#include <iostream>

void Print(const int *refNum)				//CONST INT
{
	//*refNum = 100;	//error (READONLY)
	std::cout << *refNum << std::endl;
}

void Print2(int *const refNum)				//CONST *
{
	int num = 100;
	*refNum = 100;
	std::cout << *refNum << std::endl;
	//refNum = &num;	//error (READONLY)
}

void Print3(const int *const refNum)		//CONST INT CONST *
{
	int num = 100;
	//*refNum = 100;	//error (READONLY)
	std::cout << *refNum << std::endl;
	//refNum = &num;	//error (READONLY)
}

int main(void) {

	int num = 100;
	int num2 = 200;
	int num3 = 300;

	const int * refNum = &num;				//CONST INT
	//*refNum = 100;	//error
	Print(&num);		//100

	int *const refNum2 = &num;				//CONST *
	//refNum2 = &num2;	//error
	*refNum2 = 1000;
	Print(&num);		//1000
	Print2(&num);		//100
	Print2(&num2);		//100
	

	const int *const refNum3 = &num3;		//CONST INT CONST *
	//*refNum3 = 100;	//error
	//refNum3 = &num3;	//error
	Print3(&num3);		//300
	return 0;
}