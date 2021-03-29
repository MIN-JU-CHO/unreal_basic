#include<iostream>

/*
inline int Add(int a) 자료형 있을 때
#define ADD(a)((a) + (a)) 자료형 필요X
*/


//**괄호** 습관적으로 많이 쓰기
#define Plus(a)((a)+(a))	//template과 비슷하게 함수정의


inline int Add(int a) {
	return a + a;
}	//inline define 최대한 간략하게. 자주 사용되는 것만.


using namespace std;
int main(void) {
	cout << Plus(10) << endl;
	cout << Plus(10.00f) << endl;


	cout << Add(10) << endl;
	cout << Add(10.00f) << endl;
	return 0;
}