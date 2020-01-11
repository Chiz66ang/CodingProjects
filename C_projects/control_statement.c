#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*키보드에서 문자 한개와 숫자 한개를 입력받아서 로그인을 수행한다
문자는 이용자의 id로 간주하고, 숫자는 암호로 간주한다.
아이디가 B이고 암호가 2222인 이용자만 로그인 성공 메시지를 출력하고
로그인에 실패한 이용자에게는 로그인 실패 메시지를 표시한다*/

void login(char id, int pw)
{/*
	char* result;
	if ((id == 'B') && (pw == 2222)) result = "로그인 성공";
	else result = "로그인 실패";
	printf("%s \n", result);
	*/
}

int add(int a)
{
	/*오늘의 요일을 switch 함수로 표현해보시오
	int sum = 0;
	switch (a)
	{
	case 1: sum += 1;  //흐름을 깨줄 때 사용
	case 2: sum += 2; 
	case 3: sum += 3; 
	case 4: sum += 4; 
	case 5: sum += 5; 
	case 6: sum += 6; 
	case 7: sum += 7; 
	case 8: sum += 8; 
	case 9: sum += 9; 
	case 10: sum += 10;
	}

	return sum; */
}

char* day(int wday)
{ /*오늘의 요일을 switch 함수로 표현해보시오
	char* sday; //static은 없어도 댐 고정 하거나 하지 않아도 되기 때문
	switch (wday)
	{
	case 0: sday = "일"; break;
	case 1: sday = "월"; break;
	case 2: sday = "화"; break;
	case 3: sday = "수"; break;
	case 4: sday = "목"; break;
	case 5: sday = "금"; break;
	case 6: sday = "토"; break;
	}
	
	return sday;
	*/
}
int main()
{
	/*오늘의 요일을 switch 문장으로 해결해보세요

	time_t tm_t = time(0);
	struct tm* ptm = localtime(&tm_t);
	int wday = ptm->tm_wday;


	char* sday = day(wday);
	printf("오늘은 %s 요일 입니다. \n", sday);
	*/

	/*시간 구하기
	time_t tm_t = time(0);
	struct tm* ptm = localtime(&tm_t);
	int wday = ptm->tm_wday;
	//이건 time기억하고 요구하는 명령어 따라서 하기
	//char* sday;


	if		(wday == 2) wday = "화"; //sday =화
	else if (wday == 3) wday = "수"; //0= 일요일 부터해서 쭉쭉 가면 됨.

	printf("오늘은: %s 요일입니다 \n", wday); //sday
	wday는위에서 int (정수)로 지정을 해주었기 때문에 char*을 써서 문자 정보를 다시 지정해주는 것이 옳다.
	*/

	/*로그인 문제
	
	char id;
	int pw;
	printf("아이디와 비밀번호를 입력하세요: \n");
	scanf("%c", &id);
	scanf("%d", &pw); //문자와 숫자를 모두 id로 인식 해서 같이 놓으니까 안돼었다. 이렇게 분리해놓으니 됨
	login(id, pw);
	*/
	
	


	//제어문 (Control Statment)

	/*조건이 두개일 떄 삼항 연산자를 만들어보고, if문으로도 만들어보았다.
	srand (time(0));
	int rd = rand();
	char* res = (rd % 2 == 0) ? "짝수" : "홀수";

	printf("res: %s \n", res);

	char* result;
	if (rd % 2 == 0) result = "짝수";
	else result = "홀수";
	printf("result: %s \n", result);
	*/

	/*switch 문장
	int a = 1;
	switch (a)
	{
	case 0: printf("0입니다. \n");
	case 1: printf("1입니다. \n");
	case 2: printf("2입니다. \n");
	case 3: printf("3입니다. \n");
	default: printf("그 외의 \n");
	}
	*/

	/*switch 문제
	//키보드에서 입력된 수를 함수에 전달하면 그 함수는 받아들인 수부터 10까지 합산한 결과를 리턴하는 기능을 작성해보세요
	
	printf("수를 입력하세요: \n");
	int a;
	scanf("%d", &a);
	int sum = add(a);
	printf("%d~10까지 합산한 결과: %d \n", a, sum);
	*/

	

	printf("프로그램 종료... \n");
	return 0;
}