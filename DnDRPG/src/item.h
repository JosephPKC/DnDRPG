#ifndef ITEM_H
#define ITEM_H
#pragma once
#include "cosmicobject.h"
#include "gamemanager.h"
#include "combat.h"
#include "../data/essentials.h"
#include "../data/enumerations.h"
#include "../data/effectreferencelist.h"

/* Item Base Class */
class Item : public CosmicObject {
public:
	Item();
	Item(oid id, string flavor, string name, ItemType type, int value);

	string name() const;
	void setName(const string& name);

	ItemType type() const;
	void setType(const ItemType& type);

	int value() const;
	void setValue(int value);

private:
	string _name;
	ItemType _type;
	int _value;
};

/* Treasure Item Class */
class Treasure : public Item {
public:
	Treasure();
	Treasure(oid id, string flavor, string name, int value);
};

/* Potion Item Class */
class Potion : public Item {
public:
	Potion();
	Potion(oid id, string flavor, string name, int value, oid eid);

	oid eid() const;
	void setEid(const oid& eid);

	bool applyEffect(GameManager* G, Combat* C, oid user, std::vector<oid> targets);

private:
	oid _eid;
};

/* Gear Item Class */
class Gear : public Item {
public:
	Gear();
	Gear(oid id, string flavor, string name, int value, int level, GearType type, GearRarity rarity, GearSlot slot);

	GearType type() const;
	void setType(const GearType& type);

	GearRarity rarity() const;
	void setRarity(const GearRarity& rarity);

	GearSlot slot() const;
	void setSlot(const GearSlot& slot);

	virtual void upgrade();

	int level() const;
	void setLevel(int level);

	std::vector<std::pair<ItemStat, int> > properties();
	void setProperties(const std::vector<std::pair<ItemStat, int> >& properties);

private:
	int _level;
	GearType _type;
	GearRarity _rarity;
	GearSlot _slot;
	std::vector<std::pair<ItemStat,int>> _properties;

	virtual void update();
};

/* Armor Class */
class Armor : public Gear {
public:
	Armor();
	Armor(oid id, string flavor, string name, int value,  int level, GearRarity rarity, ArmorWeight weight, int armor, int init);
	int armor() const;
	void setArmor(int armor);

	int init() const;
	void setInit(int init);

	ArmorWeight weight() const;
	void setWeight(const ArmorWeight& weight);

	void upgrade();

private:
	ArmorWeight _weight;
	int _armor;
	int _init;

	void update();
};

/* OffHand Class */
class OffHand : public Gear {
public:
	OffHand();
	OffHand(oid id, string flavor, string name, int value, int level, GearRarity rarity, int shield);

	int shield() const;
	void setShield(int shield);

	void upgrade();

private:
	int _shield;

	void update();
};

/* Weapon Class */
class Weapon : public Gear {
public:
	Weapon();
	Weapon(oid id, string flavor, string name, int value, int level, GearRarity rarity, GearSlot slot, bool twoHand, WeaponClass cl, int dmgnum, int dmgdice, int dmgbonus, int atk, int ch, int spatk, DamageType dmgtype);

	void upgrade();
	int rollDamage();

	bool twoHand() const;
	void setTwoHand(bool twoHand);

	WeaponClass cl() const;
	void setCl(const WeaponClass& cl);

	int dmgnum() const;
	void setDmgnum(int dmgnum);

	int dmgdice() const;
	void setDmgdice(int dmgdice);

	int dmgbonus() const;
	void setDmgbonus(int dmgbonus);

	int atk() const;
	void setAtk(int atk);

	int ch() const;
	void setCh(int ch);

	int spatk() const;
	void setSpatk(int spatk);

	DamageType dmgtype() const;
	void setDmgtype(const DamageType& dmgtype);

private:
	bool _twoHand;
	WeaponClass _cl;
	int _dmgnum;
	int _dmgdice;
	int _dmgbonus;
	int _atk;
	int _ch;
	int _spatk;
	DamageType _dmgtype;

	void update();
};

#endif // ITEM_H
