#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H
#include "item.h"
#include "dbmanager.h"

class ItemFactory {
public:
	ItemFactory();

	Treasure createTreasure(oid id, int level);
	Potion createPotion(oid id, int level);
	Weapon createWeapon(oid id, int level, GearRarity rarity);
	Armor createArmor(oid id, int level, GearRarity rarity);
	OffHand createOffHand(oid id, int level, GearRarity rarity);


};

#endif // ITEMFACTORY_H
