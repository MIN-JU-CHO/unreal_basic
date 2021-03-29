#include "AAA.h"
//#include <iostream>	//이미 헤더파일에 있음.

//class 내용 서술

AAA::AAA()
{
	num = 100;
}

void AAA::Print()
{
	std::cout << "Num: " << num << std::endl;
}

//직접 만들거나 h에서 Alt+Enter