#include "item.h"

Item::Item() : CosmicObject() {
	_name = C_DEF_GEN_STRING;
	_type = ItemType::DEF;
	_value = C_DEF_GEN_INT;
}

Item::Item(oid id, string flavor, string name, ItemType type, int value)
	: CosmicObject(id,flavor) {
	_name = name;
	_type = type;
	_value = value;
}

string Item::name() const {
    return _name;
}

void Item::setName(const string& name) {
    _name = name;
}

ItemType Item::type() const {
    return _type;
}

void Item::setType(const ItemType& type) {
    _type = type;
}

int Item::value() const {
    return _value;
}

void Item::setValue(int value) {
    _value = value;
}

Treasure::Treasure() : Item() {
	setType(ItemType::TREASURE);
}

Treasure::Treasure(oid id, string flavor, string name, int value)
	: Item(id,flavor,name,ItemType::TREASURE,value) {
}

Potion::Potion() : Item() {
	setType(ItemType::POTION);
	_eid = C_DEF_ID;
}

Potion::Potion(oid id, string flavor, string name, int value, oid eid)
	: Item(id,flavor,name,ItemType::POTION,value) {
	_eid = eid;
}

oid Potion::eid() const {
	return _eid;
}

void Potion::setEid(const oid& eid) {
	_eid = eid;
}

bool Potion::applyEffect(GameManager* G, Combat* C, oid user, std::vector<oid> targets) {
	return L_EFFECT_MASTER[_eid]->exec(G,C,user,targets);
}

Gear::Gear() : Item() {
	setType(ItemType::GEAR);
	_level = C_DEF_GEN_INT;
	_type = GearType::DEF;
	_rarity = GearRarity::DEF;
	_slot = GearSlot::DEF;
}

Gear::Gear(oid id, string flavor, string name, int value, int level, GearType type, GearRarity rarity, GearSlot slot)
	: Item(id,flavor,name,ItemType::GEAR,value){
	_level = level;
	_type = type;
	_rarity = rarity;
	_slot = slot;
}

GearType Gear::type() const {
	return _type;
}

void Gear::setType(const GearType& type) {
	_type = type;
}

GearRarity Gear::rarity() const {
	return _rarity;
}

void Gear::setRarity(const GearRarity& rarity) {
	_rarity = rarity;
}

GearSlot Gear::slot() const {
	return _slot;
}

void Gear::setSlot(const GearSlot& slot) {
	_slot = slot;
}

void Gear::upgrade() {
	//The idea of upgrade is that it increments the level of the item by one.
	//When the item level increases, update all of its stats and properties by following the value scaling guide
}

int Gear::level() const {
	return _level;
}

void Gear::setLevel(int level) {
	_level = level;
}

std::vector<std::pair<ItemStat, int> > Gear::properties() {
	return _properties;
}

void Gear::setProperties(const std::vector<std::pair<ItemStat, int> >& properties) {
	_properties = properties;
}

void Gear::update() {
	//Follow the stat scaling guides
}

Armor::Armor() : Gear() {
	Gear::setType(GearType::ARMOR);
	Gear::setSlot(GearSlot::ARMOR);
	_weight = ArmorWeight::DEF;
	_armor = C_DEF_GEN_INT;
	_init = C_DEF_GEN_INT;
}

Armor::Armor(oid id, string flavor, string name, int value, int level, GearRarity rarity, ArmorWeight weight, int armor, int init)
	: Gear(id,flavor,name,value,level,GearType::ARMOR,rarity,GearSlot::ARMOR) {
	_weight = weight;
	_armor = armor;
	_init = init;
}

int Armor::armor() const {
	return _armor;
}

void Armor::setArmor(int armor) {
	_armor = armor;
}

int Armor::init() const {
	return _init;
}

void Armor::setInit(int init) {
	_init = init;
}

ArmorWeight Armor::weight() const {
	return _weight;
}

void Armor::setWeight(const ArmorWeight& weight) {
	_weight = weight;
}

void Armor::upgrade() {

}

void Armor::update() {

}

OffHand::OffHand() : Gear() {
	Gear::setType(GearType::OFFHAND);
	Gear::setSlot(GearSlot::OFF);
	_shield = C_DEF_GEN_INT;
}

OffHand::OffHand(oid id, string flavor, string name, int value, int level, GearRarity rarity, int shield)
	: Gear(id,flavor,name,value,level,GearType::OFFHAND,rarity,GearSlot::OFF) {
	_shield = shield;
}

int OffHand::shield() const {
	return _shield;
}

void OffHand::setShield(int shield) {
	_shield = shield;
}

void OffHand::upgrade() {

}

void OffHand::update() {

}


Weapon::Weapon() : Gear() {
	Gear::setType(GearType::WEAPON);
	Gear::setSlot(GearSlot::MAIN);
	_twoHand = C_DEF_GEN_BOOL;
	_cl = WeaponClass::DEF;
	_dmgnum = C_DEF_GEN_INT;
	_dmgdice = C_DEF_GEN_INT;
	_dmgbonus = C_DEF_GEN_INT;
	_atk = C_DEF_GEN_INT;
	_ch = C_DEF_GEN_INT;
	_spatk = C_DEF_GEN_INT;
	_dmgtype = DamageType::DEF;
}

Weapon::Weapon(oid id, string flavor, string name, int value, int level, GearRarity rarity, GearSlot slot, bool twoHand, WeaponClass cl, int dmgnum, int dmgdice, int dmgbonus, int atk, int ch, int spatk, DamageType dmgtype)
	: Gear(id,flavor,name,value,level,GearType::WEAPON,rarity,slot) {
	_twoHand = twoHand;
	_cl = cl;
	_dmgnum = dmgnum;
	_dmgdice = dmgdice;
	_dmgbonus = dmgbonus;
	_atk = atk;
	_ch = ch;
	_spatk = spatk;
	_dmgtype = dmgtype;
}

void Weapon::upgrade() {

}

int Weapon::rollDamage() {
	int min = _dmgnum;
	int max = _dmgnum * _dmgdice;
	return roll(min,max) + _dmgbonus;
}

bool Weapon::twoHand() const {
	return _twoHand;
}

void Weapon::setTwoHand(bool twoHand) {
	_twoHand = twoHand;
}

WeaponClass Weapon::cl() const {
	return _cl;
}

void Weapon::setCl(const WeaponClass& cl) {
	_cl = cl;
}

int Weapon::dmgnum() const {
	return _dmgnum;
}

void Weapon::setDmgnum(int dmgnum) {
	_dmgnum = dmgnum;
}

int Weapon::dmgdice() const {
	return _dmgdice;
}

void Weapon::setDmgdice(int dmgdice) {
	_dmgdice = dmgdice;
}

int Weapon::dmgbonus() const {
	return _dmgbonus;
}

void Weapon::setDmgbonus(int dmgbonus) {
	_dmgbonus = dmgbonus;
}

int Weapon::atk() const {
	return _atk;
}

void Weapon::setAtk(int atk) {
	_atk = atk;
}

int Weapon::ch() const {
	return _ch;
}

void Weapon::setCh(int ch) {
	_ch = ch;
}

int Weapon::spatk() const {
	return _spatk;
}

void Weapon::setSpatk(int spatk) {
	_spatk = spatk;
}

DamageType Weapon::dmgtype() const {
	return _dmgtype;
}

void Weapon::setDmgtype(const DamageType& dmgtype) {
	_dmgtype = dmgtype;
}

void Weapon::update() {

}
