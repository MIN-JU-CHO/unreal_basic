#include <iostream>
/*
Base Super Class - �θ� Ŭ���� ���
*/
using namespace std;

class Base {
	protected:	//public:, private:		//�ڽ��� ��� ����
		int num;
public:
	Base(int a) :num(a) {
		cout << "base ������" << endl;
	}
	~Base() { //�Ҹ��ڴ� �ƹ��͵� ����
		cout << "base �Ҹ���" << endl;

	}
	void PrintBase() {
		cout << "PrintBase()" << endl;
	}
};

class AA : public Base {	//���� �׻� public���� Base�� ��ӹ޴´�
public:
		//using namespace Base::
	AA(int b) : Base(b) {	//Base�� default �����ڰ� �����Ƿ� �ݵ�� �������	//Base::Base(b) �ܺο� �̷��� ���⵵ �Ѵ�
		//Base::Base(b); ���ο� �̷��� ���⵵ �Ѵ�	//������ �����δ� �Ҹ���� ���� �ϹǷ� ������ ����!! (�Լ� ������ �Ǵ°�.)
		cout << "AA ������" << endl;

	}
	~AA() {	//�Ҹ��ڴ� �ƹ��͵� ����

		cout << "AA �Ҹ���" << endl;

	}

	void Print() {
		//Base::PrintBase();
		cout << "num: " << num << endl;	//protected �����Ƿ� ��ӹ��� �� ����
	}
	
	static void Sprint() {

	}
};

int main(void) {

	AA::Sprint();	//static�̹Ƿ� �����Ӱ� ��� ����

	AA* aa;		//���� ����
	aa = new AA(10);	//��ü ����

	aa->Print();
	aa->PrintBase();

	delete aa;	//���Ұ�� base�� aa �Ѵ� �Ҹ� ����.
	return 0;
}