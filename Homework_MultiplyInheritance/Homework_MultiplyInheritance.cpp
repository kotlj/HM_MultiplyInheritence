
#include <iostream>

enum weaponType
{
	fist,
	sword,
	axe,
	dagger,
	hammer,
};

class Warrior
{
private:
	unsigned int HP;
	unsigned int DMG;
	weaponType weapon;
public:
	Warrior()
	{
		HP = 100;
		DMG = 20;
		weapon = weaponType(0);
	}
	Warrior(unsigned int _HP, unsigned int _DMG, weaponType _weapon)
	{
		HP = _HP;
		DMG = _DMG;
		weapon = _weapon;
	}

	void hit() const
	{
		std::cout << "Deal " << DMG << " with: weaponType(" << weapon << ")\n";
	}

	virtual ~Warrior() {}
};
class Wizard
{
private:
	unsigned int HP;
	unsigned int INT;
public:
	Wizard()
	{
		HP = 60;
		INT = 100;
	}
	Wizard(unsigned int _HP, unsigned int _INT)
	{
		HP = _HP;
		INT = _INT;
	}

	void luminos() const
	{
		std::cout << "Casted magic light with radius: " << INT << '\n';
	}

	virtual ~Wizard() {}
};
class Archer
{
private:
	unsigned int HP;
	unsigned int AGT;
	unsigned int arrows;
public:
	Archer()
	{
		HP = 80;
		AGT = 100;
		arrows = 10;
	}
	Archer(unsigned int _HP, unsigned int _AGT, unsigned int _arrows)
	{
		HP = _HP;
		AGT = _AGT;
		arrows = _arrows;
	}

	void shot() const
	{
		if (arrows > 0)
		{
			std::cout << "PHEAF!\n";
		}
		else
		{
			std::cout << "Out of arrows\n";
		}
	}

	virtual ~Archer() {}
};

class Multy : public Warrior, public Wizard, public Archer
{
private:
public:
	Multy() : 
		Warrior(unsigned int(100), unsigned int(25), weaponType(1)), 
		Wizard(unsigned int(100), unsigned int(120)), 
		Archer(unsigned int(100), unsigned int(120), unsigned int(10))
	{}
	Multy(unsigned int _HP, unsigned int _DMG, unsigned int _INT, unsigned int _AGT, unsigned int _arrows, weaponType _weapon) :
		Warrior(_HP, _DMG, _weapon),
		Wizard(_HP, _INT),
		Archer(_HP, _AGT, _arrows)
	{}

};

int main()
{
	Warrior tester1;
	tester1.hit();
	Wizard tester2;
	tester2.luminos();
	Archer tester3;
	tester3.shot();
	Multy multyTester;
	multyTester.hit();
	multyTester.luminos();
	multyTester.shot();
}