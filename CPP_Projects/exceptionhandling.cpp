#include <iostream>

using namespace std;

int divide(int a, int b) throw(exception) //함수 선언문 뒤에 예외를 던질 수 있는 함수임을 표시해주는 것이 용이하다.
{
	if (b == 0) throw exception ("0으로 나누기 실패"); // return을 할 수 없고 프로그램을 멈출 필요가 있을 때 exception을 던지면 된다. (함수를 호출한 곳으로 던진다: 이경우 main함수에 잇음)
	return a / b;
}

int main()
{
	//예외처리(Exception Handling)
	//try catch 
	//장점: try에서 발생하는 에러를 표시할수 있고, catch에서 그 에러의 원인을 불러올 수 있다. 즉, 어디서 무슨 에러가 났는지 알 수 있게 설계할 수 있다는 장점.
	//프로그램의 비정상 종료를 방지 할 수 있다.

	
	try {
		cout << "나눗셈 결과: " << divide(6, 0) << endl;
	} //이걸 해보고 만약 exception이 발생하면 아래 catch에서 받아준다.
	catch (exception& e) {
		cerr << e.what() << endl;
	}

	/*
	키보드에서 두 수를 받아서 나눗셈을 하고 그 결과식을 출력해보세요.
	

	int a;
	int b;
	int res = 0;

	
	try {
		if (b == 0)
		{
			throw exception("산술오류(0으로 나누기 실패)"); //exception은 이미 있는 객체. exception 객체를 함수를 호출한 곳으로 던져진다. //에러의 원인을 적어준다
		} //일종의 예외 처리
		res = a / b; //a / b했을 때 b가 0이면 비정상 종료되어버린다.
	} //try 블럭에서 던져주면 catch에서 잡는다.
	catch (exception& e) { //throw에서 던져준 것을 잡으면 아래 블럭이 실행된다.
		cerr << "0으로 수를 나눌 수 없습니다" << endl;
		cerr << e.what() << endl; //exception개체가 만들어졌다면 객체이름.what()으로 나타낼 수 있다. what = 에러가 뭐야? //에러의 원인을 불러올 수 있다.
		return 1; //아래 로직이 돌아가면 안되니까 함수를 끝내라는 의미. (다른 상황에선 없을 수도 있다)
	}

	cout << a << "/" << b << " = " << res << endl;
	
	//혹은
	
	while (true) {
		cout << "두 수를 입력하세요: " << endl;
		cin >> a >> b;
		try {
			if (b == 0)
			{
				throw exception("산술오류(0으로 나누기 실패)");
			}
			res = a / b;
			cout << a << "/" << b << " = " << res << endl;
			break;
		}
		catch (exception& e) {
			cerr << "0으로 수를 나눌 수 없습니다. 다시 입력하세요." << endl;
			cerr << e.what() << endl;
		}
	}

		//try에서 에러를 검사하고 처리했으니 return 1;이 필요없다.
*/

	cout << "프로그램 종료..." << endl; //try에서 에러를 처리하고 식까지 처리했으니 마지막에는 프로그램을 정상 종료할 수 있다.

	return 0;
}