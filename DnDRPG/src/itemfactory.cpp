#include "itemfactory.h"

ItemFactory::ItemFactory() {
	//Nothing
}

Treasure ItemFactory::createTreasure(oid id, int level) {
	DbManager dbm(C_DB_PATH);
	TreasureSet ts = dbm.queryTreasure(id);
	if (ts._type == ItemType::DEF)
		return Treasure();
	return Treasure(id,ts._flavor,ts._name,ts._value + level * (ts._value / 2));
}

Potion ItemFactory::createPotion(oid id, int level) {

}

Weapon ItemFactory::createWeapon(oid id, int level, GearRarity rarity)
{

}

Armor ItemFactory::createArmor(oid id, int level, GearRarity rarity)
{

}

OffHand ItemFactory::createOffHand(oid id, int level, GearRarity rarity)
{

}

