/*
�и�������
*/
#include<iostream>
#include "AAA.h"

//#include ""

int main(void) {
	AAA aaa;
	aaa.Print();		//.


	AAA* aaaRef = new AAA();	//��ü(������)
	aaaRef->Print();	//->
	delete aaaRef;		//����

	return 0;
}