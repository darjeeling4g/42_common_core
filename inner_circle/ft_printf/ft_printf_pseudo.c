int ft_printf(const char *format, ...)
{
	// format을 파싱 후 리스트 생성 / 오류코드 반환
	// (if) 파싱 과정에서 오류 발생 시
		// 리스트 초기화, 리턴
	// 파싱으로 얻은 리스트를 기반으로 format을 conversion하여 출력
	// 최종 리스트 초기화, 결과 반환
}

int parser()
{
// (while) null문자 만날때까지 format 문자열 순환
	// field info 생성 및 초기화
	// (if) 현재 문자 %가 아니면
		// 시작 지점 저장
		// % 또는 null 만날 때까지 이동
		// 종료 지점까지의 길이 저장
		// feild info를 담은 feild list 생성
	// (else if) 현재 문자가 %이면
		// type field만날 때까지 각 문자 해석
			// (while) flags field가 아닐 때까지
				// (if) 현재문자가 '-'이면
					// field info에 등록
				// (if) 현재문자가 '+'이면
					// field info에 등록
				// (if) 현재문자가 ' '이면
					// field info에 등록
				// (if) 현재문자가 '0'이면
					// field info에 등록
				// (if) 현재문자가 '#'이면
					// field info에 등록
			// (while) width field가 아닐 때까지
				// (if) 현재문자가 number(except 0)이면  atoi로 획득
			// (while) .precision field가 아닐 때까지
				// (if) 현재문자가 .이면 0획득
					// (if) 다음문자가 number이면 atoi로 획득
			// (if) 현재문자가 type field가 아니라면
				// return error
			// (else if) type filed라면
				// type 획득
}

int printer()
{
//	(while) record list 순환
//		(if) type이 text
//			print_text
//		(else if) type이 char
//			print_char
//		(else if) type이 string
//			print_str
//		(else if) type이 ptr
//			print_ptr
//		(else if) type이 signed int
//			print_sint
//		(else if) type이 unsigned int
//			print_uint
//		(else if) type이 lower hex number
//			print_lhex
//		(else if) type이 upper hex number
//			print_uhew
//		(else if) type이 percent
//			print_percent
//	(return) result
}

void	ft_print_text(t_info *field_info, int *result)
{
//	(if) result != -1 일때 : 출력 중 오류가 발생하지 않았을 때만 실행
	//	(while) start부터 end까지
	//		write
	//		result++
}

void	ft_print_char(va_list pargs, t_info *field_info, int *result)
{
//	(if) + ' ' 0 # || percision(with n)
//		에러 처리
//	(if) 출력 과정 중 오류가 반환되지 않았을 때
//		width : 1보다 클때 좌측에 공백
//		percision(default) : 변화 없음
//		- : width가 1보다 클때 우측으로 공백
//		va_arg로 pargs값 출력
//		pargs 길이만큼 결과값 증가
}

void	ft_print_str(va_list pargs, t_info *field_info, int *result)
{
//	(if) flags에 '-'외에도 존재하면
//		error
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 클때 좌측에 공백
//		precision(default) : 문자열이 출력되지 않음
//		precision(with n) : 출력할 문자열의 최대 길이 제한 / 설정한 길이가 문자열보다 크다면 원래 문자열 출력
//		(if) flags가 없을 때
//			좌측 공백 출력
//		precision 크기만큼 문자열 출력
//		(if) minus가 있을 때
//			우측 공백 출력
}

void	ft_print_ptr(va_list pargs, t_info *field_info, int *result)
{
//	(if) flags가 '-'외에 또 존재하면
//		error
//	(if) 출력 중 오류가 반환되지 않았을때,
//		width : len보다 클때 좌측에 공백
//		precision(default) : 정확도 무시
//	(if) flags 가 없을 때
//		좌측 공백출력
//	포인터 변수 값(메모리 주소) 16진수 변환 후 출력
//	(if) minus일때
//		우측 공백출력
}

void	ft_print_sint(va_list pargs, t_info *field_info, int *result)
{
//	(if) flags가 hash on일 경우
//		error
//	(if) flags가 plus on이면서 blank on일 경우
//		plus on만 적용
//	(if) flags가 minus on이면서 zero on일 경우
//		minus on만 적용
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 클때 좌측 공백
//		precision(default) : 0 flags를 무시한다
//		precision(with n) : len보다 작으면 무시, len보다 크면 남는자리 0으로 대체 / width는 precision 적용한 길이를 제외하고 적용됨
//		(if) flags가 없으면 좌측 공백 (zero on일 경우 0으로 대체)
//		precision 적용된 10진수 출력(+, ' ' 옵션 적용시 부호출력)
//		precision이 0이면서 nbr이 0인경우 0을 출력하지 않음
//		(if) minus면 우측공백
}

void	ft_print_uint(va_list pargs, t_info *field_info, int *result)
{
//	(if) flags가 minus, zero외에 또 존재하는 경우
//		error
//	(if) flags가 minus on이면서 zero on일 경우
//		minus on만 적용
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 길면 좌측 공백
//		precision(default) : 0 flags를 무시한다
//		precision(with n) : len보다 작으면 무시, len보다 크면 남는자리 0으로 대체 / width는 precision 적용한 길이를 제외하고 적용됨
//		(if) flags가 없으면 좌측 공백 (zero on일 경우 0으로 대체)
//		precision 적용된 10진수 출력
//		precision이 0이면서 nbr이 0인경우 0을 출력하지 않음
//		(if) minus면 우측공백
}

void	ft_print_lhex(va_list pargs, t_info *field_info, int *result)
{
//	(if) flags가 plus, blank이면
//		error
//	(if) flags가 minus on이면서 zero on일 경우
//		minus on만 적용
//	(if) 출력 중 오류가 반환되지 않았을 때
//		width : len보다 길면 좌측 공백
//		precision(default) : 0 flags를 무시한다
//		precision(with n) : len보다 작으면 무시, len보다 크면 남는자리 0으로 대체 / width는 precision 적용한 길이를 제외하고 적용됨
//		hash : hex이므로 출력값 앞에 0x를 추가한다
//		(if) flags가 없으면 좌측 공백 (zero on일 경우 0으로 대체)
//		precision 적용된 10진수 출력
//		precision이 0이면서 nbr이 0인경우 0을 출력하지 않음
//		(if) minus면 우측공백
}

void	ft_putchar_iter(char c, int len, int *result)
{
//	(while) len까지
//		ft_putchar_fd
//		result + 1
}

int	ft_unum_to_str(unsigned int num, char *array)
{
//	array 마지막 자리 null
//	(while) 숫자 0이상 일때까지
//		뒤에서부터 array를 채워넣음
//		i++
//	i 반환
}

int	ft_num_to_hex(size_t num, char *array, int is_addr, int is_upper)
{
//	array[19]을 0으로 memset
//	array[0], [1]에 각각 0, x 할당
//	(while) num을 16으로 나눈 몫이 0이 될 때까지 (size_t를 최대로 나눠도 16개까지 나옴)
//		array[17] 부터 나머지를 채워넣음(array[18]은 '\0'자리로 비우기 위함)
//		i--
//	멈춘지점의 인덱스를 반환
}

int	ft_num_to_str(int num, char *array)
{
//	array 마지막 자리 null
//	(while) 숫자 0이상 일때까지
//		뒤에서부터 array를 채워넣음
//		i++
//	i 반환
}

void	ft_putsign(t_info *field_info, int num, int *result)
{
//	(if) flags에 '+' or ' '이 있을 때
//		(if) 양수일때
//			(if) flags가 +이면
//				+출력
//			(else if) flags가 ' '이면
//				' '출력
//		(else if) 음수일때
//			-출력
//		field_info->width -= 1
//		result++
}

void del_info()
{
	//field_info를 형변환 후 초기화
}

void	feild_init(t_info *filed_info)
{
	//feild_info 초기화
}
