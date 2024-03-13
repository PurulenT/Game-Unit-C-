#include <iostream>
using namespace std;

enum Type {Elf, Human, Goblin, Orc, Gnome};

class Unit {
private:
	float HP;
public:
	Type type;
	int age = 0;
	int level = 0;
	string name;
	int passedKM = 0;

	Unit(Type type)
	{
		this->type = type;
		if (!type == Type::Orc)
		{
			this->HP = 100;
		}
		else
		{
			this->HP = 90;
		}
	}
	Unit(Type type, int age)
	{
		this->type = type;
		this->age = age;
	}
	void Hit()
	{
		int randHPloose = rand() % 10 + 1;
		this->HP = this->HP - randHPloose;
		if (this->HP <= 0)
		{
			this->age = 0;
			this->HP = 0;
			this->level = 0;
			this->passedKM = 0;
		}
	}

	bool isAlive()
	{
		if (this->HP <= 0)
		{
			return false;
		}
		return true;
	}

	void Go(int meters)
	{
		int result = meters / 1000000;
		if (result > 0)
		{
			for (int i = 0; i < result; i++)
			{
				this->level++;
			}
		}
	}

	void printInfo()
	{
		cout << "Type: " << this->type << endl
			<< "HP: " << this->HP << endl
			<< "Age: " << this->age << endl
			<< "Level: " << this->level << endl
			<< "Name: " << this->name << endl
			<< "Passed: " << this->passedKM << endl;
	}

};

int main()
{
	srand(time(0));
	Unit unit(Type::Orc);
	unit.printInfo();
	return 0;
}