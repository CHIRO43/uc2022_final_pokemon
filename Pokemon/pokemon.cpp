#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<time.h>

using namespace std;

int user_score = 0, cpu_score = 0;

void pok_assign(void);
void pok_display(void);
void pok_display(int);
void  play(int);

class POK
{
private:
	int power;
	float health;
	int speed;
	int defence;
	int offence;
	char name[10];

public:
	int pow() { return power; }
	float hlt() { return health; }
	int spd() { return speed; }
	int def() { return defence; }
	int off() { return offence; }
	char* getname() { return name; };
	void special(int);
	void attack(int);
	void defend(int);
	void agility(int);

	POK() {}

	POK(int p, float h, int s, int d, int o, char n[10])
	{
		power = p;
		health = h;
		speed = s;
		defence = d;
		offence = o;
		strcpy(name, n);
	}

};

char a[12][12] = { "�����","��ī��","����Ĵ�","�źϿ�","��������","���ڸ�",
	"������","������","�ĵ� ","���Ӹ�","������","����Ǫ��" };

POK Voltorb(4, 60, 5, 4, 3, a[0]), Pikachu(7, 80, 6, 5, 8, a[1]);
POK Psyduck(3, 50, 4, 7, 5, a[2]), Blastoise(8, 90, 5, 8, 7, a[3]);
POK Ninetales(7, 70, 8, 5, 6, a[4]), Charizard(9, 80, 4, 7, 9, a[5]);
POK Butterfee(6, 50, 8, 3, 6, a[6]), Spearow(8, 70, 9, 4, 7, a[7]);
POK Alakazam(7, 80, 4, 5, 9, a[8]), MrMime(8, 70, 4, 9, 7, a[9]);
POK Golem(7, 90, 3, 8, 7, a[10]), Kabutops(9, 70, 6, 9, 8, a[11]);

class player
{
public:
	POK pokemon[3];

}cpu, user;

void POK::special(int pok)
{
	//randomize();
	int ch = rand() % 4;
	switch (ch)
	{
	case 0:	health *= 2;
		cout << "\nü�� 2��!";
		break;
	case 1: speed *= power;
		cout << "\n��ø ����!";
		break;
	case 2: defence *= power;
		cout << "\n��� ����!";
		break;
	case 3: offence *= power;
		cout << "\n���� ����!";
		break;
	}
	power = 0;
	pok_display(pok);

}

void POK::attack(int pok)
{
	//randomize();
	int ch = rand() % 4, cpu_val, user_val;
	user_val = user.pokemon[pok].off();
	switch (ch)
	{
	case 0: cout << "\n���� ��ø�� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].spd();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n���� �� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].def();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n���� ������ �����ߴ�!";
		cpu_val = cpu.pokemon[pok].off();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 20;
		else if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 20;
		else if (cpu_val > user_val)
			user.pokemon[pok].health -= 10;
		else if (user_val > cpu_val)
			cpu.pokemon[pok].health -= 10;
		break;
	case 3: cout << "\n���� ��ȭ�� �����ߴ�!";
		cpu.pokemon[pok].special(pok);
		break;
	}
}

void POK::defend(int pok)
{
	//randomize();
	int ch = rand() % 4, cpu_val, user_val;
	user_val = user.pokemon[pok].def();
	switch (ch)
	{
	case 0: cout << "\n���� ��ø�� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].spd();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n���� ������ �����ߴ�!";
		cpu_val = cpu.pokemon[pok].off();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n���� �� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].def();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 20;
		else if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 20;
		else if (cpu_val > user_val)
			user.pokemon[pok].health -= 10;
		else if (user_val > cpu_val)
			cpu.pokemon[pok].health -= 10;
		break;
	case 3: cout << "\n���� ��ȭ�� �����ߴ�!";
		cpu.pokemon[pok].special(pok);
		break;
	}
}

void POK::agility(int pok)
{
	//randomize();
	int ch = rand() % 4, cpu_val, user_val;
	user_val = user.pokemon[pok].spd();
	switch (ch)
	{
	case 0: cout << "\n���� �� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].def();
		if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 10;
		else
			cpu.pokemon[pok].health -= 20;
		break;
	case 1: cout << "\n���� ������ �����ߴ�!";
		cpu_val = cpu.pokemon[pok].off();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 10;
		else
			user.pokemon[pok].health -= 20;
		break;
	case 2: cout << "\n���� ��ø�� �����ߴ�!";
		cpu_val = cpu.pokemon[pok].spd();
		if (user_val - cpu_val > 50)
			cpu.pokemon[pok].health -= 20;
		else if (cpu_val - user_val > 50)
			user.pokemon[pok].health -= 20;
		else if (cpu_val > user_val)
			user.pokemon[pok].health -= 10;
		else if (user_val > cpu_val)
			cpu.pokemon[pok].health -= 10;
		break;
	case 3: cout << "\n���� ��ȭ�� �����ߴ�!";
		cpu.pokemon[pok].special(pok);
		break;
	}
}

int main()
{
	int pok, num;
	int ber;
	cout << "\t********* *****   * *  *******      *      *****    *" << endl;
	cout << "\t  *   *       *   * *  *     *     * *     *        *" << endl;
	cout << "\t  *   *   ***** *** *  *******    *   *    *        *" << endl;
	cout << "\t*********    *    * *     *      *     *   *        *" << endl;
	cout << "\t    *       *  ** * *  *******  *       *  *****  ***    " << endl;
	cout << "\t    *         *  *     *                   *        *" << endl;
	cout << "\t    *        *    *    *                   *        *" << endl;
	cout << "\t    *       *      *   *                   *        *" << endl;
	cout << "\t*********  *        *  ******* *********** *****    *" << endl;
	cout << "---------------------------------------------------------------------" << endl;

	while (true) {
		cout << "1) �ο��  2) ����  3) ���ϸ�  4) �������� :";
		cin >> num;

		if (num == 1) {
		restart:
			//	clrscr();
			pok_assign();
			for (int i = 0; i < 3; ++i)
			{
				cout << "\n______________________________________________";
				pok_display();
				do {
					cout << "\n\n���ϸ��� ���� ���ּ���.(1-3): ";
					cin >> pok;
					if (!pok)
						return 0;
					if (pok == 10101)
						goto restart;
				} while (pok > 3 || pok < 0);
				play(--pok);
			}
			cout << "\n\t\t____________________________________________\n";
			if (user_score > cpu_score)
				cout << "\t\t**********!!!�̰���ϴ�!!!**********";
			else
				cout << "\t\t**********!!!���濡�� �����ϴ�!!!**********";
			cout << "\n\t\t____________________________________________\n";
			//!	getch();
			return 0;
		}
		else if (num == 2) { exit; }
		else if (num == 3) {
			for (int i = 0; i < 6; ++i) {
				cout << "\n" << i + 1 << ") " << a[i];
			}
			cout << endl << endl;
		}


		if (num == 4) {
			cout << "����ĥ �� �����ϴ�. ���� �Ͻðڽ��ϱ�?" << endl;
			cout << "1. �ο�� 2. �����Ѵ� : ";

			cin >> ber;
			if (ber == 1) {
				goto restart;
			}
			else if (ber == 2)
			{
				return 0;
			}
		}
	}
}

void play(int pok)
{
	int choice;
	cout << "\n���� ���ϸ� : " << user.pokemon[pok].getname();
	cout << "\n��� ���ϸ�: " << cpu.pokemon[pok].getname() << endl;
	while ((user.pokemon[pok].hlt() > 0) && (cpu.pokemon[pok].hlt() > 0))
	{
		do {
			cout << "_____________________________________________";
			cout << "\n�����ϼ���: ";
			cout << "\n1.) ��ø: " << user.pokemon[pok].spd()
				<< "\t\t2.) ����:  " << user.pokemon[pok].off()
				<< "\n3.) ���: " << user.pokemon[pok].def()
				<< "\t\t4.) ��ȭ: " << user.pokemon[pok].pow();
			cout << "\n\n�����ϼ���: ";
			cin >> choice;
		} while (choice < 0 || choice>4);

		switch (choice)
		{
		case 0:exit(0);
		case 1:user.pokemon[pok].agility(pok);	break;
		case 2:user.pokemon[pok].attack(pok);	break;
		case 3:user.pokemon[pok].defend(pok);	break;
		case 4:user.pokemon[pok].special(pok);	break;
		}

		cout << "\n\n���� ���ϸ�: " << user.pokemon[pok].getname()
			<< "\tü��: " << user.pokemon[pok].hlt();
		cout << "\n��� ���ϸ� : " << cpu.pokemon[pok].getname()
			<< "\tü��: " << cpu.pokemon[pok].hlt() << endl;
	}

	if (user.pokemon[pok].hlt() > cpu.pokemon[pok].hlt())
	{
		user_score++;
		cout << "\n\n**********************";
		cout << "\n* �̰��!! *\n";
		cout << "**********************\n\n";
	}
	else
	{
		cpu_score++;
		cout << "\n\n**********************";
		cout << "\n* �����ϴ�. *\n";
		cout << "**********************\n\n";
	}
}




void pok_assign()
{
	//randomize();
	int uval, cval;
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 3; ++i)
	{
		uval = rand() % 11;
		cval = rand() % 11;
		switch (uval)
		{
		case 0:user.pokemon[i] = Voltorb;	 break;
		case 1:user.pokemon[i] = Pikachu;	 break;
		case 2:user.pokemon[i] = Psyduck;	 break;
		case 3:user.pokemon[i] = Blastoise; break;
		case 4:user.pokemon[i] = Ninetales; break;
		case 5:user.pokemon[i] = Charizard; break;
		case 6:user.pokemon[i] = Butterfee; break;
		case 7:user.pokemon[i] = Spearow;	 break;
		case 8:user.pokemon[i] = Alakazam; break;
		case 9:user.pokemon[i] = MrMime;	 break;
		case 10:user.pokemon[i] = Golem;	 break;
		case 11:user.pokemon[i] = Kabutops; break;
		}
		switch (cval)
		{
		case 0:cpu.pokemon[i] = Voltorb;	 break;
		case 1:cpu.pokemon[i] = Pikachu;	 break;
		case 2:cpu.pokemon[i] = Psyduck;	 break;
		case 3:cpu.pokemon[i] = Blastoise; break;
		case 4:cpu.pokemon[i] = Ninetales; break;
		case 5:cpu.pokemon[i] = Charizard; break;
		case 6:cpu.pokemon[i] = Butterfee; break;
		case 7:cpu.pokemon[i] = Spearow;	 break;
		case 8:cpu.pokemon[i] = Alakazam;  break;
		case 9:cpu.pokemon[i] = MrMime;	 break;
		case 10:cpu.pokemon[i] = Golem;	 break;
		case 11:cpu.pokemon[i] = Kabutops; break;
		}
	}
}

void pok_display()
{
	cout << "\n\n���� ���ϸ�: \n";
	for (int i = 0; i < 3; ++i)
	{
		cout << "\n" << i + 1 << ") " << user.pokemon[i].getname();
		cout << "\n\t��ȭ\tü��\t��ø\t���\t����" << endl;
		cout << "\t" << user.pokemon[i].pow()
			<< "\t" << user.pokemon[i].hlt()
			<< "\t" << user.pokemon[i].spd()
			<< "\t" << user.pokemon[i].def()
			<< "\t" << user.pokemon[i].off();
	}
}

void pok_display(int i)
{

	cout << "\n_____________________________________________";
	cout << "\n���ϸ� �ɷ�:\n";

	cout << "\nUser: " << user.pokemon[i].getname();
	cout << "\n\t��ȭ\tü��\t��ø\t���\t����" << endl;
	cout << "\t" << user.pokemon[i].pow()
		<< "\t" << user.pokemon[i].hlt()
		<< "\t" << user.pokemon[i].spd()
		<< "\t" << user.pokemon[i].def()
		<< "\t" << user.pokemon[i].off();

	cout << "\nCPU : " << cpu.pokemon[i].getname();
	cout << "\n\t��ȭ\tü��\t��ø\t���\t����" << endl;
	cout << "\t" << cpu.pokemon[i].pow()
		<< "\t" << cpu.pokemon[i].hlt()
		<< "\t" << cpu.pokemon[i].spd()
		<< "\t" << cpu.pokemon[i].def()
		<< "\t" << cpu.pokemon[i].off();
}