/*
분리컴파일
*/
#include<iostream>
#include "AAA.h"

//#include ""

int main(void) {
	AAA aaa;
	aaa.Print();		//.


	AAA* aaaRef = new AAA();	//객체(포인터)
	aaaRef->Print();	//->
	delete aaaRef;		//삭제

	return 0;
}