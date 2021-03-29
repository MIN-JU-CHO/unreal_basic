#include <iostream>

/*
* 오버라이딩 - virtual, override
*/

using namespace std;

class Player
{
private:
	int hp;

public:
	Player() : hp(100) {}
	~Player() {}

	void Demage(int attack)
	{
		hp -= attack;
	}

	void PrintHP()
	{
		cout << "플레이어 HP: " << hp << endl;
	}
};

class MonsterBase
{
protected:
	int attack;
	char* name;
	int classType;

public:
	MonsterBase() {}
	MonsterBase(const char* name, int attack, int classType)
	{
		int size = strlen(name) + 1; //"aaa" = 3개 + 1
		this->name = new char[size]; //"aaa "
		strcpy_s(this->name, size, name);

		this->attack = attack;
		this->classType = classType;
	}

	~MonsterBase() {}

	virtual void Run() {}
	virtual void Attack(Player* const player)
	{
		player->Demage(attack);
	}

	int GetType()
	{
		return classType;
	}
};

class Marin : public MonsterBase
{
public:
	Marin() : MonsterBase("마린", 10, 0) {}

	void Run() override
	{
		cout << "마린 이동 " << endl;
	}

	void Attack(Player* player) override
	{
		MonsterBase::Attack(player);
		cout << "마린 공격 - " << attack << endl;
	}

	void PrintMarin()
	{
		cout << "PrintMarin()" << endl;
	}
};

class Tank : public MonsterBase
{
public:
	Tank() : MonsterBase("탱크", 25, 1) {}

	void Run() override
	{
		cout << "탱크 이동 " << endl;
	}

	void Attack(Player* player) override
	{
		MonsterBase::Attack(player);
		cout << "탱크 공격 - " << attack << endl;
	}
};

int main()
{
	const int ARRAY_NUM = 5;
	MonsterBase* arrMonsterBase[ARRAY_NUM];

	Player player;

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		arrMonsterBase[in] = nullptr;
	}

	arrMonsterBase[0] = new Marin();
	arrMonsterBase[1] = new Tank();
	arrMonsterBase[2] = new Tank();
	arrMonsterBase[3] = new Tank();
	arrMonsterBase[4] = new Marin();

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		if (arrMonsterBase[in] != nullptr)
		{
			arrMonsterBase[in]->Run();
			arrMonsterBase[in]->Attack(&player);
			player.PrintHP();
		}
	}

	MonsterBase* marin2 = new Marin();
	//marin2->PrintMarin(); //에러가 발생 반드시 형변환하면 멤버함수 호출 가능..
	((Marin*)marin2)->PrintMarin();
	static_cast<Marin*>(marin2)->PrintMarin();
	dynamic_cast<Marin*>(marin2)->PrintMarin();

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		delete arrMonsterBase[in];
	}

	return 0;
}