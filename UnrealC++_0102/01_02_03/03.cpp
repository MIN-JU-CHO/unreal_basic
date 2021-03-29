#include<iostream>
/*Template keyword
�����ε����� ����*/



template <typename T>	//�Ϲ������� T ��
T Sum(T a, T b) {		//Template �Լ�
	return a + b;
}

template<typename T1, typename T2>
void Add(T1 a, T2 b) {	//�ٸ� �ڷ��� (���Ƶ� ��. ������ 2������)
	std::cout << a + b << std::endl;
}


template <typename T>	//�Ϲ������� T ��
						//Template Ŭ����
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
	
	Add(10.0f, 10.00f);	//�ٸ�(���Ƶ���) �ڷ��� ���� �� ����


	//AA aa; error
	//int * Paa = &num; error
	//�� �� �����Ƿ� *****�����ϱ�. Template �ͼ�������
	//Template�� ���� Ŭ��������.
	AA<int> aa(10);	//	template ���� ������ �־������ <int>
	std::cout << aa.GetData() << std::endl;	//pointer �ƴϹǷ� .������
	
	AA<float> Faa(10.0f);	//float �ֱ� ����. 10������ �ڵ� casting
	std::cout << Faa.GetData() << std::endl;	//pointer �ƴϹǷ� .������
	
	AA<int>* Paa = new AA<int>(10);	//��ü �����ͷ� �־���	//default ������ �����Ƿ� (10)�ʼ�
	std::cout << Paa->GetData() << std::endl;	//pointer �Ƿ� ->������
	
	return 0;
}