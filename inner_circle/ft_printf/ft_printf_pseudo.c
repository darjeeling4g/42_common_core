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
					// (if) 현재문자가 number이면  atoi로 획득
				// (while) .precision field가 아닐 때까지
					// (if) 현재문자가 .이면 0획득
						// (if) 다음문자가 number이면 atoi로 획득
				// (if) 현재문자가 type field가 아니라면
					// return error
}

int printer()
{

}

void del_info()
{
	//field_info를 형변환 후 초기화
}
