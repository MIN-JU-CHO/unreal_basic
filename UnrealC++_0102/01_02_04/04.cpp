#include<iostream>

/*
inline int Add(int a) �ڷ��� ���� ��
#define ADD(a)((a) + (a)) �ڷ��� �ʿ�X
*/


//**��ȣ** ���������� ���� ����
#define Plus(a)((a)+(a))	//template�� ����ϰ� �Լ�����


inline int Add(int a) {
	return a + a;
}	//inline define �ִ��� �����ϰ�. ���� ���Ǵ� �͸�.


using namespace std;
int main(void) {
	cout << Plus(10) << endl;
	cout << Plus(10.00f) << endl;


	cout << Add(10) << endl;
	cout << Add(10.00f) << endl;
	return 0;
}