#include <iostream>
#include "src/dbmanager.h"
using namespace std;

int main(int argc, char *argv[]) {
	DbManager db("D:\\Files\\Programming\\Home\\C++\\DnDRPG\\DnDRPG\\data\\ref_data.db");
	ArmorSet as = db.queryArmor(1);
	OffHandSet os = db.queryOffHand(26);
	WeaponSet ws = db.queryWeapon(17);
	cout << as._name << ", " << os._name << ", " << ws._name << endl;

	return 0;
}

/* TODO */
/* Implement the Item Stat Value Scaling Tables
 * Implement the Upgrade and Update functions for the Gear
 * Test the Gear classes
 * Implement Potion Effects
 */
