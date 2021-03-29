#include <iostream>
/*
������ (�Լ�), �Ҹ��� (�Լ�)
*/



class AA {
private:
	int num;
public:
	AA() {	//void return �� �ʿ� ����
		std::cout << "AA ������" << std::endl;
	}

	AA(int num) :num(num) {
		//it means this->num = num;
		std::cout << "AA ������: " << this->num << std::endl;

	}
	AA(int a, int b) :num(a + b) {
		//it means this->num = a+b;
		Print();
	}

	~AA() {	//void return �� �ʿ� ����
		std::cout << "AA �Ҹ���" << std::endl;
	}

	void Print()
	{
		std::cout << "this->num: " << this->num << std::endl;
	}
};

int main(void) {

	AA aa;	//������ ���ÿ� �Ҹ�
	AA aaa(10);	//������ ���ÿ� �Ҹ�
	AA aaaa(1,2);	//������ ���ÿ� �Ҹ�
	
	return 0;
}