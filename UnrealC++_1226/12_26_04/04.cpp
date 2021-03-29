#include <iostream>

/*
(�������̵�) override  Ŭ�������� ����� �ݵ�� �����ؾ���.
virtual (������ �Լ�)
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

class Monster {
private:
	int attack;
	char* name;	//string
public:
	Monster() {}

	Monster(const char* name, int attack) {	//���� ������ �ʰԲ�. �̸��� ���ݷ�
		int size = strlen(name) + 1;	///"aaa"=3�� +1 (NULL)
		this->name = new char[size];	///"aaa " 4���� ����=�ش� string �޸� ���� Ȯ��(array) **��ü**
		strcpy_s(this->name, size, name);	//"aaa " Ȯ���� �޸� ������ ������ ����
		this->attack = attack;	//���ݷ� ����
								//==(*this).attack = attack;

	}

	~Monster() {	//�Ҹ���
		delete[] name;	//array delete	//�޸� ���� Ȯ���ߴ� �� �ݵ�� ��������� �� **��ü**
	}

	void Attack(Player *const player)	//player�� ��������(�ּ�)�� ��ȣ��
										//������ �� �Ҹ��ڰ� �ƴ� ���� �޼ҵ��̹Ƿ� return�� ��� �ʿ�!!
	{
		cout << name << " attacks: " << attack << endl;;	//���� �̸��� �󸶳� �����ߴ��� ���
		player->Damage(attack);	//���� ���� (player class���� ���ǵ� �޼ҵ� ���)
	}

};

int main(void) {
	const int ARRAY_NUM = 5;
	Player player;	//player ��ü ����
	Monster* arrMon[ARRAY_NUM];	//���� 5���� ���� ����(���� ����X)

	const char* MonsterName[] = { "111", "222", "333", "444", "555", "666" };	//���� �̸� �̸� �迭�� ����

																				//								10		34	65	31	1 105

	player.PrintHP();	//ó�� player ü��:100

	for (int i = 0; i < ARRAY_NUM; i++) {
		arrMon[i] = new Monster(MonsterName[i], (i + 1) * 5);	//���� **��ü** ����, 5�� ����� ���ݷ� ����
	}


	arrMon[0]->Attack(&player);	//1�� ���� ����
	player.PrintHP();	//ü�� ����
	arrMon[1]->Attack(&player);	//2�� ���� ����
	player.PrintHP();	//ü�� ����


	for (int i = 0; i < ARRAY_NUM; i++) {
		delete arrMon[i];	//array delete	//�޸� ����(���� **��ü**) Ȯ���ߴ� �� �ݵ�� ��������� ��
	}


	return 0;
}