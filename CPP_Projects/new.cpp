#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void print_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	delete[] arr; //배열일 때는 delete[] 아닐 때는 그냥 delete
}


int main()
{
	/*동적할당(malloc(12), new 키워드)
	int* arr = new int[3]; //실행시 정수 3개 저장할 공간을 확보해주세요.
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	cout << arr[0] << ", " << arr[1] << ", " << arr[2] << endl;
	//여기도 동적할당을 했으면 메모리를 수동으로 지워줘야한다.
	delete[]arr; //동적할당 메모리 해제.
	*/


	/* 동적할당 예제1
	키보드에서 입력 데이터의 수를 먼저 받아서 "몇개의 수를 입력하실건가요?"
	그 수에 해당하는 정수를 배열에 저장하고 -> 그 개수에 만큼의 배열 공간을 만든다.
	다른 함수로 전달하여 화면에 표시하는 기능을 작성해보세요.
	*/

	/*
	int a;
	cout << "입력하실 숫자의 갯수를 알려주세요: ";
	cin >> a;

	int* arr = new int[a];

	for (int i = 0; i < a; i++)
	{
		cout << "숫자를 입력해주세요: ";
		cin >> arr[i];
	}

	for (int i = 0; i < a; i++)
	{
		cout << arr[i] <<"\t" ;
	}
	

	stringstream을 쓴 선생님 예시
	cout << "입력한 숫자의 갯수는: ";
	int size = 0;
	string line;
	getline(cin, line);
	
	stringstream ss(line);//숫자 입력 부분
	ss >> size;
	ss.clear();

	int* arr = new(nothrow)int[size];
	if (arr == NULL)
	{
		cerr << "동적할당 실패" << endl; //동적할당을 실패했을 때, arr에 아무런 값이 안들어갔을때, 실패했다고 하고
		return 1; // main 함수를 끝낸다.
	}

	cout << size << "개의 정수 입력";
	getline(cin, line);

	ss.str(line);
	for (int i = 0; !ss.eof(); i++) //eof -> end of file 여기서는 스트림의 끝을 의미 (Ture/ false)값이 나온다. 끝에서 ture가 나와야한다. 스트림의 끝에 도달하지 않았으면 계속 돌려라
	{
		ss >> arr[i];
	}//배열의 초기화 부분

	print_arr(arr, size);
	*/

	/*
	typedef 키워드
	자료형을 새로 정의한다. -> 변수를 만들기 위해
	*/
	typedef int* IP; //정수 포인터(int*)를 IP라고 하겠다.
	int a = 5;
	IP ip = &a;

	/*enum 키워드
	열거형을 선언하고 열거형 변수를 생성한 다음 
	초기화하고 출력하여 확인해보세요.
	게임의 상태: IDEL, WALK, RUN, DIE
	
	enum Status
	{
		IDEL, WALK, RUN, DIE //0,1,2,3으로 정의되고 있다
	};
	//Satus game_state = WALK;
	//cout << "현재 게임 상태: " << game_state << endl;
	//혹은

	enum class Status
	{
		IDEL, WALK, RUN, DIE 
	};
	Status game_state = Status::WALK; //클래스로 정의했을 때 호출하는 법
	switch (game_state)
	{
	case Status::IDEL:
		break;
	case Status::WALK:
		break;
	case Status::RUN:
		break;
	}
	*/



	return 0;
}