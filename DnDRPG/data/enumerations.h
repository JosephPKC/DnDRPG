#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H
#pragma once
#include <map>
using namespace std;
/* Primary Attribute */
enum class AttrP {
	ERR,
	DEF,
	STR,
	DEX,
	INT,
	CON
};

/* Derived Attribute */
enum class AttrD {
	ERR,
	DEF,
	HPM,
	BAR,
	BMA,
	BRA,
	BSA,
	BMD,
	BRM,
	BSM,
	SS,
	MS,
	RS,
	AC,
	BI,
	CHB,
	CHM,
	THO,
	REG,
	BRG
};

/* Item Stat Bonuses */
enum class ItemStat {

};

/* Damage Types */
enum class DamageType {
	ERR,
	DEF
};

/* Item Types */
enum class ItemType {
	ERR,
	DEF,
	GEAR,
	POTION,
	TREASURE
};
static const map<ItemType,string> ItemTypeLU = {
	{ItemType::ERR,"Error"},
	{ItemType::DEF,"Default"},
	{ItemType::GEAR,"Gear"},
	{ItemType::POTION,"Potion"},
	{ItemType::TREASURE,"Treasure"}
};
static const map<string,ItemType> ItemTypeRLU = {
	{"Error",ItemType::ERR},
	{"Default",ItemType::DEF},
	{"Gear",ItemType::GEAR},
	{"Potion",ItemType::POTION},
	{"Treasure",ItemType::TREASURE}
};

/* Gear Types */
enum class GearType {
	ERR,
	DEF,
	WEAPON,
	ARMOR,
	OFFHAND
};
static const map<GearType,string> GearTypeLU = {
	{GearType::ERR,"Error"},
	{GearType::DEF,"Default"},
	{GearType::WEAPON,"Weapon"},
	{GearType::ARMOR,"Armor"},
	{GearType::OFFHAND,"Off Hand"}
};
static const map<string,GearType> GearTypeRLU = {
	{"Error",GearType::ERR},
	{"Default",GearType::DEF},
	{"Weapon",GearType::WEAPON},
	{"Armor",GearType::ARMOR},
	{"Off Hand",GearType::OFFHAND}
};

/* Gear Rarity */
enum class GearRarity {
	ERR,
	DEF,
	COMMON,
	RARE,
	UNIQUE,
	LEGENDARY
};
static const map<GearRarity,string> GearRarityLU = {
	{GearRarity::ERR,"Error"},
	{GearRarity::DEF,"Default"},
	{GearRarity::COMMON,"Common"},
	{GearRarity::RARE,"Rare"},
	{GearRarity::UNIQUE,"Unique"},
	{GearRarity::LEGENDARY,"Legendary"}
};
static const map<string,GearRarity> GearRarityRLU = {
	{"Error",GearRarity::ERR},
	{"Default",GearRarity::DEF},
	{"Common",GearRarity::COMMON},
	{"Rare",GearRarity::RARE},
	{"Unique",GearRarity::UNIQUE},
	{"Legendary",GearRarity::LEGENDARY}
};

/* Gear Slot */
enum class GearSlot {
	ERR,
	DEF,
	MAIN,
	OFF,
	ARMOR,
	VERSATILE
};
static const map<GearSlot,string> GearSlotLU = {
	{GearSlot::ERR,"Error"},
	{GearSlot::DEF,"Default"},
	{GearSlot::MAIN,"Main"},
	{GearSlot::OFF,"Off"},
	{GearSlot::ARMOR,"Armor"},
	{GearSlot::VERSATILE,"Versatile"}
};
static const map<string,GearSlot> GearSlotRLU = {
	{"Error",GearSlot::ERR},
	{"Default",GearSlot::DEF},
	{"Main",GearSlot::MAIN},
	{"Off",GearSlot::OFF},
	{"Armor",GearSlot::ARMOR},
	{"Versatile",GearSlot::VERSATILE}
};

/* Armor Weight Type */
enum class ArmorWeight {
	ERR,
	DEF,
	LIGHT,
	HEAVY
};
static const map<ArmorWeight,string> ArmorWeightLU = {
	{ArmorWeight::ERR,"Error"},
	{ArmorWeight::DEF,"Default"},
	{ArmorWeight::LIGHT,"Light"},
	{ArmorWeight::HEAVY,"Heavy"}
};
static const map<string,ArmorWeight> ArmorWeightRLU = {
	{"Error",ArmorWeight::ERR},
	{"Default",ArmorWeight::DEF},
	{"Light",ArmorWeight::LIGHT},
	{"Heavy",ArmorWeight::HEAVY}
};

/* Weapon Class  */
enum class WeaponClass {
	ERR,
	DEF,
	DAGGER,
	AXE,
	MACE,
	SWORD,
	BOW,
	STAFF
};
static const map<WeaponClass,string> WeaponClassLU = {
	{WeaponClass::ERR,"Error"},
	{WeaponClass::DEF,"Default"},
	{WeaponClass::DAGGER,"Dagger"},
	{WeaponClass::AXE,"Axe"},
	{WeaponClass::MACE,"Mace"},
	{WeaponClass::SWORD,"Sword"},
	{WeaponClass::BOW,"Bow"},
	{WeaponClass::STAFF,"Staff"}
};
static const map<string,WeaponClass> WeaponClassRLU = {
	{"Error",WeaponClass::ERR},
	{"Default",WeaponClass::DEF},
	{"Dagger",WeaponClass::DAGGER},
	{"Axe",WeaponClass::AXE},
	{"Mace",WeaponClass::MACE},
	{"Sword",WeaponClass::SWORD},
	{"Bow",WeaponClass::BOW},
	{"Staff",WeaponClass::STAFF}
};

/* Feature Tags */
enum class FeatTag {
	ERR,
	DEF,
	ACTIVE,
	PASSIVE,
	ACID,
	COLD,
	FIRE,
	FORCE,
	LIGHTNING,
	NECROTIC,
	PHYSICAL,
	POISON,
	PSYCHIC,
	RADIANT,
	THUNDER,
	MELEE,
	RANGED,
	SPELL,
	HEALING,
	SUMMON,
	TRANSFORM,
	CONDITION,
	BOON,
	STANCE,
	AURA,
	SPIRIT,
	PROWESS,
	GUARDIAN,
	HUNTER,
	STEALTH,
	WILD
};

#endif // ENUMERATIONS_H
