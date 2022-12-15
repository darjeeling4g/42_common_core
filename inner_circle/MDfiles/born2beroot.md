# Born2beRoot
> This project aims to introduce you to the wonderful world of virtualization

## Before start
### Virtual Machine
- VM(virtual machine) 이란?

- Debian vs Rocky

- VM의 포멧
	- VDI(virtual disk image) : Oracle의 버추얼박스에서만 사용가능한 포멧
	- VHD(virtual hard disk) : Oracle의 버추얼박스, MS의Hyper-V, Citrix의 Xen에서 구동 가능한 포멧
	- VMDK(virtual machine disk) : Oracle의 버추얼박스, VMware의 VMware Player에서 구동 가능한 포멧

- VM의 디스크 할당 방식
	- Dynamically allocated : 디스크 생성속도가 빠름, 더 큰 크기로 확장 가능
	- Fixed size : 사용이 빠름, 더 큰 크기로 확장 불가

- Debian vs Rocky

### LVM(Logical Volume Manage)
- encrypted partitions
- journaling file system (ext4)
- `lsblk` : 리눅스 스토리지 디바이스 출력

### GRUB bootroader

### sudo
- superuser do 현재 계정에서 root권한만을 빌리는 것(하나의 명령에 대해서 일시적으로 root권한을 사용하는 것)
- 필요성 : Unix또는 Linux시스템에서 root는 무한대의 권한을 가지고 있음, 침입자들에게는 root권한을 얻어내는 것이 최우선의 목표 / su의 경우 원격으로 로그인한 계정에서도 root가 될 수 있음
- 장점
	- root passwd 효율적으로 관리 가능 : root패스워드를 공유하면 정기적인 변경이 어렵고 외부로 노출될 확률이 올라감
	- root 권한을 사용하는 시간 최소화하여 위험요소로부터 안전한 작업 또는 운영가능
	- log추척이 간편 : su root의 경우 작업을 일일이 추적이 불가능하며, 시스템 일부가 손상되어도 눈치 채지 못할 수 있음
- `env_reset` : HOME, LOGNAME, PATH, SHELL, TERM, USER을 제외한 모든 환경변수를 reset
- `mail_badpass` : 잘못된 패스워드로 sudo실행 시 지정된 메일로 보고
- `secure_path` : sudo 명령은 현재 계정의 쉘이 아닌 가상의 쉘을 생성하고 그 안에서 실행된다. 이때 가상의 쉘의 환경변수 PATH 값을 secure\_path옵션을 통해 지정한다
	> sudo권한이 있는 사용자의 PATH환경변수에 악성 코드로 인한 경로가 포함되어 있어 특정 명령 실행 시 경로에서 악성 파일이 실행될 경우 취약할 수 있음
	>> 트로이목마 해킹 공격에 대한 일차적인 방어 기능 제공(사용자의 부주의로 현재 계정의 path에 악의적인 경로가 포함된 경우, 이를 무시함으로써 sudo를 통한 전체 시스템 접근 방지

#### su
- swich user 현재 계정을 로그아웃하지 않고 다른 계정으로 전환하는 명령어 (`su <계정명>` 의 형태)
- 사용 시 일반계정쉘 `$`에서 관리자계정쉘 `#`으로 변경되는 것을 확인가능
- `su` : `su root`와 동일한 의미를 가짐
	- PATH와 환경변수가 유지
	- 워킹디렉토리를 변경하지 않음
- `su -` : `su -l` or `su --login root`와 동일한 의미를 가짐
	- PATH가 default가 되며, 기존 사용자 환경에서 사용하던 환경변수를 모두 지워버림
	- 사용자 계정의 홈 디렉터리로 이동함

#### TTY
- Teletypewiter 리눅스의 콘솔 및 터미널을 의미
- TTY모드를 활성화하면 터미널을 할당하지 않은 상태에서 sudo 명령어를 실행할 수 없다
- 터미널이 연결되기 전에 sudo명령어를 막아주면, sudo daemon또는 cronjobs또는

#### sudo 설치
1. `dpkg -l sudo` : sudo가 설치되어있는지 확인
2. `su` or `su -`로 root권한으로 전환
3. `apt install sudo`
> apt apt-get의 차이점?

4. visudo로 sudoers 에 접근
> sudoers : 관리자가 일반계정에 sudo권한을 부여하기위해 수정이 필요함
>> sudoers파일의 경우 일반 편집기로 접근 시 많은 제약이 있으며, 편집간에 실수가 발생하면 sudo를 사용할 수 없다. visudo는 문접체크를 해준다

5. 서브젝트 요구사항 대로 secure\_path 수정

6. 아래 옵션 추가
```sudoers
Defaults	authfail_message="원하는 에러메세지" #권한 획득 실패 시 출력 (sudo 인증 실패 시)
Defaults	badpass_message="원하는 에러메세지" #sudo인증에서 비밀번호 틀리면 출력
Defaults	log_input #sudo명령어 실행 시 입력된 명령어 log로 저장
Defaults	log_output #sudo명령어 실행 시 출력 결과를 log로 저장
Defaults	requiretty #sudo명령어 실행 시 tty강제
Defaults	iolog_dir="/var/log/sudo/" #sudo log 저장 디렉토리 설정
Defaults	passwd_tries=3 #sudo실행 횟수를 지정. default가 3
```

7. sudo log 저장위치를 위와 같이 설정했으므로 해당 위치에 폴더 생성

### 그룹설정
1. `groupadd user42` 를 통해서 user42그룹추가
2. `usermod -aG sudo,user42 <사용자이름>` 명령어로 해당 그룹에 유저 추가
> G옵션 : 그룹 설정 시, gid그룹을 제외하고 명령어에 나열된 그룹만 추가가 되며, 명령어에 나열되어 있지 않지만 유저가 속한 그룹은 모두 탈퇴된다  
> a옵션 : G옵션과 함께 쓰이며, 명령어에 나열되지 않지만 유저가 속한 그룹에 대해서 탈퇴처리 하지 않는다
3. `usermod -g user42 <사용자이름>` : 명령어를 통해 user42그룹이 primary group이 되도록 한다
4. `sudo deluser <사용자명> <그룹명>` : 그룹에서 사용자 제거가능
5. `sudo userdel -r <사용자명>` : 사용자 제거 가능

### Apparmor
- 시스템 관리자가 응용프로그램 역량 및 권한을 제한할 수 있도록 하는 커널 보안 모듈
- 프로그램의 프로필을 통해 아래와 같은 작업을 제한 및 관리함
	- 네트워크 엑세스
	- raw 소켓 엑세스
	- 파일 읽기, 쓰기, 실행 권한
	- 기타 해당 프로그램이 취할 수 있는 작업
- 강제적 접근통제(MAC)를 제공함으로써 전통적인 유니스 임의적 접근 통제 모델(DAC)을 지원
- SELinux는 IBM/RedHat계열에서 선호되고 같은 계열의 CentOS와 같은 운영체제에서 사용된다. 나머지는 AppArmor사용
- SELinux는 policy file과 right file system을 통해 작동. AppArmor는 policy file만으로 작동. SELinux가 조금 더 복잡하고 표준화하여 설정하기 어려운 단점

#### 접근 통제(Access control)
- 운영체제에서 접근통제는 디렉터리난 파일, 네트워크 소켓 같은 시스템자원을 적절한 권한을 가진 사용자나 그룹이 접근하고 사용할 수 있게 통제하는 것을 의미
- 접근 통제에서는 시스템 자원을 객체(Object)라고 하며 자원에 접근하는 사용자나 프로세스는 주체(Subject)라고 정의한다
> 즉, /etc/passwd 파일을 객체, 파일에 접근해서 암호를 변경하는 passwd라는 명령어는 주체
>> 아파치 웹서버의 설정 파일 /etc/httpd/conf/httpd.conf 는 객체, 웹서버 프로그램 /sbin/httpd 는 주체

#### 임의 접근 통제(DAC : Discretionary Access Control)
- 임의 접근 통제는 시스템 객체에 대한 접근을 사용자나 또는 그룹의 신분을 기준으로 제한하는 방법
- 사용자나 그룹이 객체의 소유자라면 다른 주체에 대해 이 객체에 대한 접근 권한을 설정할 수 있다
	- 여기서 임의적이라는 말은 소유자는 자신의 판단에 의해서 권한을 줄 수 있다는 의미이며, 구현이 용이하고 사용이 간편하기 때문에 전통적으로 유닉스나 윈도우등 대부분의 운영체제의 기본 접근 통제 모델로 사용되고 있다
- 임의적 접근 통제는 사용자가 권한을 탈취당하면 사용자가 소유하고 있는 모든 객체의 접근 권한을 가질 수 있게 되는 치명적인 문제가 있음
- 대표적인 보안 취약점 2가지
	- setuid / setgid 문제 : 유닉스 계열 운영 체제는 실행 파일의 속성에 setuid or setgid 비트라는 것을 설정할 수 있으며, 이 비트가 설정되어 있을 경우 해당 프로그램을 실행하면 실행 시점에 설정된 사용자(setuid) 또는 그룹(setgid) 권한으로 동작함 &rarr; passwd 나 ping의 경우 소유가 root이며 setgid 비트가 설정되어 있음 &rarr; 해당 명령어 실행시 루트 사용자로 전환되므로 공격자가 손쉽게 루트 권한을 획득할 수 있음
	- 잘 알려진 포트 daemon 문제 : 잘 알려진 포트(well-known port) 는 루트만이 사용할 수 있어, 데몬 서비스는 모두 루트의 권한으로 기됨 됨 &rarr; 만약 서비스 데몬이 보안 취약점이 있거나 잘못 설정되면 루트 권한이 빼앗길 수 있으므로 웹서버등은 구동 후에 자식 프로세스 생성(fork 시스템 콜) 한 후 쉘이 없는 사용자 계정으로 전환하여 동작

#### 강제 접근 통제(MAC : Mandatory Access Control)
- 강제 접근 통제는 미리 정해진 보안 등급에 의거하여 주체에게 허용된 접근 권한과 객체에게 부여된 허용 등급을 비교하여 접근을 통제하는 모델
- 높은 보안을 요구하는 정보는 낮은 보안 수준의 주체가 접근할 수 없으며, 소유자라고 할 지라도 정책에 어긋나면 객체에 접근할 수 없으므로 강력한 보안을 제공
- 단점 : 구현이 복잡하고 어려우며 모든 주체와 객체에 대해서 보안 등급과 허용등급을 부여하여야 하므로 설정이 복잡하고 시스템 관리자가 접근 통제 모델에 대해 잘 이해하고 있어야 

#### AppArmor 설정
- 프로필은 /etc/apparomr.d 디렉토리에 저장
	- 프로필은 complain mode 와 enforce mode로 실행가능
		- complain mode : 응용프로그램을 제한하지 않고, 위반 사항을 보고하는 로그 항목만을 작성함
		- enforce mdoe : 응용프로그램이 제한된 동작을 수행하지 못하게 함
- `sudo dpkg -l apparmor` : apparmor 설치 확인
- `sudo apt install apparmor` : apparmor 설치
- `sudo apt install apparmor-utils` : apparmor utils 설치
- `aa-enabled` : 활성화 여부 확인

### UFW(Uncomplicated firewall)
- 데비안 계열 및 다양한 리눅스 환경에서 사용하기 쉬운 방화벽 관리 프로그램
	- 커널은 server에 대한 cliend의 네트워크 접속을 제어하는 넷필터라는 모듈을 가지고 있음 &rarr; 이를 활용하여 서버 접속에 대한 네트워크 정책을 세우는 프로그램이 firewall
	- 간단한 명령 및 명령수가 적은 명령줄 인터페이스를 사용하는 것이 특징이며, 프로그램 구성에는 iptables사용
		> iptable : 시스템 관리자가 리눅스 커널 방화벽이 제공하는 테이블과 그것들을 저장하는 체인, 규칙들을 구성할 수 있게 해주는 사용자 공간 응용프로그램(설정과 관리가 복잡함)

#### 방화벽
-  데이터 패킷을 분석하고 적용된 규칙에 따라 허용여부를 결정해 들어가고 나가는 네트워크 트래픽을 제어하는 네트워크 보안 시스템
	- 보안이 필요한 네트워크의 통로를 단일화하여 관리함으로써 외부의 불법침임으로부터 내부의 정보자산을 보호
	- 사용자 인증, 주소변환, 감사기록 등이 장점
	- 강력한 접근제어를 제공하기 위해 외부망과 내부망의 구성을 위한 별개의 네트워크를 가짐
	- 바이러스와 같은 맬웨어 형태로 존재하는 위협은 방어할 수 없다

#### UFW설정
- `sudo apt install ufw` : ufw 설치
- `sudo ufw status verbose` : ufw 상태 확인(default는 inactive)
- `sudo ufw enable` : 부팅 시 ufw 활성화되게 설정
	> `sudo ufw disable ` : 비활성화
- `sudo ufw default deny` : 기본incoming deny로 설정
	> `sudo ufw show raw` : 기본 룰 확인
	>> `sudo ufw default allow` : 기본을 허용으로도 설정 가능
- `sudo ufw allow 4242` : ssh 연결 허용(4242라는 커스텀 포트 사용하는 경우)
- `sudo ufw status numbered` : 정책 확인
- `sudo ufw delete 정책 번호` : 해당 정책 삭제

#### 포트 포워딩
- 포트 : 컴퓨터의 LAN선은 하나인데, 통신을 필요로 하는 프로그램이 다수일 때 이 프로그램을 구별하는 번호
	- 0번 ~ 1023번 : 잘 알려진 포트(well-known port)
		- 20 : FTP(data)
		- 21 : FTP(제어)
		- 22 : SSH
		- 23 : 텔넷
		- 53 : DNS
		- 80 : HTTP
		- 119 : NNTP
		- 443 : TLS/SSL방식의 HTTP
	- 1024번 ~ 49151번 : 등록된 포트(registered port)
	- 49152번 ~ 65535번 : 동적 포트(dynamic port)
- 포트포워딩
	- 네트워크 상에서 패킷이 방화벽이나 라우터 같은 네트워크 게이트를 지날 때 ip주소와 포트 번호 결합의 통신 요청을 다른 곳으로 넘겨주는 네트워크 주소 변환의 응용
	- 라우터에서 새로운 기능을 이용할 수 있는 강력한 툴이 될 수 있으면서 심각한 온라인 취약성에 노출시킬 수 있음

### SSH

## Reference

