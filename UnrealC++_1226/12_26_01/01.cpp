#include <iostream>

/*
함수 오버로딩(파라미터 개수, 함수 이름은 같고, 파라미터 자료형)
*/

using namespace std;

void Print() {
	cout << "Print()" << endl;
}

void Print(int num) {
	cout << "Print (int num): " << num << endl;
}

void Print(float fNum) {
	cout << "Print (float fNum): " << fNum << endl;
}

void Print(int num, int num1, int num2) {
	cout << "Print (int num): " << num << endl;
	cout << "Print (int num1): " << num1 << endl;
	cout << "Print (int num2): " << num2 << endl;
}

int main() {
	Print();
	Print(10);
	Print(10.0f);
	Print(10, 20, 30);
	return 0;
}
