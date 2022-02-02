#include <iostream>
#include "Enemies.h"
#include "Player.h"
#include "Weapons.h" 
#include <ctime>

using namespace std;

//Grid Variables 
const int Row = 6;
const int Column = 6;
int Grid[Row][Column];
//int** Map = 0;
//int grid[* playerRow][* playerColumn];

//Player Variables 
Player player1;
char playerInput = '#';

//Player X and Y on the grid
int playerX = 0;
int playerY = 0;

//Player selected Gun number 
int pGunNumber = 0;
int* pGunNumberPointer = &pGunNumber;

//Main Game
bool startGame = false;
bool stillAttacking = false;

//Weapons
//Weapons weapon1;
Weapons weapons[3];
int weaponNumber = 0;

//Enemy
Enemy enemy1;
//Enemy enemy[3];
int maxEnemy;

void Clear()
{
	for (int i = 0; i < Column; i++)
	{
		for (int j = 0; j < Row; j++)
		{
			//initialising Main grid with a value of 0;
			Grid[i][j] = 0;
		}
	}
}

//void Show()
//{
//	for (int i = 0; i < Column; i++)
//	{
//		for (int j = 0; j < Row; j++)
//		{
//			cout << easyGrid[i][j] << " ";
//		}
//		cout << endl;
//	}
//}

void WeaponFireHull()
{
	//Player is attacking enemy ships health 

	//Gives the player 3 randomly assinged weapon
	cout << "What Weapon are you going to use?" << endl;
	cout << "1. " << weapons[0].weaponType << endl;
	cout << "2. " << weapons[1].weaponType << endl;
	cout << "3. " << weapons[2].weaponType << endl;
	cin >> *pGunNumberPointer;
	
	//Pick the Fist Weapon
	if (*pGunNumberPointer == 1)
	{
		//Takes the first weapons health away from the enemy
		enemy1.spaceship1.health -= weapons[0].damageStrength;
		cout << "You did " << weapons[0].damageStrength << " damage to the enemy" << endl;

		if (enemy1.spaceship1.health <= 0)
		{
			//Enemy ship blow up and adds the ships score value to the player
			cout << "The ship explodes." << endl;
			player1.score += enemy1.scorevalue;
			cout << "Your health is currently " << player1.health << endl;
			cout << "Your score is  " << player1.score << endl;
			system("PAUSE");
			//Sets the attacking while loop to false so the player can go back to the grid screen
			stillAttacking = false;
		}
		else
		{
			//Calculates the enemy health and displays it on screen 
			if (enemy1.spaceship1.health > 75)
			{
				cout << "The ship looks fine keep fireing" << endl;
				system("PAUSE");
			}
			if (enemy1.spaceship1.health <= 0)
			{
				cout << "The ship is looking worse for wear" << endl;
				system("PAUSE");
			}
			if (enemy1.spaceship1.health >= 25 && enemy1.spaceship1.health <= 40)
			{
				cout << "The enemy cannont take many more hits" << endl;
				system("PAUSE");
			}
		}
	}
	//Picks the Secound Weapon
	if (*pGunNumberPointer == 2)
	{
		enemy1.spaceship1.health -= weapons[1].damageStrength;
		cout << "You did " << weapons[1].damageStrength << " damage to the enemy" << endl;

		if (enemy1.spaceship1.health <= 0)
		{
			cout << "The ship explodes." << endl;
			player1.score += enemy1.scorevalue;
			cout << "Your health is currently " << player1.health << endl;
			cout << "Your score is  " << player1.score << endl;
			system("PAUSE");
			stillAttacking = false;
		}
		else
		{
			if (enemy1.spaceship1.health > 75)
			{
				cout << "The ship looks fine keep fireing" << endl;
				system("PAUSE");
			}
			if (enemy1.spaceship1.health <= 0)
			{
				cout << "The ship is looking worse for wear" << endl;
				system("PAUSE");
			}
			if (enemy1.spaceship1.health >= 25 && enemy1.spaceship1.health <= 40)
			{
				cout << "The enemy cannont take many more hits" << endl;
				system("PAUSE");
			}
		}
	}
	//Picks the Third Weapon
	if (*pGunNumberPointer == 3)
	{
		enemy1.spaceship1.health -= weapons[2].damageStrength;
		cout << "You did " << weapons[2].damageStrength << " damage to the enemy" << endl;

		if (enemy1.spaceship1.health <= 0)
		{
			cout << "The ship explodes." << endl;
			player1.score += enemy1.scorevalue;
			cout << "Your health is currently " << player1.health << endl;
			cout << "Your score is  " << player1.score << endl;
			system("PAUSE");
			stillAttacking = false;
		}
		else
		{
			if (enemy1.spaceship1.health > 75)
			{
				cout << "The ship looks fine keep fireing" << endl;
				system("PAUSE");
			}
			if (enemy1.spaceship1.health <= 0)
			{
				cout << "The ship is looking worse for wear" << endl;
				system("PAUSE");
			}
			if (enemy1.spaceship1.health >= 25 && enemy1.spaceship1.health <= 40)
			{
				cout << "The enemy cannont take many more hits" << endl;
				system("PAUSE");
			}
		}
	}
}

void EnemyAttack()
{
	system("CLS");
	//If the player doge chance is above 50 miss the attack
	if (player1.dogeChance >= 50)
	{
		cout << "Useing the ships thrusters you managed to avoid the enemy attack!" << endl;
		player1.dogeChance -= 50;
		cout << "The Enemy missed there Attack!" << endl;
		system("PAUSE");
	}
	//If player health is above 0 take 25 damage
	else if (enemy1.spaceship1.health > 0)
	{
		cout << "The Enemy Opens fires" << endl;
		player1.health -= 25;
		cout << "You have taken " << " 25 damage" << endl;
		cout << "Your health is  " << player1.health <<  endl;
		system("PAUSE");
		
		//If the player has 0 or less health stop the Attacking loop and Game loop
		if (player1.health <= 0)
		{
			stillAttacking = false;
			startGame = false;
		}
	}
}

void PlayerAttack()
{
	//Attacking loop 
	while (stillAttacking)
	{
		system("CLS");
		cout << "Engaging Enemy Ship" << endl;
		cout << "Enemy Space Craft is a " << enemy1.spaceship1.type << endl;
		cout << "1. Attack" << endl;
		cout << "2. Dodge" << endl;
		cout << "3. Heal" << endl;

		cin >> *pGunNumberPointer;
		switch (*pGunNumberPointer)
		{
		case 1:
			//Player attack function
			WeaponFireHull();
			break;
		case 2:
		// Player increases doge chance
			cout << "You fire up you thrusters " << endl;
			player1.dogeChance += 35;
			cout << "Thrusters need to be above 50 to doge you have " << player1.dogeChance << endl;
			system("PAUSE");
			break;
		case 3:
			//Player increases total health 
			player1.spaceship1.health += 35;	
			cout << "You heal 25 health. Your health is " << player1.health << endl;
			system("PAUSE");
		break;
		}
		//Enemy attack function
		EnemyAttack();
	}
}

void EnemySetUp()
{
	//Setting the values for each class of enemy to a grid tile
	
	//Scout Class ships
	Grid[0][0] = 0;
	Grid[1][1] = 0;
	Grid[1][2] = 0;
	Grid[2][1] = 0;
	Grid[3][3] = 0;
	Grid[2][3] = 0;
	Grid[1][0] = 0;

	//Assault Class Ships
	Grid[0][2] = 1;
	Grid[0][3] = 1;
	Grid[3][0] = 1;
	Grid[2][2] = 1;
	Grid[0][1] = 1;

	//Tank Class ships
	Grid[2][0] = 3;
	Grid[3][2] = 3;
	Grid[1][3] = 3;
	Grid[3][1] = 3;
}

int main()
{
	//Clears the array and sets all the values to zero
	Clear();
	//Resests the random seed
	srand(time(NULL));
	//Sets up the enemy postions on the array
	EnemySetUp();

	//Randoms the first option of weapons
	weaponNumber = rand() % 3;
	srand(time(NULL));
	if (weaponNumber == 0)
	{
		//Uses the wepaon class to create a weapon class array 
		weapons[0] = Weapons(30, "laser rifle");
		//Weapon damage and name being applied
	}
	if (weaponNumber == 1)
	{
		weapons[0] = Weapons(50, "Machine Guns");
	}
	if (weaponNumber == 2)
	{
		weapons[0] = Weapons(rand() % 60 + 20, "Railgun");
	}
	if (weaponNumber == 3)
	{
		weapons[0] = Weapons(15, "Emp Gun");
	}

	//Randoms for the secound weapons
	weaponNumber = rand() % 6 + 4;
	srand(time(NULL));
	if (weaponNumber == 4)
	{
		weapons[1] = Weapons(rand() % 60 + 25, "Laser Beam");
	}
	if (weaponNumber == 5)
	{
		weapons[1] = Weapons(75, "Rockets");
	}
	if (weaponNumber == 6)
	{
		weapons[1] = Weapons(rand() % 30 + 25, "Coilgun");
	}

	//Random for the third row of weapons
	weaponNumber = rand() % 9 + 7;
	srand(time(NULL));
	if (weaponNumber == 7)
	{
		weapons[2] = Weapons(rand() % 35 + 25, "Drone Strikes");
	}
	if (weaponNumber == 8)
	{
		weapons[2] = Weapons(42, "Mines");
	}
	if (weaponNumber == 9)
	{
		weapons[2] = Weapons(rand() % 90, "Shrapnel Blaster");
	}

	//Start of Game loop
	startGame = true;
	while (startGame)
	{
		stillAttacking = true;
		cout << "What way do you want to travel?" << endl;
		cout << "Please enter in W = North, S = South, D = East, A = West" << endl;
		cin >> playerInput;
		switch (playerInput)
		{
		case 'w':
			playerY++;
			break;
		case 's':
			playerY--;
			break;
		case 'd':
			playerX++;
			break;
		case 'a':
			playerX--;
			break;
		default:
			cout << "Invalid Key Entered" << endl;
			break;

			//Check how close the player is to the edge of the grid
			if (playerX == 10)
			{
				//If the player has gone over move them back
				playerX = 9;
			}
			if (playerX == -1)
			{
				playerX = 0;
			}
			if (playerY == -1)
			{
				playerY = 0;
			}
			if (playerY == 10)
			{
				playerY = 9;
			}
		}
		cout << "Your current position of X = " << playerX << " and Y = " << playerY << endl;
		cout << Grid[playerX][playerY] << endl;

		system("PAUSE");

		if (Grid[playerX][playerY] == 1)
		{
			//Tank
			enemy1.scorevalue = 100;
			enemy1.spaceship1.health = 100;
			enemy1.spaceship1.type = "Tank Class Destoryer";

			//Currently not in use
			//enemy1.spaceship1.speed = 10;
			//enemy1.spaceship1.shieldStrength = 35;

			//enemy1.spaceship1.amountOfArmour = 3;
			//enemy1.spaceship1.amountOfThurusters = 1;
			//enemy1.spaceship1.amountOfSheildGens = 3;

			//enemy1.spaceship1.shieldGeneratorsHealth = 100;
			//enemy1.spaceship1.enginesHealth = 100;
			//enemy1.spaceship1.thrustersHealth = 100;
			//enemy1.spaceship1.armourHealth = 100;

			PlayerAttack();
			EnemyAttack();
		}

		if (Grid[playerX][playerY] == 2)
		{
			//Assault
			enemy1.scorevalue = 50;
			enemy1.name = "Attack class";
			enemy1.spaceship1.health = 60;
			enemy1.spaceship1.type = "Assault";


			PlayerAttack();
			EnemyAttack();
		}

		if (Grid[playerX][playerY] == 3)
		{
			//Scout
			enemy1.scorevalue = 30;
			enemy1.name = "Seaker class";
			enemy1.spaceship1.health = 30;
			enemy1.spaceship1.type = "Scout";

			PlayerAttack();
			EnemyAttack();
		}
	}
	system("CLS");
	cout << "You have Died" << endl;
	cout << "Your Score was " << player1.score << endl;
	cout << "Thanks for playing " << endl;
}

