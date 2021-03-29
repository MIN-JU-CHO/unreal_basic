#pragma once	//include <AAA.h> 중복되지 않게끔
#include <iostream>

//class 내용 요약. 선언부
class AAA {
private:	
	int num;
public:
	AAA() /*:num(100) {}*/;	//주석: 이렇게 해도 됨

	void Print();	//F12, Alt+F12로 이동 및 수정 가능
};