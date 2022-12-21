# Born2beRoot
> This project aims to introduce you to the wonderful world of virtualization

## Before start
### 1. Virtual Machine
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

### 2. LVM(Logical Volume Manage)
- encrypted partitions
- journaling file system (ext4)
- `lsblk` : 리눅스 스토리지 디바이스 출력

### 3. GRUB bootroader

### 4. sudo
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
- 터미널이 연결되기 전에 sudo명령어를 막아주면, sudo daemon또는 cronjobs또는웹서버 플러그인과 같은 다른 분리된 프로세스에서 사용되는 것을 방지할 수 있다
```
- 콘솔(console) : 서버의 로컬 장치에서 직접 명령어를 작성하는 입출력 장치
- 쉘(shell) : 커널과 사용자를 연결하는 인터페이스, 명령어를 해석해 전달해줌
	- 커널(kernal : 알맹이) 의 반댓말로 조개 껍데기를 의미
	- 명령줄 인터프리터(해석기) 이다
		> 사용자는 터미널이라는 인터페이스로 쉘이라는 프로그램을 이용해 명령을 입력하고 명령이 처리되며 결과가 출력되는 것을 볼 수 있음
		>> 일반적으로 터미널에서 쉘을 실행할 뿐, 쉘은 터미널 없이 백그라운드 프로세스에서도 실행할 수 있음
- 터미널(terminal) : 콘솔의 한 종류, 컴퓨터와 사용자 간에 서로 상호작용 할 수 있는 CLI 인터페이스
- pty(Pseudo-terminal) : 가상 tty, 가상 터미널 환경
- pts(Pseudo-terminal slave) : 원격 터미널 환경
```

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

### 5. 그룹설정
1. `groupadd user42` 를 통해서 user42그룹추가
2. `usermod -aG sudo,user42 <사용자이름>` 명령어로 해당 그룹에 유저 추가
> G옵션 : 그룹 설정 시, gid그룹을 제외하고 명령어에 나열된 그룹만 추가가 되며, 명령어에 나열되어 있지 않지만 유저가 속한 그룹은 모두 탈퇴된다  
> a옵션 : G옵션과 함께 쓰이며, 명령어에 나열되지 않지만 유저가 속한 그룹에 대해서 탈퇴처리 하지 않는다
3. `usermod -g user42 <사용자이름>` : 명령어를 통해 user42그룹이 primary group이 되도록 한다
4. `sudo deluser <사용자명> <그룹명>` : 그룹에서 사용자 제거가능
5. `sudo userdel -r <사용자명>` : 사용자 제거 가능

### 6. Apparmor
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

### 7. UFW(Uncomplicated firewall)
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

### 8. SSH
- Secure Shell Protocol
- 네트워크 프로토콜 중 하나로 컴퓨터와 컴퓨터가 인터넷과 같은 Public Network를 통해 서로 통신할 때 보안적으로 안전하게 통신하기 위해 사용하는 프로토콜
- 기존에 유닉스 시스템 쉘에 원격 접속하기 위해 사용하던 텔넷은 암호화가 이루어지지 않아 계정 정보가 탈취될 위험이 높으므로 여기에 암호화 기능을 추가하여 1995년에 나온 프로토콜
- 대표적인 사용의 예
	- 데이터 전송(git push)
	- 원격제어(aws와 같은 클라우드 서비스)
- 장점
	- 보안 통신, 포트 포워딩 등의 기능을 제공하여 암호화되지 않은 telnet, rlogin, SMTP등에 대한 패킷 스니핑 등의 보안 공격 방지
- 사용이유
	- 보안 때문에 FTP나 Telnet과 같은 다른 컴퓨터 통신을 사용하지 않는다
	- SSH는 보안적으로 훨씬 안전한 채널을 구성한 뒤 정보를 교환하기 때문에 보다 보안적인 면에서 뛰어나다

####  작동원리
- SSH프로토콜은 클라이언트-서버 모델로 동작하며 대칭키 방식, 비대칭키 방식, 해시 알고리즘을 사용하여 인증 및 암호화를 수행한다
	- 대칭키 방식 : 클라이언트-서버 간 전체 연결을 암호화에 사용
	- 비대칭키 방식 : 키교환, 클라이언트 인증, 서버 인증에 사용
	- 해시 알고리즘 : 패킷의 무결성을 확인하기 위해 사용
1. 클라이언트는 서버에 원격 접속을 위해 연결을 위한 프로세스 시작
	- 서버의 TCP 22번 포트로 SSH접속 요청
	- 서버는 서버가 지원하는 프로토콜 버전을 응답으로 보내줌
	- 클라이언트는 서버가 지원하는 프로토콜 버전 중 자신과 일치하는 것이 있다면 연결을 지속(버전교환)
1. 서버는 자신의 공개키를 클라이언트에게 전송
	> 클라이언트는 서버들의 공개키를 사용자 홈 디렉터리의 .ssh/known_hosts에 저장하고 있음
1. 올바른 서버인지 확인(클라이언트 관점)
	1. 클라이언트에서 난수 생성, 해시값 생성 및 저장
	1. 서버의 공개키로 암호화 후 서버에 전송
	1. 서버의 개인키로 데이터를 복호화하여 난수 추출
	1. 서버에서 복호화된 난수 해시값을 클라이언트에게 전송
	1. 기존 해시값과 서버에게 반은 해시값 비교 &rarr; 동일할 시 올바른 서버
1. 암호화된 통신을 위한 세션키 생성(대칭키 생성)
	- 세션키(대칭키)는 모든 통신을 암호화 하는데 사용
	- 대칭키는 유출되었을 때 취약하므로 키 교환 알고리즘을 통해 안전하게 대칭키를 공유
	- 디피-헬만 알고리즘(Diffie-Hellman : DH)
		1. 클라이언트와 서버는 임시 비대칭키 방식의 키 쌍을 생성하고 키 교환
		1. DH를 통해 서버와 클라이언트는 세션키를 공유하게 되고, 이후 모든 통신에 세션키 사용
		> 대칭키 교환에 사용된 키 쌍은 서버, 클라이언트 인증에 사용되는 SSH키 쌍과 다름
1. 서버에 접근할 수 있는 클라이언트인지 확인(서버 관점)
	- 패스워드 인증
		- 복잡성 설정의 한계가 있기 때문에 일반적으로 사용하지 않는것이 좋음
	- SSH 키 쌍을 이용한 인증
		- 클라이언트도 키 쌍을 생성 후 서버 인증했던 방식과 동일하게 진행
1. 클라이언트가 서버에 원격 접속
	> 세션키를 통해 클라이언트와 서버 간 통신을 수행함


#### 통신방식
- Public Key and Private Key
	- SSH는 다른 컴퓨터와 통신할 때 일반적으로 사용하는 비밀번호 입력을 통한 접속을 하지 않는다
	- 기본적으로 SSH는 한 쌍의 key를 통해 접속하려는 컴퓨터와 인증 과정을 거친다
		- Public Key
			- 공개되어도 비교적 안전한 key
			- 메세지 전송 전 암호화에 사용
			- 암호화만 가능하며, 복호화는 불가능
		- Private Key
			- 절대로 외부에 노출되면 안되는 key
			- 암호화된 메세지를 복호화에 사용
- 대칭키 방식 vs 비대칭키 방식(공개키)
	- 대칭키 암호화 방식
		- 암복호화에 사용하는 키가 동일
		- 장점 : 속도가 빠름
		- 단점 : 키를 교환해야한다는 문제(키 배송 문제)
			- 키 교환 중 키가 탈취될 수 있음
			- 사람이 증가할수록 관리해야 할 키가 방대해짐
	- 비대칭키(공개키) 암화화 방식
		- 암복호화에 사용하는 키가 다름
			- 공개키는 모든 사람이 접근 가능
			- 개인키는 각 사용자만이 가지고 있음
		- 장점 : 키분배 필요없음, 기밀성/인증/부인방지 기능을 제공
		- 단점 : 대칭키 대비 속도가 느림
#### 암호화 알고리즘
- RSA
	- 공개키 암호 시스템중 하나로 암호화 뿐만 아니라 전자서명이 가능한 최초의 알고리즘
	- 일반적으로 알려진 공개키 방식과의 차이점
		- 암호화 제약조건이 없음
		- 즉. 공개키로 암호화하여 공개키로 복호화 할 수도 있음
- DSA
	- 디지털 서명 알고리즘(Digital Signature Algorithm)은 디지털 서명을 위한 연방 정보 처리 표준
	- 1991년 8월 미국 국립표준기술연구소(NIST)가 제안했으며 1993년 FIPS186로 채택
- Ed25519(EdDSA)
	- SHA-512 및 Curve25519를 사용한 EdDSA 공개키 서명체계
		> EdDSA : 트위스트 에드워드 곡선을 기반으로하는 Schnorr서명의 변형을 사용하는 디지털 서명 체계
		>> 보안을 유지하면서 기존 디지털 서명 체계보다 더 빠르도록 설계되었음
	- 빠른 단일 서명 확인 (Fast single-signature verification)
	- 매우 빠른 배치 검증 (Even faster batch verification)
	- 빠른 키 생성(Fast key generation)
	- 높은 보안 수준(High security level)
	- 완전 방지 세션 키(Foolproof session keys)
	- 충돌 탄력성(Collision resilience)
	- 비밀 배열 인덱스가 없음(No secret array indices)
	- 비밀 지점 조건이 없음(No secret branch conditions)
	- 작은 서명(Small signatures)
	- 작은 키(Small keys)

|Protocol|Key length|Create AttrCert|Verify AttrCert|
|---|---|---|---|
|RSA|1024bit|40.26ms|0.10ms|
|RSA|2018bit|253.61m|0.40ms|
|RSA|4096bit|1635.65ms|1.43ms|
|DSA|512bit|19ms|0.1ms|
|DSA|1024bit|82ms|0.310ms|
|ED25519|256bit|0.197ms|0.226ms|

#### SSH설정
- `apt search openssh-server` : 설치유무 확인
- `apt install openssh-server` : openssh 설치
- `systemctl status ssh` : openssh실행여부, 사용포트 확인
- `sudo vim /etc/ssh/sshd_config` : ssh 설정변경
	> 프로젝트 요구사항은 Port22번 대신에 Port4242사용  
	> PermitRootLogin prohibit-password &rarr; PermitRootLogin no : 외부에서 root로 로그인 하는 것 차단
	>> ssh_config : 클라이언트 일때 설정  
	>> sshd_config : 서버측일때 설정
- `sudo systemctl restart ssh` : 재시작 및 설정 적용

#### systemd(system daemon)과 daemon 프로세스
- foreground 프로세스
	- 표준입출력장치(터미널과 키보드, tty or pts)를 통해 대화 가능한 프로세스
- background 프로세스
	- 터미널과의 관계를 모드 끊은 프로세스
	- 사용자에게 무언가를 키보드를 통해 전달받지 않고 스스로 동작하는 프로세스
	- sshd의 경우, 터미널에 $를 띄워주고 명령을 기다리므로 foreground  프로세스로 보이기도함
		> sshd는 백그라운드로 동작하며, 다른 프로세스를 통해서 해당 동작을 수행하는 것임  
		> 프로세스의 PID PPID의 관계를 통해서 sshd가 어떤 프로세스를 동작시켜 정보를 보여주는지 확인가능
		>> 프로세스 간의 관계는 `ps -ef`로 확인 가능
- daemon 프로세스
	- 데몬(daemon)이란 서비스의 요청에 응답하기 위해 오랫동안 실행중인 백그라운드 프로세스
		> 유닉스 운영체제에서 이름이 d로 끝나는 프로세스들이 대표적
		>> inetd, httpd, nfsd, sshd, named, lpd 등이 있음
	- 부모프로세스(PPID)가 1 or 다른 데몬 프로세스인 프로세스를 의미한다
		> 다른 프로세스의 경우, ssh로 접속하여 백그라운드로 실행시키더라도 ssh접속이 끊기면 자동으로 종료된다
	- 웹서버의 경우(대표적인 데몬 프로세스)
		- PPID가 1이기 때문에 ssh 세션이 종료되더라도, 종료되지 않고 계속 웹 서비스르 제공
- systemd
	- init 의 역할을 대체하는 데몬
		> init : 전통적으로 Unix시스템이 부팅 후 가장 먼저 생성된 후 다른 프로세스를 실행
		>> init의 PID : 1 (systemd 이 init을 대체하므로 동일하게 PID는 1을 가짐)
	- 리소스를 unit이라고 하는 단위로 관리
		- unit의 type은 다음과 같음 : .service / .device / .mount / .automount / .swap / .target / .path / .timer / .snapshot / .slice / .scope
			> .service를 주로 많이 다루게 될 것임
- systemctl
	- systemd를 관리하기 위한 도구
	- 시스템 유닛 조작 명령어
		- `systemctl status` : 실행중인 유닛 상태 정보 출력
		- `systemctl` or `systemctl list-units` : 로딩된 유닛을 출력
		- `systemctl list-unit-files` : 설치된 유닛 목록 출력
		- `systemctl start 유닛명` : 유닛 활성화
		- `systemctl stop 유닛명` : 유닛 비활성화
		- `systemctl status 유닛명` : 유닛 상태확인
		- `systemctl restart 유닛명` : 유닛 종료 후 재활성화
		- `systemctl enable 유닛명` : 유닛 등록
			> 등록하면 재부팅시에 유닛이 실행되도록 함
			>> `systemctl enable --now 유닛명` : 유닛 등록 및 활성화
		- `systemctl disable 유닛명` : 유닛 등록 해제
		- `systemctl reload 유닛명` : 유닛 갱신
		- `systemctl mask 유닛명` : 유닛 마스킹
		- `systemctl unmask 유닛명` : 유닛 마스킹 해제

#### 로컬-가상환경 간 ssh연결
- Virtual Box &rarr; tools &rarr; networt &rarr; create : 새로운 네트워크 생성(vboxnet0)
- vm setting &rarr; nerwork &rarr; advanced &rarr; port fowarding &rarr; rule 추가
	> host ip : 위에 생성한 네트워크의 ip / guest ip : 가상환경의 ip / port : 4242
	>> guest ip 확인을 위해서는 `hostname -I`로 확인가능
- adapter2 &rarr; attached to : host-only adapter &rarr; name : vboxnet0
- 이후 vm시작하면 `ifconfig`시에 vboxnet0의 해당 ip가 동작하는것을 확인가능
- `ssh <사용자 id>@<서버 주소> -p <포트번호>` 로 접속

#### 네트워크 장비 & 연결방식
https://unabated.tistory.com/entry/VMware-의-네트워크-구성과-연결의-이해

### 9. 패스워드 정책 설정
- `vi /etc/login.defs` 에서 `PASS_MAX_DAYS 30`, `PASS_MIN_DAYS 2`, `PASS_WARN_AGE 7`, `PASS_MIN_LEN 10`으로 변경
	> /etc/login.defs : 사용자 계정의 설정 및 기본 값을 정의 한 파일
	>> PASS_MIN_LEN의 경우, 이제는 PAM에서 설정을 관리함
- `sudo apt install libpam-pwquality` 로 패키지 설치
	> PAM(pluggable authentication modules) 응용 프로그램(서비스)에 대한 사용자의 사용 권한을 제어하는 모듈  
	> 1. 인증이 필요한 응용프로그램은 더 이상 passwd 파일을 열람하지 않고 PAM모듈에 사용자 인증을 요청  
	> 2. PAM은 인증을 요청한 사용자의 정보를 가지고 결과를 도출하여 응용프로그램에 전달
	>> PAM을 사용하기 이전에는 시스템에 저장된 사용자 정보를 통해 인증할 경우, 응용프로그램이 사용자 정보가 담긴 주요 시스템 파일(/etc/passwd)에 대한 접근 권한을 가지고 있어야 하므로 침해사고의 위험
- `sudo vim etc/pam.d/common-password` 입력 후 다음과 같이 수정
	- `retry=3 minlen=10 difok=7 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username enforce_for_root`
		> retry=3 : 암호입력 3회제한  
		> minlen=10 : 암호 최소 길이 10  
		> difok=7 : 기존 패스워드와 달라야 하는 문자 수는 7  
		> ucredit=-1 : 대문자 한 개 이상  
		> lcredit=-1 : 소문자 한 개 이상  
		> dcredit=-1 : 숫자 한 개 이상  
		> maxrepeat=3 : 같은 문자가 3개 연속해서 나오는 검사
		> reject_username : username이 그대로 또는 역순으로 패스워드에 들어있는지 검사  
		> enforce_for_root : root 사용자가 패스워드를 바꾸려는 경우에도 동일하게 적용  
		>> credit의 경우 음수인지 양수인지에 따라 뜻이 달라짐
	- `passwd -e 사용자명` : 현존하는 사용자 계정의 암호변경을 강제

### 10. cron 과 monitoring.sh
#### monitoring.sh
- `sudo apt install sysstat`
- `vim /root/monitoring.sh`
```sh
printf "#Architecture: "
uname -a

printf "#CPU physical : "
nproc --all

printf "#vCPU : "
cat /proc/cpuinfo | grep processor | wc -l

printf "#Memory Usage: "
free -m | grep Mem | awk '{printf"%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage: "
df -a -BM | grep /dev/map | awk '{sum+=$3}END{print sum}' | tr -d '\n'
printf "/"
df -a -BM | grep /dev/map | awk '{sum+=$4}END{print sum}' | tr -d '\n'
printf "MB ("
df -a -BM | grep /dev/map | awk '{sum1+=$3 ; sum2+=$4 }END{printf "%d", sum1 / sum2 * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load: "
mpstat | grep all | awk '{printf "%.2f%%\n", 100-$13}'

printf "#Last boot: "
who -b | awk '{printf $3" "$4"\n"}'

printf "#LVM use: "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ] ; then printf "yes\n" ; else printf "no\n" ; fi

printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"

printf "#User log: "
who | wc -l

printf "#Network: IP "
hostname -I | tr -d '\n'
printf "("
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"

printf "#Sudo : "
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n
```
- uname : 시스템 정보 출력 명령어
	> a : 커널 이름, 네트워크 호스트명, 커널 릴리즈 정보, 커널 버전, 시스템의 하드웨어 타입, 운영체제 이름
- nproc : 현재 프로세스에서 사용할 수 있는 처리 장치 수
	> --all : 설치된 모든 코어 / 프로세스 수 출력
- /proc/cpuinfo : CPU정보가 담겨있는 파일
	> wc -l : 줄 수 출력
- free : 시스템 메모리 사용 현황 출력 명령어
	> m : 메가바이트 단위로 표시
- df : 파일시스템 디스크 공간의 사용량을 출력하는 명령어
	> a : 0블록의 파일시스템을 포함해 모든 파일시스템을 출력하는 옵션  
	> B : 지정한 크기(size)를 블록단위로 정하여 용량을 표기하는 옵션  
	> BM : 크기를 1M로 블록단위로 정해 용량을 표시
	>> tr -d '\n' : 개행 삭제
- mpstat : 사용 가능한 CPU와 core별 사용량을 출력(sysstat 설치 필요)
- who : 호스트에 로그인한 사용자 정보 출력
	> b : 마지막 시스템 부팅 시간을 출력하는 옵션
- ss : 소켓 상태를 조회할 수 있는 유틸리티
- hostname : 시스템 이름을 확인하고 설정하는 명령어
	> I : 호스트의 IP주소를 출력하는 옵션
- ip : 인터페이스를 위, 아래로 가져오고 주소와 경로를 할당 및 제거하고, ARP캐시를 관리하는 등 다양한 용도로 사용
	> link : 네트워크 인터페이스를 표시하고 수정
	>> show : 관련 인터페이스를 출력
- journalctl : systemd 의 서비스 로그를 확인할 수 있음, systemd-journald.service 에 의해서 systemd정보를 분석
	> _COMM=sudo : 특정 로그 보기
#### cron
- 관리자들이 고정된 간격을 갖는 지정 날짜 및 시간마다 주기적으로 정기적인 작업을 처리하기 위해 소프트웨어를 실행토록 환경을 설정하는 시간기반 job스케줄러 성격의 데모 프로세스
- 사용자는 crontab명령으로써 cron이 crontab파일에 접근하여 쉘 명령어들이 주어진 일정에 주기적인 실행하도록 작업 목록을 정의하는 방법만 이해하면 된다
- 기본 명령어
	- `sudo crontab -e` : 설정 및 수정
	- `sudo crontab -l` : 목록 보기
	- `sudo crontab -r` : 삭제
	- `sudo service cron stop` : 중지
	- `sudo service cron restart` : 재시작
- crontab
	- 분 시 일 월 요일 [실행할 작업]
		- 해당 사항이 있는 자리에만 숫자를 적고 나머지는 \*로 표기
		- 요일의 경우 일요일이 0이고 토요일이 6이다.
		- 아무것도 입력하지 않고 \* \* \* \* \* 으로 두면 매 분마다 실행
		- \* : 모든 값을 뜻합니다.
		- ? : 특정한 값이 없음을 뜻합니다.
		- - : 범위를 뜻합니다. (예) 월요일에서 수요일까지는 MON-WED로 표현
		- , : 특별한 값일 때만 동작 (예) 월,수,금 MON,WED,FRI
		- / : 시작시간 / 단위  (예) 0분부터 매 5분 0/5
		- L : 일에서 사용하면 마지막 일, 요일에서는 마지막 요일(토요일)
		- W : 가장 가까운 평일 (예) 15W는 15일에서 가장 가까운 평일 (월 ~ 금)을 찾음
		- \# : 몇째주의 무슨 요일을 표현 (예) 3#2 : 2번째주 수요일

## Reference

