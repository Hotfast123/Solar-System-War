#pragma once
#include <iostream>
#include <string>
using namespace std;

class Weapons
{
public:
	int damageStrength;
	string weaponType;

	Weapons();
	Weapons(int Damage, string type);
};
