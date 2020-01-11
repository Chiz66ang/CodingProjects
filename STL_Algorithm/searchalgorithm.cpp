#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Member
{
	int num;
	string name;
	Member() {}
	Member(int num, string name) : num(num), name(name) {}

	void print()
	{
		cout << num << "\t" << name << endl;
	}

};

int main()
{
	//검색 알고리즘 (순차검색, 이진검색)
	//순차검색: 배열의 첫 원소부터, 마지막 원소까지 비교검색하는 방법
	//이진검색: 정렬된 배열을 대상으로 절반씩 나누어 검색 (성능면에서 더 좋음)

	/*Member 객체 (번호, 이름)를 5개 저장한 배열을 준비.
	//회원의 번호를 순차적으로 검색하여 검색된 회원의 정보를 표시
	//검색이 된 경우, 루프를 즉시 벗어난다. 

	Member mem[5];
	mem[0] = { 1, "지수" };
	mem[1] = { 2, "순용" };
	mem[2] = { 3, "빵주" };
	mem[3] = { 4, "도현" };
	mem[4] = { 5, "기원" };

	for (int i = 0; i < 5; i++) //순차 검색 (뒷쪽에 있는 데이터를 검색할 때는 시간이 오래 걸리겠지)
	{
		if (mem[i].num = 3)
		{
			mem[i].print();
			break;
		}
	}

	//이진 검색
	//정렬 된 데이터의 중간 값 구하기. (맨끝방 번호 - 맨첫방 번호)/2 + 맨첫방 번호
	아래 예제 참고
	*/

	/*
		Member 객체를 20개 생성할 때 번호, 이름은 중복되지 않도록 지정하고
		생성된 후에는 번호로 정렬하여 이진검색을 실행한다.
		번호는 11~30까지 지정하고 이름은 무작위수를 구하여 알파벳으로 변경하여 사용한다.
		(atoi, itoa 사용)
		char c = 65;
		cout << c << endl; 이렇게 해도 된다
	*/
	//중복되지 않은 값 지정
	Member mem[20];
	srand(time(0));
	int i = 0;
	int rd = 0;

	outer_loop:
	while (i < 20) //for(int i =0; i <20; i++)
	{
		rd = rand()% 20 + 11;
			for (int j = 0; j <= i; j++)
			{
			if (mem[j].num == rd)
				goto outer_loop;
			}
		mem[i++].num = rd;
		//c = rd + 54; //아스키 코드는 65 -91까지 (대문자 기준)
		//mem[i++].name = c;
	}

	outer_loop2:
	for (int idx = 0; idx < 20;)
	{
		string _name;
		_name += (char)(rand() % 26 + 65);

		for (int j = 0; j < idx; j++)
		{
		if (mem[j].name == _name)
			goto outer_loop2;
		}
		mem[idx++].name = _name;
	}
	
	
	//번호순 정렬
	Member mp;
	for (int i = 1; i < sizeof(mem) / sizeof(Member); i++) 
	{
		int temp = mem[i].num; 
		Member mp = mem[i];
		int idx = i; 
		for (int j = i - 1; mem[j].num > temp && j >= 0; j--)
		{
			mem[idx--] = mem[j]; 
			mem[j] = mp;
		}
	}


	for (int i = 0; i < 20; i++)
	{
		mem[i].print();
	}
	
	//이진 검색
	int mid = 0;
	int begin = 0;
	int end = (sizeof(mem) / sizeof(Member)-1);
	int target = 27;

	bool found = false;

	
	while (begin <= end) //절반씩 나누면 시작과 끝이 같아진다. //while (1)로 해도 된당.
	{
		mid = (end - begin) / 2 + begin;
		if (mem[mid].num == target)
		{
			cout << target << "의 위치: " << mid << endl;
			mem[mid].print();
			found = true;
			break;
		}
		else if (mem[mid].num > target)
		{
			end = (mid - 1);
		}
		else if (mem[mid].num < target)
		{
			begin = (mid + 1);
		}
	}

	return 0;
}