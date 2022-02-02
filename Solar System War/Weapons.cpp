#include "Weapons.h"

Weapons::Weapons()
{
	damageStrength = 0;
	weaponType = "Temp Weapon";
}

Weapons::Weapons(int Damage, string type)
{
	damageStrength = Damage;
	weaponType = type;
}

