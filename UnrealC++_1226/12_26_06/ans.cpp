#include <iostream>

/*
* �������̵� - virtual, override
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
		cout << "�÷��̾� HP: " << hp << endl;
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
		int size = strlen(name) + 1; //"aaa" = 3�� + 1
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
	Marin() : MonsterBase("����", 10, 0) {}

	void Run() override
	{
		cout << "���� �̵� " << endl;
	}

	void Attack(Player* player) override
	{
		MonsterBase::Attack(player);
		cout << "���� ���� - " << attack << endl;
	}

	void PrintMarin()
	{
		cout << "PrintMarin()" << endl;
	}
};

class Tank : public MonsterBase
{
public:
	Tank() : MonsterBase("��ũ", 25, 1) {}

	void Run() override
	{
		cout << "��ũ �̵� " << endl;
	}

	void Attack(Player* player) override
	{
		MonsterBase::Attack(player);
		cout << "��ũ ���� - " << attack << endl;
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
	//marin2->PrintMarin(); //������ �߻� �ݵ�� ����ȯ�ϸ� ����Լ� ȣ�� ����..
	((Marin*)marin2)->PrintMarin();
	static_cast<Marin*>(marin2)->PrintMarin();
	dynamic_cast<Marin*>(marin2)->PrintMarin();

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		delete arrMonsterBase[in];
	}

	return 0;
}