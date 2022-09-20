# Get\_next\_line
> Reading a line from a fd is way too tedious
>> This project is about programming a function that returns a line read from a file descriptor.

## Before start
### System level I/O
##### 저수준 파일 입출력 특징
- 시스템 호출(Systemp call)을 이용하므로 파일에 빠르게 접근
- 바이트 단위로만 입출력을 수행

-|저수준 파일 입출력|고수준 파일 입출력
---|---|---
파일 지시자|`ind fd`|`FILE *fp;`
특징|- 훨씬 빠르다<br> - 바이트 단위로 읽고 쓴다<br> - 특수 파일에 대한 접근이 가능하다|- 사용하기 쉽다 <br> - 버퍼 단위로 읽고 쓴다 <br> - 데이터의 입출력 동기화가 쉽다 <br> - 여러 가지 형식을 지원한다
주요 함수|open, close, write, dup, dup2, fcntl, lseek, fsync|fopen, fclose, fread, fwrite, fputs, fgets, fprintf, fscanf, freopen, fseek
##### 파일 기술자(file descriptor)
> 현재 열려있는 파일을 구분할 목적으로 유닉스 계열 시스템에서 부여하는 번호
- file descriptor는 정수값으로 open함수를 이용해 파일을 열었을때 부여
- 0~2 까지는 각각 표준입력(Standard Input), 표준출력(Standard Output), 표준에러(Standard Error)가 기본적으로 할당되며, 이후 번호부터 순차적으로 부여된다
##### 파일 열기 : open
`int open(const char *path, int oflag [, mode_t mode]);`
- open 함수는 path에 지정한 파일을 oflag에 지정한 상태 플래그 값에 따라 열고 파일 기술자를 반환한다

oflag의 종류|기능
---|---
O\_RDONLY|파일을 읽기 전용으로 연다
O\_WRONLY|파일을 쓰기 전용으로 연다
O\_RDWR|파일을 읽기/쓰기 용으로 연다
O\_CREAT|파일이 없으면 생성한다, 파일을 생성할 권한은 당연히 있어야 한다, 파일이 이미 있다면 아무 의미없는 옵션
O\_EXCL|O\_CREAT옵션과 함께 사용할 경우 기존에 없는 파일이면 파일을 생성하지만, 이미 있다면 파일을 생성하지 않고 오류 메시지를 출력한다
O\_APPEND|이 옵션을 지정하면 파일의 맨 끝에 내용을 추가한다
O\_TRUNC|파일을 생성할 때 이미 있는 파일이고, 쓰기 옵션으로 열었다면 내용을 모두 지우고 파일의 길이를 0으로 변경한다
O\_NONBLOCK/O\_NDELAY|비블로킹(non-blocking) 입출력 옵션으로 파일을 읽거나 쓰고 난 후의 동작에 영향을 준다, 디스크의 파일 입출력보다는 FIFO 같은 특수 파일의 입출력에 의미가 있다. 디스크인 경우 읽거나 쓸 데이터가 없으면 -1을 리턴한다.
O\_SYNC/ODSYNC|파일에 쓰기 동작을 할 때 보통 버퍼에만 쓰고 나중에 디스크와 같은 저장 장치로 옮겨 쓰는데, 이 옵션이 설정되어 있으면 저장 장치에 쓰기를 마쳐야 쓰기 동작을 완료한다. O\_SYNC 플래그는 파일의 수정 시각 속성도 수정할 때까지 기다린다. 이 옵션을 설정하면 프로그램의 실행 속도는 느려질 수 있지만 디스크에 확실하게 저장됨을 보장한다.
- 각 플레그들은 OR(|)연산자로 연결해 지정할 수 있다
	- ex) 쓰기 전용으로 열 때, 이미 파일이 있는 경우 (O\_WRONLY | O\_TRUNC)  
쓰기 전용으로 열 때, 파일이 없는 경우 (O\_WRONLY | O\_CREAT | O\_TRUNC)  
읽기/쓰기/추가용으로 열 때 (O\_RDWR | O\_APPEND)
- mode는 파일의 접근 권한을 설정하는 것으로, O\_CREAT 플래그를 지정해 파일을 생성할 때만 사용한다. mode는 일반적으로 파일 권한을 설정하듯이 0644와 같이 지정할 수도 있지만, 정의된 플래그를 사용할 수도 있다.

mode 플래그|모드|설명
---|---|---
S\_IRWXU|0700|소유자 읽기/쓰기/실행 권한
S\_IRUSR|0400|소유자 읽기 권한
S\_IWUSR|0200|소유자 쓰기 권한
S\_IXUSR|0100|소유자 실행 권한
S\_IRWXG|0070|그룹 읽기/쓰기/실행 권한
S\_IRGRP|0040|그룹 읽기 권한
S\_IWGRP|0020|그룹 쓰기 권한
S\_IXGRP|0010|그룹 실행 권한
S\_IRWXO|0070|기타 사용자 읽기/쓰기/실행 권한
S\_IROTH|0004|기타 사용자 읽기 권한
S\_IWOTH|0002|기타 사용자 쓰기 권한
S\_IXOTH|0001|기타 사용자 실행 권한
- 위의 표를 기준으로 0644 권한을 지정하기 위해서는 OR연산자로 묶어준다
	- ex)mode = S\_IRUSR | S\_IWUSR | S\_IRGRP | S\_IROTH;
- open함수는 파일 열기에 성공하면 파일기술자를 리턴, 실패 시 -1을 리턴한다
	- 오류코드는 외부변수 errno에 저장되며, perror함수로 확인가능
##### 파일 생성 : creat
`int creat(const char *path, mode_t mode);`
- creat함수는 open함수에 파일 생성 플래그를 부여한 것과 동일하게 동작한다
	- creat(path, mode);
	- open(path, O\_WRONLY|O\_CREAT|O\_TRUNC, mode);
##### 파일 닫기 : close
`int close(int fildes);`
- 파일 입출력 작업이 모두 완료되면 반드시 파일을 닫아야 한다
	- 프로세스가 열 수 있는 파일의 개수는 제한되어 있어, 허용 개수를 초과시 파일을 더이상 열 수 없게된다
- close 함수는 파일을 성공적으로 닫으면 0을 리턴, 실패 시 -1을 리턴한다
##### 파일 읽기 : read
`ssize_t read(int fildes, void *buf, size_t nbytes);`
- read 함수는 file descriptor가 가리키는 파일에서 nbytes로 지정한 크기만큼 바이트를 읽어 buf로 지정된 메모리 영역에 저장한다
- 성공적으로 실행시 읽어온 바이트 수를 리턴하며, 오류 시 -1을 리턴한다
	- 만일, 리턴값이 0이면 파일의 끝에 도달해 더 이상 읽을 내용이 없음을 의미한다
- read 함수를 실행할 때마다 읽어온 크기만큼 file offset을 이동해 다음 위치를 가리킨다.

##### 파일 쓰기 : write
`ssize_t write(int fildes, void *buf, size_t nbytes);`
- d


## Mandatory part

Function name|get\_next\_line
---|---
Prototype|`char *get_next_line(int fd);`
Turn in files|get\_next\_line.c, get\_next\_line.h, get\_next\_line\_utils.c
Parameters|fd: The file descriptor to read from
Return value|Read line: correct behavior<br> NULL: there is noting else to read, or an error occurred
External functs.|read, malloc, free
Description|Write a function that returns a line read from a file descriptor

## Reference
- https://12bme.tistory.com/211
- https://www.rapidtables.com/code/linux/gcc/gcc-d.html
