#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int find_max(int* arr, int size) //최대값 구하기 예제
{/*
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
*/
}

int* creat_arr(int size)
{
	/* 배열생성과 동적할당
	//int arr[size] -->이건 runtime 때 할당되어서 안됌. (정적할당)
	//이럴 때 동적 할당을 쓴다
	
	int *arr = malloc(size); //동적할당
	for (int i = 0; i < size; i++)
	{
		arr[i] = i + 1; //여기서 배열 변수 arr의 값을 넣어준 것
	}
	return arr;
	*/
}

void swap(int arr[], int size)
{
	/*
	for (int i = 0; i < size / 2; i++) //i는 공간의 갯수와 돌아가는 순자
	{
		tmp = arr[i];
		arr[i] = arr[size - i];
		arr[size - 1] = tmp;
	}
	*/
}


//call by value와 call by reference
void change(int i) //arguement를 받는 값: parameter
{
	//i = i + 10;
	//printf("change()에서 i= %d \n", i); //10
	//여기에서는 실제 i값이 아니라 0이라는 값만 복사가 되어 온 것이기 때문에 main함수에서 i를 print했을 때, int i = 0이라는 것이 변하지 않았기 때문에 0으로 출력되는 것이다.

}

//call by value와 call by reference
void change2(int* ip) //parameter에 포인터가 들었다
{
	//*ip = *ip + 10;
	//printf("change2()에서 ip= %d \n", *ip);
	//여기서 *ip는 i변수와 같다. 그러므로 i변수의 값이 함수에 따라 처리/변경된다. 그래서 main 함수에서 print했을 때 i의 값이 변경되는 것이다.
}

void chgadd(int**p)// p를 가지고 두번 역참조하면 정수가 나오더라
{
	/*
	static int i = 10;//static (함수가 끝나도 지워지지 않는다)
	*p = &i; //*p는 main에 있는 p와 같다.
	*/
}



int main()
{
	//5일차 아침 예제
	//키보드에서 문자열을 입력 받기
	//문자열을 원소로 하는 배열
	//회원 5명의 이름을 배열에 저장하고 화면에 표시해보세요


	/*char name[5][30];//30 크기의 공간 배열을 5개 정렬해라~ 

	for (int i =0; i < 5; i++)
	{
		printf("이름을 입력하세요:");
		scanf("%s", name[i]); //name만 치면 배열의 첫번째 주소만 가르키고 있기 때문에 첫번째 원소에만 새로운 정보가 저장되고 있는 것이어서 name[i]라고 해서 다음 입력 떄는 다음 배열에 저장할 수 있도록 해줘야한다.
	}

	for (int i = 0; i < 5; i++)
	{
		printf("입력된 이름은: %s \n", name[i]);
	}
	*/
	/*선생님 예시
	char* name[] = { 순디, 빵주, 지수 }; //"순디" "빵주" "지수"라는 문자열이 있는 주소가 저장되어있는 공간을 여러개 만든 것 char*[]. 내 예시에서 이걸쓰면 오류남.. 왜냐? 노트에 적혀있는 id 예시 참고.
	for (int i = 0; i < sizeof(name) / sizeof(char*); i++)
	{
		printf("%d. %s \n", i + 1, name[i]);
	}
	*/

	/*키보드에서 문자열을 입력 받기
	printf("이름을 입력하세요:");
	//char* name = NULL; --> 오류가 난다
	char name[20]; --> 오류가 나지 않는다. 이유는 위를 참고
	scanf("%s", name);
	printf("입력된 이름은: %s \n", name);
	*/

	/*
	//키보드에서 입력된 문자열을 공백 구분없이 한 행 전체 읽기
	// 이름 번호 전화번호<enter>치면 3개의 정보 모두 읽기 (scanf는 스페이스 치면 첫자료만 읽어온다)
	//gets()함수를 이용하여 한 문장 전체를 입력받아 표시해보세요
	char info [50];
	printf("이름 번호 전화번호를 입력하세요:");
	gets_s(info, 50); //정보 입력
	//puts(info); //정보 출력 (딱 정보만 출력)
	//printf("당신의 정보는: %s", info); (서식을 정해 다양한 변수의 값을 출력할 수 있다)
	

	//키보드에서 입력받는 명령어 scanf
	//문자열에서 입력받는 명령어 sscanf (문자열에 든 여러가지 변수 값을 분류해주는 함수)
	//sscanf (string scanf) 써서 변수 정보를 각 토큰으로 분류해보기
	char name [20];
	int num;
	int num2;
	sscanf(info, "%s %d %d", name, &num, &num2); //이름 번호 전화번호를 문자열, 정수, 정수로 분리하여 name, num, num2의 주소에 저장하라.
	printf("이름: %s 전화번호:%d 번호:%d", name, num2, num);
	*/


	//번외: 정보를 구분할 때 구분자로 공백(스페이스바)를 쓰기보다 | 이런 기호를 자주쓴다
	/* strtok( string token) 문자열 속에서 최소 의미를 갖는 단어를 찾아낸다
	char str[30] = "지수|3|241355";
	char* field[] = { "이름", "번호", "주소" };
	char* prt= strtok(str, "|");
	
	for(int i =0; prt!=NULL ;i++)
	{
		printf("%s\t%s \n", field[i], prt);
		prt = strtok(NULL, "|"); //이건 그냥 이런 공식
	}
	*/

	



	//문자배열(문자열) 다루기
	//char str[] = { 'H', 'e', 'l', 'l', 'o', '\0'};
	//printf("%s \n", str); //'\0'를 주지 않으면 문자 배열의 끝을 인식하지 못하고 추가적인 쓰레기 문자들도 출력한다.
	//'\0'는 문자 배열이 끝났음을 알려준다. (c언어 에서는 그럼)
	//char str[] = "Hello"; //""를 써서 문자열을 넣어주면, \0이 자동으로 포함된 거나 마찬가지 
	//printf("%c", str[0]); //결과는 H //이것도 배열이니 공간을 지정해주면 하나씩 출력가능
	//str[0] = 'h'; //원소를 지정하여 다른 값을 정상적으로 삽입하고 출력할 수 있다.
	//printf("%c", str[0]); //결과는 h
	//배열 변수는 포인터 상수이지만 문자열은 상수가 아니니 (각 원소에 접근해) 바꿀 수 있다.//배열 변수는 포인터 상수

	//char* str = "Hello";
	//포인터로 선언된 문자열은 상수여서 조작할 수 없다. 하지만 str은 변수여서 조작 가능하다 (다른 주소를 받을 수 있다).
	//"Hello"는 문자열 상수
	//str[0] = 'h';
	//printf("%s \n", str); //프로그램이 돌아가지 않고 끝남. 오류라는 뜻.
	//str이 가지고 있는 문자열 수정 불가 (const char* str = "Hello")와 같다.

	//str = "World";
	//printf("%s \n", str); //world라고 잘 출력된다.
	//char str2[6];//포인터 상수 (방 한개한개를 고칠 수 있지만 포인터의 주소를 바꿀 순 없다)
	//str2[0] = 'H';

	//char* str2 = "Hello";

	//printf("%d %d \n", str, str2);
	//str과 str2의 주소가 같다. "Hello"는 두개가 아닌 동일한 값이다. 

	//c언어 문자열 함수 string.h 이용 예시
	//char dest[20];
	//strcpy(dest,"Hello"); //문자열 copy(복사) string copy //첫번째엔 
	//"Hello"(소스)를 dest로 "Hello"라는 문자열 상수를 복사하라.
	//printf("dest = %s \n", dest); 결과는 Hello

	//문자열 함수 예제
	/*strcat(str1,str2) 문자열을 연결하라는 함수
	char dest[20] = "Hello";
	char* cnt = "World";
	strcat_s (dest,cnt, 20);
	printf("%s \n", dest);
	*/

	//strcmp(str1, str2) 
	//string compare : str1 과 str2를 비교하라. 
	//나올 수 있는 값: 0 (문자열이 완전히 일치), 1(왼쪽이 더 큰 문자열이면: ascii코드에서 더 큰 수(사전상 뒷쪽에 나온다), -1 (왼쪽이 더 작은 문자열이면: ascii코드에서 더 작은 수 (사전상 앞쪽에 나옴)




	/*포인터 변수를 하위 함수에서 바꾸는 예제 call by reference 포인터 예제
	int a = 5;
	int* p = &a;
	printf("*p=%d \n", *p);// = 5

	//위의 식을 가지고 하위 함수를 호출하여 p에 주소를 다른 주소로 변경해보세요.
	//결과가 10이 나오도록 해보세요

	chgadd(&p); //call by reference (p에 들어잇는 주소를 바꿔주는 것)
	printf("*p=%d \n", *p);
	*/

	/*포인터와 배열
	int arr[] = { 1,2,3,4,5 }; //4byte공간이 5개 있는것. 주소는 byte마다 있으니까 주소도 20개가 있을것.
	//첫 공간의 주소만 알면, 나머지 배열의 주소도 알 수 있다. (어짜피 순차적으로 나가기 때문)
	// arr[0] = 1이 있는 주소

	printf("%d", *(arr + 0)); //*(arr+0) 에 대한 약식 = arr[0] 배열을 생성하는 수식과 같아보이지만 쓰는 장소에 따라 의미가 바뀐다
	printf("%d", *(arr + 1)); //arr[1]
	printf("%d", *(arr + 2)); //arr[2]
	printf("%d", *(arr + 3)); //arr[3]
	printf("%d", *(arr + 4)); //arr[4]
	*/

	/*다차원 배열
	int score[2][3]  = { //2차원배열 (1차원 배열을 원소로 거느린 배열이다~) //score[]배열에 들어있는 주소는 맨 첫번째 주소 {1}이 들어있는 주소
		{1,2,3}, //이거 하나는 정수 배열
		{4,5,6}  // {전체= 배열의 배열}
	}; //--> 방 3개(일차원 배열이)를 가지고 있는 배열이 2개 (총 방 수는 6개)
	//e.g.한 반의 학생의 각 과목 성적
	//보기 편하게 저렇게 놨지만 실제로 메모리에는 {1,2,3},{4,5,6}이런식으로 쭉 이어져있다.
	
	//score[0][0] = 10; //score 배열의 1번째 원소에 있는 1번째 방
	//score[0][1] = 20;
	//score[0][2] = 30;
	//score[1][0] = 40;
	//score[1][1] = 50;
	*/

	//다차원 배열 예제
	/*위의 원소들을 포인터 연산을 활용하여 모두 표시해보세요

	int* b = score;
	for (int i = 0 ;i<6 ;i++) //i<6은 2*3을 한 변수의 개수
	{
		printf("%d", *(b + i));
	}
	*/

	//포인터 배열 (포인터를 원소로 하는 배열: 주소를 담고 있는 배열), 정수 배열 (정수를 원소로 하는 배열)
	//정수 변수의 주소를 원소로 하는 배열
	/*
	int* parr[3]; //int* 정수 변수의 주소를 parr[3] 3개 공간의 배열에 저장하겠다.
	int a, b, c;
	parr[0] = &a; //첫 원소에는 a의 주소를 넣는다
	parr[1] = &b;
	parr[2] = &c;

	a = 1; //a는 1이라는 값이다
	b = 3;
	c = 6;
	*/
	//parr배열을 이용하여 a,b,c에 저장된 값을 표시해보세요.
	
	/*for (int i = 0; i < 3; i++)
	{
		printf("%d \t", *parr[i]); //parr[i]라는 표시 자체가 주소를 찾아가겠다는 의미. 이미 주소를 찾아갔으니 *을 한번 붙여서 그 주소의 값을 찾아간다.
	}
	*/
	//또 다른 표현: printf("%d", **parr); 여기서는 parr만 있으니 *parr로 주소를 추출하고 그 값을 추출하기 위해 **parr을 해준다.
	
	


	/*동적할당 배열생성
	int *arr = creat_arr(8);
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", arr[i]);
	}
	//동적으로 할당 했으면 메모리를 필수적으로 헤제해줘야한다.

	free(arr); //동적할당 메모리 해제
	*/

	//배열 생성과 동적 할당 예제
	//1~5까지 저장한 배열을 생성하고 그 배열을 다른 함수에 전달해서 
	//뒤집어진 배열을 리턴하는 함수를 작성해보세요.
	
	//오후 수업
	//Call by value, Call by reference(address)
	/* call by value와 call by reference 설명
	int i = 0;
	//change(i); //parameter로 넘어가는 실제의 값: argument //printf하면 0 --> 왜 바뀌지 않았을까? (call by value --> 메인함수에서의 값을 바꿀 수 없다. 그래서 0이 출력)

	change2(&i);
	printf("main()에서 i= %d \n", i);
	*/



	//Array (배열)
	/* int a, b, c; //3개의 정수 공간 --> for loop 적용 x
	a = 1;
	b = 2;
	c = 3;

	int arr[3]; //3개의 정수 공간 --> for loop 적용 가능
	//arr은 배열 변수, 포인터 상수
	//포인터: 할당된 메모리의 첫번째 공간의 메모리 주소를 가진다.
	//상수: 다른 메모리의 주소를 재할당 할 수 없음을 의미
	//배열 변수 선언
	 
	//배열 변수 초기화
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	*/
	//printf("arr: %d \n", arr);--> 메모리 주소가 나온다. arr메모리 주소에 든 값을 구하려면 역참조(*arr)을 하거나, arr[index 값]을 준다.
	//또 다른 배열 변수 초기화 방법
	//int nums[] = { 1,2,3 };
	//[3]이라는 '공간 3개를 확보해라~'라는 명령이 없어도 {}안에 값의 개수를 컴파일러가 자동으로 세어서 공간을 마련하고 {}안에 값을 넣어준다
	//실무에서는 잘 안쓰이고, 공부할 때 씀
	//int num2[3] = { 0, };
	//[]안에 든 갯수만큼 공간을 확보하고 맨 처음의 방(원소)을 {}의 적힌 수로 초기화하고, 나머지 방(원소)들은 빈칸(0)으로 초기화하라.

	// 배열의 공간 크기는 컴파일시(코딩하고 저장할 때)에 결정될 수 있어야 한다. 
	/* 예시: 키보드로 배열변수의 크기를 지정하고 싶었다. 
	printf("원소의 개수를 입력하세요:");
	int size;
	scanf("%d", &size);
	int nums[size]; 이 때 식에 상수값이 있어야 한다는 메시지가 뜨는데, 배열변수의 공간 크기가 컴파일 시 정해지지 않고 runtime 후 결정되기 때문에 안됌.. c언어에서는.
	*/

	/*
	int a, b, c;
	a = 1;
	b = 2;
	c = 3;
	//-->에선 for loop를 돌려 값을 순차적으로 산출 할 수 없다.
	*/
	/*
	int arr[3];
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;

	for (int i = 0; i < 3; i++)
	{
		printf("d%", arr[i]);
	}
	*/

	/*정수원소 10개를 가진 배열을 준비하고 무작위 수로 초기화합니다.
	//모든 원소의 값과 최대값을 표시해보세요.
	//loop를 두개로 하라 (초기화하는 루프, 출력하는 루프)
	int arr[10];
	srand(time(0));
	int max = 0;
	
	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand() % 30 + 1;
	}							//초기화 하는 루프

	for (int i = 0; i < 10; i++)
	{
		printf("%d \n", arr[i]); //아니면 *(arr*i) 그냥 *arr하면 가장 첫번째 값만 불러온다.
		
	}							//출력하는 루프

	for (int i = 0; i < 10; i++)
	{
		if (arr[i] > max) max = arr[i];
	}
	printf("최대값: %d \n", max); //print는 한번만 하면 되니까 마지막에 써주고, max 검사는 모든 수에서 해줘야 하니까 루프로 돌려준다.
	*/

	/*swap 알고리즘: 맞교환하는 알고리즘
	int a = 1;
	int b = 2;
	a = b;
	b = a; 이건 성립이 안됨
	int tmp = a; //다른 메모리 공간에다 a의 원래 값을 기억시켜 b에게 준다
	a = b;
	b = tmp;
	printf("a = %d \t b = %d \n", a, b);
	*/

	/* 배열원소 뒤집기
	int swap[] = { 1,2,3,4,5 };
	int tmp;

	for (int i = 0; i < 5 / 2; i++) //i는 공간의 갯수와 돌아가는 순자
	{
		tmp = swap[i];
		swap[i] = swap[4 - i];
		swap[4 - 1] = tmp;
	}

	for (int i = 0; i < 5 / 2; i++)
	{
		printf("%d", swap[i]);
	}
	*/

	/* 배열에서 최대값 구하기 예제
	int swap[] = { 1,2,3,4,5 };
	int max = find_max(swap, sizeof(swap) / sizeof(int));
	printf("배열원소 중의 최대값:%d \n", max);
	*/



	return 0;
}