#include <iostream>
/*
생성자 (함수), 소멸자 (함수)
*/



class AA {
private:
	int num;
public:
	AA() {	//void return 형 필요 없다
		std::cout << "AA 생성자" << std::endl;
	}

	AA(int num) :num(num) {
		//it means this->num = num;
		std::cout << "AA 생성자: " << this->num << std::endl;

	}
	AA(int a, int b) :num(a + b) {
		//it means this->num = a+b;
		Print();
	}

	~AA() {	//void return 형 필요 없다
		std::cout << "AA 소멸자" << std::endl;
	}

	void Print()
	{
		std::cout << "this->num: " << this->num << std::endl;
	}
};

int main(void) {

	AA aa;	//생성과 동시에 소멸
	AA aaa(10);	//생성과 동시에 소멸
	AA aaaa(1,2);	//생성과 동시에 소멸
	
	return 0;
}