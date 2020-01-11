#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	//자료구조와 알고리즘
	/*5개의 정수 원소를 가진 배열을 생성하고 
	임의의 수(20이하)로 원소를 초기화하고 표시해보세요
	*/

	srand(time(0));
	int arr[5];
	int rd = 0;
	int i = 0;
	
	/*
	for (int i = 0; i < 5; i++)
	{
		rd = rand() % 20 + 1; //rd란 변수에 무작위 수 추출
		arr[i] = rd;
	}
	*/
	
	outer_loop: //Label
	while (i < 5)
	{
		rd = rand() % 20 + 1;
		for (int j = 0; j <= i; j++) //중복 방지 루프
		{
			if (arr[j] == rd)//중복된 값인지 확인
			goto outer_loop; //Label. goto는 잘 안쓴다. 왠만하면 쓰지 말 것. 
		}
		arr[i++] = rd;
	}

	//추출한 랜덤한 수를 오름차 순으로 정렬한다.
	/*선택 정렬 (Selection Sort)
	int tmp = 0;
	for (int i = 0; i < 5 - 1; i++) //선택을 위한 방
	{
		for (int j = i + 1; j < 5; j++) // 선택한 방 우측에 있는 방
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i]; //swap 알고리즘
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	*/
	
	/* 거품정렬 (Bubble Sort) 
	int temp = 0;
	for (int i = 4; i >=0 ; i--)
	{
		for (int j = 0; j < i ; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	*/

	//삽입정렬
	int end = sizeof(arr) / sizeof(int);
	int begin = 1;

	for (int i = begin; i < end; i++) //오른쪽으로 나가는 비교할 순서
	{
		int temp = arr[i]; //기준값
		int idx = i; //비교할 왼쪽값
		for (int j = i - 1; arr[j] > temp && j >= 0; j--)
		{
			arr[idx--] = arr[j]; //j의 값을 오른쪽로 방에 할당시킨다.
			arr[j] = temp;
		}
	}



	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
	

	


	return 0;
}