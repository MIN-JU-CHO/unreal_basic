#include <iostream>

/*
new delete �׻� ���� �ٳ�� �Ѵ�
*/

using namespace std;

class Player {
private:
	int hp;
public:
	Player() : hp(100) {}	//������ - �⺻ü�°� 100����
	~Player() {}	//�Ҹ���

	void Damage(int attack) {	//������ �Ծ��� �� ü�� ���� 
		hp -= attack;
	}
	void PrintHP() {	//�÷��̾� ���� ü�� ���
		cout << "�÷��̾� HP: " << hp << endl;
	}
};

class MonsterBase {

protected:
	int attack;
	char* name;	//string
	int classType;


public:
	MonsterBase(const char* name, int attack, int classType) {	//���� ������ �ʰԲ�. �̸��� ���ݷ�
		int size = strlen(name) + 1;	///"aaa"=3�� +1 (NULL)
		this->name = new char[size];	///"aaa " 4���� ����=�ش� string �޸� ���� Ȯ��(array) **��ü**
		strcpy_s(this->name, size, name);	//"aaa " Ȯ���� �޸� ������ ������ ����
		this->attack = attack;	//���ݷ� ����
								//==(*this).attack = attack;
		this->classType = classType;
	}
	~MonsterBase() {
	}

	virtual void Run() {
	}
	virtual void Attack(Player *const player)	//player�� ��������(�ּ�)�� ��ȣ��
												//������ �� �Ҹ��ڰ� �ƴ� ���� �޼ҵ��̹Ƿ� return�� ��� �ʿ�!!
	{
		cout << name << " attacks: " << attack << endl;;	//���� �̸��� �󸶳� �����ߴ��� ���
		player->Damage(attack);	//���� ���� (player class���� ���ǵ� �޼ҵ� ���)
	}
};
class Marin : public MonsterBase {	//MonsterBase ��� ����
public:
	Marin() :MonsterBase("����", 100, 0) {}	//default ������
	void Run() override {		//Run overriding
		cout << "���� �̵� " << endl;
	}
	void Attack(Player* player) override {		//Attack overriding
		MonsterBase::Attack(player);		//MonsterBase�� Attack �޼ҵ� ���
		cout << "���� ���� - " << attack << endl;
	}
	void PrintMarin() {
		cout << "PrintMarin()" << endl;		//test�� �޼ҵ�
	}
};

class Tank : public MonsterBase {
public:
	Tank() :MonsterBase("��ũ", 25, 1) {}		//default ������
	void Run() override {		//Run overriding
		cout << "��ũ �̵� " << endl;
	}
	void Attack(Player* player) override {		//Attack overriding
		MonsterBase::Attack(player);		//MonsterBase�� Attack �޼ҵ� ���
		cout << "��ũ ���� - " << attack << endl;
	}
};



int main(void) {
	const int ARRAY_NUM = 5;		//��� 5
	MonsterBase* arrMonsterBase[ARRAY_NUM];	//MonsterBase ��� �迭 ���� ����

	Player player;	//player ����(default:100)

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		arrMonsterBase[in] = nullptr;		//�迭 ���� �ʱ�ȭ
	}

	arrMonsterBase[0] = new Marin();	//�迭 ���� **��** ��ü �ֱ�
	arrMonsterBase[1] = new Tank();
	arrMonsterBase[2] = new Tank();
	arrMonsterBase[3] = new Tank();
	arrMonsterBase[4] = new Marin();

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		if (arrMonsterBase[in] != nullptr)		//�ʱ�ȭ ���� �ƴ϶��
		{
			arrMonsterBase[in]->Run();		//�̵�(overriding �Լ�)
			arrMonsterBase[in]->Attack(&player);	//����(overriding �Լ�)
			player.PrintHP();		//Player HP �� ���� ���
		}
	}

	MonsterBase* marin2 = new Marin();		//MonsterBase ��� **��* ��ü ����
	//marin2->PrintMarin(); //������ �߻�. �ݵ�� ����ȯ�ϸ� ����Լ� ȣ�� ����..
	((Marin*)marin2)->PrintMarin();		//MonsterBase ��� * �̹Ƿ� Marin*�� ����ȯ �� Marin���� �޼ҵ�(override X) ���� ����.
	static_cast<Marin*>(marin2)->PrintMarin();	//��������ȯ
	dynamic_cast<Marin*>(marin2)->PrintMarin();	//��������ȯ

	for (int in = 0; in < ARRAY_NUM; in++)
	{
		delete arrMonsterBase[in];			//�迭 ���ҵ��� new -> delete �ʼ�
	}

	return 0;
}