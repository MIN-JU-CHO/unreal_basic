#include<iostream>
/*Template keyword
오버로딩에서 시작*/



template <typename T>	//일반적으로 T 씀
T Sum(T a, T b) {		//Template 함수
	return a + b;
}

template<typename T1, typename T2>
void Add(T1 a, T2 b) {	//다른 자료형 (같아도 됨. 가능한 2개까지)
	std::cout << a + b << std::endl;
}


template <typename T>	//일반적으로 T 씀
						//Template 클래스
class AA {
private:
	T num;
public:
	AA(T a) : num(a) {}//num = a;
	T GetData() const {
		return num;
	}
};

/*int Sum(int a, int b) {
	return a + b;
}
float Sum(float a, float b) {
	return a + b;
}
double Sum(double a, double b) {
	return a + b;
}*/

int main(void) {

	std::cout << Sum(10, 100) << std::endl;		//int
	std::cout << Sum(10.0f, 100.0f) << std::endl;	//float
	std::cout << Sum(10.00, 100.00) << std::endl;	//double
	
	Add(10.0f, 10.00f);	//다른(같아도됨) 자료형 넣을 수 있음


	//AA aa; error
	//int * Paa = &num; error
	//쓸 때 낯서므로 *****주의하기. Template 익숙해지기
	//Template로 만든 클래스구나.
	AA<int> aa(10);	//	template 사용시 무조건 넣어줘야함 <int>
	std::cout << aa.GetData() << std::endl;	//pointer 아니므로 .연산자
	
	AA<float> Faa(10.0f);	//float 넣기 가능. 10넣으면 자동 casting
	std::cout << Faa.GetData() << std::endl;	//pointer 아니므로 .연산자
	
	AA<int>* Paa = new AA<int>(10);	//객체 포인터로 넣어줌	//default 생성자 없으므로 (10)필수
	std::cout << Paa->GetData() << std::endl;	//pointer 므로 ->연산자
	
	return 0;
}