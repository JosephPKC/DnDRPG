#ifndef RESULTSET_H
#define RESULTSET_H
#pragma once
#include "../data/essentials.h"
#include "../data/enumerations.h"
using namespace constant;
struct ResultSet {
	oid _id;
	string _name;
	ResultSet() {
		_id = C_DEF_ID;
		_name = C_DEF_GEN_STRING;
	}

	ResultSet(oid id, string name) {
		_id = id;
		_name = name;
	}
};

struct ItemSet : public ResultSet {
	ItemType _type;
	int _value;
	ItemSet() : ResultSet() {
		_type = ItemType::DEF;
		_value = C_DEF_GEN_INT;
	}

	ItemSet(oid id, string name, string type, int value)
		: ResultSet(id,name) {
		_type = ItemTypeRLU.at(type);
		_value = value;
	}
};

struct PotionSet : public ItemSet {
	oid _eid;
	PotionSet() : ItemSet() {
		_type = ItemType::POTION;
		_eid = C_DEF_ID;
	}

	PotionSet(oid id, string name, int value, oid eid)
		: ItemSet(id,name,"Potion",value) {
		_eid = eid;
	}
};

struct TreasureSet : public ItemSet {
	string _flavor;
	TreasureSet() : ItemSet() {
		_type = ItemType::TREASURE;
		_flavor = C_DEF_GEN_STRING;
	}

	TreasureSet(oid id, string name, int value, string flavor) : ItemSet(id,name,"Treasure",value) {
		_flavor = flavor;
	}
};

struct GearSet : public ItemSet {
	GearType _type;
	GearSlot _slot;
	GearSet() : ItemSet() {
		ItemSet::_type = ItemType::GEAR;
		_type = GearType::DEF;
		_slot = GearSlot::DEF;
	}

	GearSet(oid id, string name, int value, string gtype, string slot)
		: ItemSet(id,name,"Gear",value) {
		_type = GearTypeRLU.at(gtype);
		_slot = GearSlotRLU.at(slot);
	}
};

struct ArmorSet : public GearSet {
	ArmorWeight _weight;
	int _armor;
	int _initiative;
	ArmorSet() : GearSet() {
		_type = GearType::ARMOR;
		_weight = ArmorWeight::DEF;
		_armor = C_DEF_GEN_INT;
		_initiative = C_DEF_GEN_INT;
	}

	ArmorSet(oid id, string name, int value, string slot, string weight, int armor, int initiative)
		: GearSet(id,name,value,"Armor",slot) {
		_weight = ArmorWeightRLU.at(weight);
		_armor = armor;
		_initiative = initiative;
	}
};

struct OffHandSet : public GearSet {
	int _shield;
	OffHandSet() : GearSet() {
		_type = GearType::OFFHAND;
		_shield = C_DEF_GEN_INT;
	}

	OffHandSet(oid id, string name, int value, string slot, int shield)
		: GearSet(id,name,value,"Off Hand",slot) {
		_shield = shield;
	}
};

struct WeaponSet : public GearSet {
	bool _hand;
	WeaponClass _cl;
	int _dmgnum;
	int _dmgdice;
	int _dmgbonus;
	int _atkbonus;
	int _chbonus;
	int _spatkbonus;
	WeaponSet() : GearSet() {
		_type = GearType::WEAPON;
		_hand = C_DEF_GEN_BOOL;
		_cl = WeaponClass::DEF;
		_dmgnum = C_DEF_GEN_INT;
		_dmgdice = C_DEF_GEN_INT;
		_dmgbonus = C_DEF_GEN_INT;
		_atkbonus = C_DEF_GEN_INT;
		_chbonus = C_DEF_GEN_INT;
		_spatkbonus = C_DEF_GEN_INT;
	}

	WeaponSet(oid id, string name, int value, string slot, int hand, string cl, int dmgnum, int dmgdice, int dmgbonus, int atkbonus, int chbonus, int spatkbonus)
		:	GearSet(id,name,value,"Weapon",slot) {
		_hand = (hand == 0 ? false : true);
		_cl = WeaponClassRLU.at(cl);
		_dmgnum = dmgnum;
		_dmgdice = dmgdice;
		_dmgbonus = dmgbonus;
		_atkbonus = atkbonus;
		_chbonus = chbonus;
		_spatkbonus = spatkbonus;
	}
};


#endif // RESULTSET_H
