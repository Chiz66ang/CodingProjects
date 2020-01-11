#include <stdio.h>
#include <stdlib.h> //임의의 두 수를 저장할 때 이거 두개 추가하기
#include <time.h>
#include <math.h>
#define PI 3.141592F

void smaple() 
{
	//printf("여기는 sample 함수 \n");
	//static int count = 0;
	//count = count + 1;
	//printf("카운트 : %d \n", count);
	//메인 함수 윗쪽에 있어야만 메인 함수에서 smaple 함수를 불러서 쓸 수 있다.
	//호출 (invocation): 메인 함수에서 다른 함수를 불러 실행시키는 것

	//정적 (static)변수: 자동이 아닌 한번 만들어 놓으면 유지(고정)되는 변수를 만들고 싶을 때.
}

// 임의의 두 수를 덧셈하고 그 결과식과 답을 함께 표시하는 add() 라는 함수를 정의하고 호출해보세요.
int add(int a, int b)
{
	//return a + b;
	//int a = 1+2;

	//printf("1+2 = %d \n", a);

	/*
		int a=3, b=5;
		printf("%d + %d = %d \n", a, b, a+b);
	*/

	/* 무작위 수 추출하는 법
	srand(0); //랜덤한 범위에 씨앗 (0) 값을 준다
	int a = rand() % 10 + 1; //무작위 수의 나머지 (10개로 나눴으니 나머지가 10개 (0부터 9까지)에 +1을 더해서 1-10까지로 만는다)
	int b = rand() % 10 + 1;
	printf("%d +%d = %d", a, b, a + b);
	씨드를 똑같이 심었으면 똑같은 값이 나온다.
	*/
	
	
	//time(0)은 현재 시스템 시간; 정수로 표현된다. 이건 컴퓨터마다 다르기 때문에 완전 랜텀한 수를 돌릴 때 좋다.
	//printf("%d +%d = %d", a, b, a + b);
	

	//printf("%d +%d = %d", a, b, a + b);
	//함수 parameter 변후
}
//값을 리턴하는 함수
//파라미터 한개를 선언하고, 그 파라미터로 정수 한개를 받아서, 그 수가 짝수면 0 아니면 1을 리턴하는 함수를 정의하고 호출해보세요.
//출력 예시) 3의 홀수여부 : 1 or 0

int prct(int a)
{
	//return a % 2;

}
//원의 반지름(실수)을 파라미터로 받아서 원의 면적을 계산하여 리턴하는 기능을 함수로 작성해보세요.
//원의 면적: 반지름*반지름*3.14

float O (float a)
{
	//return a * a * PI;
}

//삼각형의 높이와 밑변을 실수로 받아서 면적을 계시하고 그 결과를 정수로 리턴하는 기능을 함수로 작성해보세요.
//삼각형의 면적은: 밑변 * 높이 /2

int area(float h, float w)
{
	//return h * w / 2;
}


/*
삼각함수
60분법: 0-360 [deg]
호도법: 반지름 길이에 해당하는 원주가 이루는 각도 [radian] --> 작은 숫자로 큰 각을 나타낼 수 있다. --> 자주씀
2PI [rad] = 360 [deg] / PI [rad] = 180 [deg]
*/

//60문법 단위의 각도를 실수형으로 받아서 호도법 단위 (실수)로 변환하여 리턴하는 함수를 작성해보세요.
//반대도 해봄
float rad(float deg)
{
	//return deg * PI / 180;
}

float deg(float rad)
{
	//return rad * 180 / PI;
}

double cos2(double deg)
{
	//return cos(rad(deg));

}
int main() //메인 함수 (함수 헤드)
{ 
	//sin 0 = 0, sin 90 = 1, cos 0 = 1, cos 90 = 0 --> 컴퓨터는 이 값을 모두 저장하고 있다.
	//이것을 쓰려면 수학 관련 파일을 인클루드 시켜야한다.
	// #include <math.h>


	//double sv = sin(rad(90.0F)); --> 값을 줄 때 항상 radian 단위로 주는 것을 잊지 말기.
	//float rad 함수를 불러와 값을 넣은 공식
	//printf("sin(90)=%f \n", sv);
	
	//cos2(45.0F); 로 값이 바로 나오도록 만들어보세요
	//double cv = cos2(45.0F);
	//printf("cos(45) = %f \n", cv);
	// float rad 함수 이후에 double cos2 함수가 적용이 되어 숫자를 바로 입력해도 변환, 변환 되어 리턴되는 값을 가질 수 있다.


	/*
	float rad = 0.42F;
	float res = deg(rad); --> 이 과정을 건너뛰고 float res = deg(0.42F) 를 넣어서 printf로 출력 가능.
	printf("%f radian은 %f degree 입니다. \n", rad, res);
	*/
	/*float deg = 30.2F;
	float res = rad(deg);
	printf("60분법 %f는 %f radian 입니다. \n", deg, res);
	*/


	/*
	float h = 3.2F;
	float w = 4.2F;
	int res = area(h, w);
	printf("높이 %f 와 밑변 %f인 삼각형의 면적은: %d \n", h, w, res);
	*/

	/* float a = 2.15F;
	float res = O(a);
	printf("반지름 %f의 원의 면적은 %f 입니다. \n", a, res);
	*/

	/*
	int a = 3;
	int res = prct(a);
	printf("%d은 홀수인가?: %d \n", a, res);// 아님 printf res 자리에 prct(a)를 넣으면 int res 변수를 따로 정의하지 않아도 된다.
	*/


	//전처리기 : Preprocessor
	//전처리 명령 : 명령어 앞에 # 기호가 붙은 명령어 (컴파인 전에 #붙은 명령어를 먼저 처리하라.)
	//define = define 상수라고도 통한다. 프로그램 코드를 직관적으로 만들어줌.

	//printf("연습 \n");
	//printf("%f \n", PI);
	//컴파일 되기 전에 include 하라. 무엇을? <stdio.h> 
	//컴파일을 진행할 때 Stdio.h에서 가져와 컴파일.


	//코드블럭{}: 한번에 실행되는 코드의 단위 (위에서부터 아래로)
	// 블럭 안에 블럭이 있을 수 있음
	//auto int a = 10; //auto= 자동 변수라는 뜻. 블럭이 시작되면 a공간을 자동으로 만들고, 블럭이 끝나면 a공간도 지워짐. 요즘은 안씀.
	//printf("a=%d \n", a);
	 //블럭의 끝. 블럭에서만 나오는 변수를 지역 변수 (local value)라고 한다.

	//printf("a=%d \n", a); 블럭을 벗어났기 때문에 에러가 남.

	//smaple(); //함수 호출: smaple 함수를 호출해서 실행시키는 것
	//smaple();
	//smaple();// 몇번씩 복붙해도 다 돌아감

	/* srand(time(0));//이건 원래 main 함수 가장 위에 들어가면 된다. 씨앗 값은 main에 넣어준다. 0 대신에 null 넣어도 됨
	int a = rand() % 10 + 1;
	int b = rand() % 10 + 1;
	int sum = add(a, b); 이렇게 해도 됨
	*/
	//add(rand() % 10 + 1,rand() % 10 + 1); 괄호 안에 수를 주면 두 수가 함수 괄호로 넘어간다. add 함수에 int a, int b를 넣어주면 괄호에서 호출한 값이 들어간다.

	//printf("%d + %d = %d \n", a, b, sum);

	return 0;
}