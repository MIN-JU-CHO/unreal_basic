#include <iostream>

/*
new delete 항상 같이 다녀야 한다
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

class MonsterBase {

protected:
	int attack;
	char* name;	//string
	int classType;


public:
	MonsterBase(const char* name, int attack, int classType) {	//글자 변하지 않게끔. 이름과 공격력
		int size = strlen(name) + 1;	///"aaa"=3개 +1 (NULL)
		this->name = new char[size];	///"aaa " 4개의 글자=해당 string 메모리 공간 확보(array) **객체**
		strcpy_s(this->name, size, name);	//"aaa " 확보한 메모리 공간에 데이터 복사
		this->attack = attack;	//공격력 설정
								//==(*this).attack = attack;
		this->classType = classType;
	}
	~MonsterBase() {
	}

	virtual void Run() {
	}
	virtual void Attack(Player* const player)	//player가 누구인지(주소)는 보호됨
												//생성자 및 소멸자가 아닌 임의 메소드이므로 return형 명시 필요!!
	{
		cout << name << " attacks: " << attack << endl;;	//몬스터 이름이 얼마나 공격했는지 출력
		player->Damage(attack);	//실제 공격 (player class에서 정의된 메소드 사용)
	}
};
class Marin : public MonsterBase {	//MonsterBase 상속 받음
public:
	Marin() :MonsterBase("마린", 100, 0) {}	//default 생성자
	void Run() override {		//Run overriding
		cout << "마린 이동 " << endl;
	}
	void Attack(Player* player) override {		//Attack overriding
		MonsterBase::Attack(player);		//MonsterBase의 Attack 메소드 사용
		cout << "마린 공격 - " << attack << endl;
	}
	void PrintMarin() {
		cout << "PrintMarin()" << endl;		//test용 메소드
	}
};

class Tank : public MonsterBase {
public:
	Tank() :MonsterBase("탱크", 25, 1) {}		//default 생성자
	void Run() override {		//Run overriding
		cout << "탱크 이동 " << endl;
	}
	void Attack(Player* player) override {		//Attack overriding
		MonsterBase::Attack(player);		//MonsterBase의 Attack 메소드 사용
		cout << "탱크 공격 - " << attack << endl;
	}
};

void Print(MonsterBase* base) {	//*넣는 이유: 너무 무거우니까 포인터 사용하기 ^^
	if (dynamic_cast<Marin*>(base) != nullptr) {
		cout << "Marin 객체" << endl;
	}
	else if (dynamic_cast<Tank*>(base) != nullptr) {
		cout << "Tank 객체" << endl;
	}
}

int main(void) {
	const int ARRAY_NUM = 5;		//상수 5
	MonsterBase* arrMonsterBase[ARRAY_NUM];	//MonsterBase 기반 배열 공간 생성

	Player player;	//player 생성(default:100)

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		arrMonsterBase[in] = nullptr;		//배열 원소 초기화
	}

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		Print(arrMonsterBase[in]);
	}

	return 0;
}