#include<stdio.h>

int main()
{
	/*printf("안녕하세요? \n"); //정보처리 안녕하세요? \n= 정보, print f()= 처리 방법 
	printf("Hello World \n");
	// Comments(주석), 행주석
	/*
		다중행 주석
		소프트웨어의 목적: 정보처리 (Information Processing)
		정보의 유형 (Data types) int = 정수 (정수를 저장하는 공간을 확보하고 저장한다: 저장공간 4byte = 32bit)
		처리 (연산자, 제어문, 함수(연산자와 제어문이 모여 함수를 만들어낸다), 라이브러리(이미 나와있는 처리 방법론; 많이 쓰는 기능, 표준 함수 등))
	*/
	//int a = 1 + 2;

	//printf("덧셈결과: %d \n", a);
	//첫 문장에서 두번째 문장 넘어갈 때 시간이 걸린다.

	//두 수를 먼저 더하고, 그 결과 값에 2를 곱한 다음, 그 결과 값을 3으로 나눈 결과를 화면에 표시해보세요
	// 덧셈은 +, 뺄셈은: -, 곱셈은 *, 나눗셈: / (몫만) 나눗셈: % (나누어서 나머지를 반환하는 연산자: 나머지만 보여주는 연산자) (산술연산자)
	
	/*
	int result = 3 + 5;
	int result2 = result * 2;
	int finresult = result2 / 3;
	printf("최종결과: %d \n", finresult);
	정수 메모리 총 3개 사용 = 12바이트 사용
	*/


	//printf("4 %% 2: %d \n", 4 % 2);

	/* 임의의 수에 5를 더하고, 그 결과에 3을 곱하여, 그 결과가 짝수라면 0을 출력하고, 홀수라면 1을 표시하시오.
	*/


	/*int re1 = 4 + 5;
	int re2 = re1 * 3;
	int re3 = re2 % 2;
	printf("최종결과: %d \n", re3);
	
	int a = 7+5;
	a= a*3; --> 이렇게 하면 기존 a에 연산된 새 값이 적용됨
	a= a%2;
	printf("결과: %d \n", a);

	int size = sizeof(int);
	printf("int의 크기: %d[bytes] \n", size);
	*/
	
	/* int size = sizeof(char);
	printf("char의 크기: %d[bytes] \n", size);
	*/
	//16비트 자료형 short 공간에 저장 가능한 양/음수의 한계
	// char (1byte), short (2byte), int (4byte), long (4 byte,잘 안씀)
	/* short 16비트 = -32768부터 32767까지 표현 가능
	char c; // -1 ~ -128, 0~127
	c = 128;
	printf("c=%d \n", c);
	결과는 -128이 나오는데 이는 정상 값이 아닌 overflow 된 값
	*/

	//int의 양수 한계를 1초과하는 수를 int 공간에 기억시키고 어떤 수로 되돌아가는지 확인해보시오
	//int c = 2147483648;
	//printf("c=%d \n", c);

	/* char, short, int
	char는 문자를 저장할 수도 있다. 이때 ''를 쓴다.
	char c = 'a';//문자 --> 숫자로 변환하여 저장 (ASCII 코드, UNICODE)
	printf("c=%c(%d) \n", c, c);//변환할 값이 2개니까 오른쪽에도 값이 2개 들어가야 한다.
	*/

	/* 대문자 A에 1을 더해서 그 값을 문자와 숫자로 표시해보세요.

	char a = 'A';
	a = a + 1;
	printf("결과= %c(%d) \n", a, a);
	문자도 숫자로 변환(아스키코드)되어 있기에 문자에 숫자를 더할 수 있다. */

	/*
	printf("번호를 입력하세요:");
	키보드의 입력을 불러오는 명령어. 이용자는 번호를 입력하고 엔터키를 누른다. scanf 읽어들이는 명령어
	int num;
	scanf("%d", &num);
	printf("입력된 값은 %d 입니다 \n", num);
	*/

	//실수 자료형 (float, double)
	//float: 소수점 이하 정밀도가 최대 6자리까지 인지 된다.
	//double: " 15자리까지 인지 된다.
	//게임에서는 float 자주 씀.

	//float f = 0.1234567890F; //마지막 F는 float로 저장해달라는 뜻 (4byte: 바이트가 클 수록 정밀도 높아짐).
	//printf("f=%f \n", f); 6째자리에서 반올림된 값은 표시한다.
	//printf("%15.10f \n", f); 15자리까지 확보한 후 소수점 이하를 10자리까지 표시해라. 하지만 결과에서 마지막 3자리의 정밀도는 떨어짐.
	//double d = 0.12345678901234567890;
	//printf("d=%21.20f \n", d); //printf 로만 찍으면 최대 6자리까지만 표시해준다.
	//마지막 3자리를 제외한 나머지 자리는 정밀하다. 정수 (0.얼마얼마의 0)의 숫자가 크면 소숫점 정밀도가 준다.
	//float f = 0.12345678F;
	//코드에 포함된 정수 기본:int (4byte), 실수 기본: double (8byte) --> F(float: 4byte)를 붙여주면 메모리에 로드 되었을 때 바로 4 byte 공간으로 들어가 메모리 절약/ 속도감이 생긴다.

	/*
		정수: char (1), short (2), int (4), long (8) 보통 많이 쓰는 것: char (이미지 데이터 처리 할 때), int
		실수: float (4), double (8) 소수점 정밀도와 관련있다: float
		키보드에서 정보를 읽는 것
	
	//키보드에서 정수 2개를 입력하여 덧셈을 하고, 그 결과와 식을 함께 화면에 표시해보세요
	printf("첫번째 정수를 입력하세요: \n");
	int num1;
	scanf("%d", &num1);
	printf("두번째 정수를 입력하세요: \n");
	int num2;
	scanf("%d", &num2);
	int res = num1 + num2;
	printf("수식은 num1 + num2, 결과는: %d \n", res);
	*/

	/* 
	int a,b;
	printf ("두 수를 공백으로 구분하여 입력:");
	scanf("%d %d, &a, &b);
	int c = a+b;
	printf("%d + %d =%d \n", a, b, c);
	*/


	//2일차
	//키보드에서 실수를 입력받아서 메모리에 저장하고자 합니다. 그 값을 화면에 표시해보세요

	//printf("실수를 입력하세요: \n");
	//float num1; //double로 하면 에러가 나고, float로 하면 정상적으로 돌아감.. 왜지..
	//scanf("%f", &num1); //double 형으로 했을 때 scanf 의 %f를 lf로 바꿔야 한다. 

	//printf("실수는: %f \n", num1);

//상수(constants)와 리터럴(Literal)
	//const float PI = 3.141592F;
	//값을 지정하고 싶을 때. 명령어 앞에 const를 붙이면 그 값이 지정된다.
	//const를 붙인 메모리 공간을 '상수'(constants)라 부른다.
	//그 외를 '변수' (Variable)라 부른다.

	//PI = 2.3514F; // Literal (데이터의 직접적인 표현; 정보의 직접적인 표현) 
	//식이 수정할 수 있어야 하는 값입니다 = 고정 해놨기 때문에 다른 값으로 수정이 불가하다.

	//int a = 5; 다른 값을 받을 수 있는 메모리 공간 (변수)
	//5; // 다를 값을 받을 수 없는 메모리 공간; lvalue를 바꾸지 못함 (Literal 이자 Constants) (Literal은 constants다!)
	//a = 3 + 5; //표현식 (expression)
	//정수 리터럴, 실수 리터럴, 문자 리터럴 (홑따옴표 찍힌 문자; 쌍따옴표 찍힌 문자는 문자열)
	//char * str = "안녕하세요? \"C언어\" 를 공부합니다";
	//화면에 홑따옴표 한개를 표시하고자 한다면?
	//char ch = '\.'; 
	//홑따옴표는 문자를 지정하는 문법이어서 '''로 쓴다면 문법 위반이다. 그러므로 '앞에 역슬레시(\)를 붙여주어 '하나가 명령어가 아님을 지정해준다.
	//printf("%s \n", str); //%s = string 문자라는 뜻
	//홑따옴표나 쌍따옴표나 명령어 기호를 출력하고 싶다면 escape (기능을 없에버리는 명령어)를 쓴다.


	
	
	return 0;
}