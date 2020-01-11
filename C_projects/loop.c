#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void gugu(int num)
{
	/*for 루프 구구단 문제
	for ( int i =1 ;i <=9 ; i++ )
	{
		printf("%d 곱하기 %d는 %d \n", num, i, num*i);
	}
	*/
}

int random_num()
{
	
	srand(time(0));
	int cnt;
	int max =0;

	for (int cnt = 0; cnt < 20; cnt++);
	{int rd = rand() % 50 + 1;
	printf("%d \t", rd);
	if (rd > max) max = rd;
	}
	return max;
	
}


int main()
{
	//4일차
	/* 50이하의 무작위 정수 20개를 추출하는 중에 가장 큰 수는 어떤 수인지 확인하여 화면에 표시해보세요.
	20개의 숫자도 모두 표시되어야 하고 그 중 가장 큰 수는 어떤 수인지 별도로 표시하세요

	- 50이하의 무작위 정수 20개
	- 모든 정수 printf("%d t\ %d t\ %d t\ %d t\ %d t\")
	-가장 큰 수 (수 비교)를 printf ("가장 큰 수: %d \n",) --> 함수 만들기
	--> 루프 안에 루프
	*/
	printf("\n 최대값: %d \n", random_num());
	


	//반복문 (while, do while, for)
	/*
	int cnt = 0;
	while (1)
	{
		//괄호 안에 들어가는 것이 상수일 때 (무한 루프일 때) {}안에 명령을 넣어 루프를 끊어주기
		cnt++;
		
		printf("루프(%d) \n", cnt);
		if (cnt == 10) break;
	}
	*/


	

	/*20부터 11까지 거꾸로 합산하는 기능 작성

	int cnt = 20;
	int sum = 0;
	while (cnt >= 11)
		{
		sum += cnt--;

	}

	printf("값은: %d \n", sum);
	*/

	//while 루프를 이용하여 1부터 20 사이의 정수 중에서 홀수만 출력하시오. 

	/*
	int all = 0;
	while (1)
	{
		all++;
		if(all%2 == 1) printf("홀수는 %d 입니다 \n", all); //if 조건이 충족되었을 때 print 하라
		if (all == 20) break; //all이 20에 도달했을 때 while 루프를 멈추어라
	}

	while (++all <= 20) if (all % 2) printf("d%", all);
	한줄로 쓴 것: all값을 하나 올렸을 때 20 보다 작거나 같을 때, if가 충족되면 print 하라.
	*/

	//임의의 수를 추출하여 짝수만 10개를 출력해보세요.
	//임의의 수 = 1 - 20 사이의 무작위 수
	//루프의 탈출 조건을 세워라. (출력한 수가 10개인가)
	/*
	int cnt = 0;
	int num;
	srand(time(0));

	
	while (cnt < 10)
	{
		num = rand() % 20 + 1; //num은 나머지가 0-19까지 (+1했으니 1-20까지)인 수를 뜻한다
		if(num%2 ==0)
		{
			cnt++;
			printf("%d \t %d \n", cnt, num);
			
		}
	}
	*/
	/*continue를 사용
	while (cnt < 10)
	{
		num = rand() % 20 + 1;
		if (num % 2) continue;// if가 True 일 때 continue 가 실행. continue는 처음으로 돌아가서 다시 실행하라는 뜻이다. 
		//이 경우 수가 짝수일 때 (false) 아래 수식을 실행하는 것이고, 홀수 (true)일 때 continue가 실행되어 처음으로 돌아가는 것이다.
		cnt++;
		printf("%d \t %d \n", cnt, num);
	}
	*/

	/* do~while 문장
	int i = 0;
	/* while (i < 10)
	{
		printf("%d", i++);
	}
	
	do //조건이 없는 함수는 무조건 실행. 검사하기 전에 실행되는 것이라 무조건 1번은 실행이 된다. 하지만 while은 조건을 붙이고 실행하는 것
	{
		printf("%d", i++);
	} 
	while (i < 10);
	모든 do~while 문장은 while문장으로 할 수 있어서 그냥 while문장 많이 씀.
	*/

	//for 문장

	/*int i = 0; 원래는 이렇게 함수 밖에 써주었으나, 한번만 쓰는 일회용 변수이니 1번 섹터에 넣어주면 좋다.
	for (int i = 0 ;i < 10 ;i++)
	{
		printf("%d",i); // printf("%d",i++)를 하기 보단 어짜피 i++가 3번 섹터의 자리에서 실행되니 3번섹터로 옮겨준다.
					//3번 섹터에는 2번섹터의 값을 바꿔주는 수식이 쓰인다. (1,3번 섹터는 루프를 돌리기 위한 보조적인 수식들이 들어간다)
	}
	*/

	/* for 루프 문제
	gugu()함수를 선언하고 그 함수에 단수를 전달하면 
	해당 구구단이 화면에 표시되도록 해보세요.
	
	
	while (1)
	{
		printf("숫자를 입력하시오: \n");
		int num;
		scanf("%d", &num);
		if (num == 0) break; //break는 반복되는 문장을 끊는 다는 뜻
		gugu(num);
	}
	//단수입력, 종료(0): while루프 안쪽에 저것이 들어가야함,
	*/

	/* 
	for 문장을 이용하여 1부터 10까지 찍고 다시 1로 순차적으로 내려오도록 출력해보시오.
	
	for (int a = 1, b = 1; a > 0; a += b)
	{
			printf("%d", a);
			if (a == 10) b = -1;
	}
	*/

	//중첩된 for루프: 루프 안에 루프가 있는 것
	//노트에 수식 있음

	/* 풀 구구단 만들기
	for(int a = 1 ;a<10 ; a++ ) //곱해있는 수
	{
		for (int b =2 ; b <10 ; b++) //단수
		{
			printf("%d * %d = %d \t", b, a, a*b); //행 바꿈
		}
		printf("\n"); //줄 바꿈 \n, \t는 개행문자
	}
	*/
	
	



	return 0;
}