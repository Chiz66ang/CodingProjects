#pragma once
#include <string>

using namespace std;

class Item
{
public:
	int num;
	string title;
	int power;
	int maxuse;
	int curuse;
	bool inuse;

	Item();
	Item(int name, string title, int power, int maxuse, int curuse); //헤더와 바디를 분리. Item의 초록 밑줄에 커서를 대서 링크를 누르고 생성자를 마저 정의를 해준다.
	//헤더 파일에는 클래스를 생성 (생성자 앞부분만)
	//소스 파일에는 헤더에서 만큰 클래스를 정의 (생성자 초기화)


};