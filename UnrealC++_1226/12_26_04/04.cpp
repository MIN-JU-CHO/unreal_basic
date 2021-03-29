#include <iostream>

/*
(오버라이딩) override  클래스간의 상속이 반드시 존재해야함.
virtual (가상의 함수)
*/

using namespace std;

class Player {
private:
	int hp;
public:
	Player() : hp(100) {}	//생성자 - 기본체력값 100으로
	~Player() {}	//소멸자

	void Damage(int attack) {	//데미지 입었을 때 체력 깎임
		hp -= attack;
	}
	void PrintHP() {	//플레이어 현재 체력 출력
		cout << "플레이어 HP: " << hp << endl;
	}
};

class Monster {
private:
	int attack;
	char* name;	//string
public:
	Monster() {}

	Monster(const char* name, int attack) {	//글자 변하지 않게끔. 이름과 공격력
		int size = strlen(name) + 1;	///"aaa"=3개 +1 (NULL)
		this->name = new char[size];	///"aaa " 4개의 글자=해당 string 메모리 공간 확보(array) **객체**
		strcpy_s(this->name, size, name);	//"aaa " 확보한 메모리 공간에 데이터 복사
		this->attack = attack;	//공격력 설정
								//==(*this).attack = attack;

	}

	~Monster() {	//소멸자
		delete[] name;	//array delete	//메모리 공간 확보했던 것 반드시 삭제해줘야 함 **객체**
	}

	void Attack(Player *const player)	//player가 누구인지(주소)는 보호됨
										//생성자 및 소멸자가 아닌 임의 메소드이므로 return형 명시 필요!!
	{
		cout << name << " attacks: " << attack << endl;;	//몬스터 이름이 얼마나 공격했는지 출력
		player->Damage(attack);	//실제 공격 (player class에서 정의된 메소드 사용)
	}

};

int main(void) {
	const int ARRAY_NUM = 5;
	Player player;	//player 객체 생성
	Monster* arrMon[ARRAY_NUM];	//몬스터 5마리 공간 생성(실제 생성X)

	const char* MonsterName[] = { "111", "222", "333", "444", "555", "666" };	//몬스터 이름 미리 배열로 설정

																				//								10		34	65	31	1 105

	player.PrintHP();	//처음 player 체력:100

	for (int i = 0; i < ARRAY_NUM; i++) {
		arrMon[i] = new Monster(MonsterName[i], (i + 1) * 5);	//몬스터 **객체** 생성, 5의 배수씩 공격력 설정
	}


	arrMon[0]->Attack(&player);	//1번 몬스터 공격
	player.PrintHP();	//체력 보기
	arrMon[1]->Attack(&player);	//2번 몬스터 공격
	player.PrintHP();	//체력 보기


	for (int i = 0; i < ARRAY_NUM; i++) {
		delete arrMon[i];	//array delete	//메모리 공간(몬스터 **객체**) 확보했던 것 반드시 삭제해줘야 함
	}


	return 0;
}