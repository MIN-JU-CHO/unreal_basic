#include <iostream>
/*
Base Super Class - 부모 클래스 상속
*/
using namespace std;

class Base {
	protected:	//public:, private:		//자식이 사용 가능
		int num;
public:
	Base(int a) :num(a) {
		cout << "base 생성자" << endl;
	}
	~Base() { //소멸자는 아무것도 없다
		cout << "base 소멸자" << endl;

	}
	void PrintBase() {
		cout << "PrintBase()" << endl;
	}
};

class AA : public Base {	//거의 항상 public으로 Base를 상속받는다
public:
		//using namespace Base::
	AA(int b) : Base(b) {	//Base에 default 생성자가 없으므로 반드시 써줘야함	//Base::Base(b) 외부에 이렇게 쓰기도 한다
		//Base::Base(b); 내부에 이렇게 쓰기도 한다	//하지만 실제로는 소멸까지 먼저 하므로 문제가 생김!! (함수 단위로 되는거.)
		cout << "AA 생성자" << endl;

	}
	~AA() {	//소멸자는 아무것도 없다

		cout << "AA 소멸자" << endl;

	}

	void Print() {
		//Base::PrintBase();
		cout << "num: " << num << endl;	//protected 였으므로 상속받을 수 있음
	}
	
	static void Sprint() {

	}
};

int main(void) {

	AA::Sprint();	//static이므로 자유롭게 사용 가능

	AA* aa;		//공간 생성
	aa = new AA(10);	//객체 생성

	aa->Print();
	aa->PrintBase();

	delete aa;	//안할경우 base와 aa 둘다 소멸 안함.
	return 0;
}