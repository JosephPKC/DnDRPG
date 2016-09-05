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
	Item::setType(ItemType::GEAR);
	_level = C_DEF_GEN_INT;
	_type = GearType::DEF;
	_rarity = GearRarity::DEF;
	_slot = GearSlot::DEF;
}

Gear::Gear(oid id, string flavor, string name, int value, int level, GearType type, GearRarity rarity, GearSlot slot)
	: Item(id,flavor,name,ItemType::GEAR,value){
	setLevel(level);
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
	setLevel(level() + 1);
	update();
}

int Gear::level() const {
	return _level;
}

void Gear::setLevel(int level) {
	if (level <= C_MAX_LEVEL && level > 0)
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
	for (std::size_t i = 0; i < _properties.size(); ++i) {
		int base = getBaseValue(_properties[i].second,level() - 1,_properties[i].first);
		_properties[i].second = getScaledValue(base,level(),_properties[i].first);
	}
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
	setLevel(level() + 1);
	update();
}

void Armor::update() {
	int base = getBaseValue(_armor,level() - 1,ItemStat::AC);
	_armor = getScaledValue(base,level(),ItemStat::AC);
	base = getBaseValue(_init,level() - 1,ItemStat::INIT);
	_init = getScaledValue(base,level(),ItemStat::INIT);
	Gear::update();
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
	setLevel(level() + 1);
	update();
}

void OffHand::update() {
	int base = getBaseValue(_shield,level() - 1,ItemStat::AC);
	_shield = getScaledValue(base,level(),ItemStat::AC);
	Gear::update();
}


Weapon::Weapon() : Gear() {
	Gear::setType(GearType::WEAPON);
	Gear::setSlot(GearSlot::MAIN);
	_twoHand = C_DEF_GEN_BOOL;
	_cl = WeaponClass::DEF;
	_dmgmin = C_DEF_GEN_INT;
	_dmgmax = C_DEF_GEN_INT;
	_atk = C_DEF_GEN_INT;
	_ch = C_DEF_GEN_INT;
	_spatk = C_DEF_GEN_INT;
	_dmgtype = DamageType::DEF;
}

Weapon::Weapon(oid id, string flavor, string name, int value, int level, GearRarity rarity, GearSlot slot, bool twoHand, WeaponClass cl, int dmgmin, int dmgmax, int atk, int ch, int spatk, DamageType dmgtype)
	: Gear(id,flavor,name,value,level,GearType::WEAPON,rarity,slot) {
	_twoHand = twoHand;
	_cl = cl;
	_dmgmin = dmgmin;
	_dmgmax = dmgmax;
	_atk = atk;
	_ch = ch;
	_spatk = spatk;
	_dmgtype = dmgtype;
}

void Weapon::upgrade() {
	setLevel(level() + 1);
	update();
}

int Weapon::rollDamage() {
	return roll(_dmgmin,_dmgmax);
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

int Weapon::dmgmin() const {
	return _dmgmin;
}

void Weapon::setDmgmin(int dmgmin) {
	_dmgmin = dmgmin;
}

int Weapon::dmgmax() const {
	return _dmgmax;
}

void Weapon::setDmgmax(int dmgmax) {
	_dmgmax = dmgmax;
}

void Weapon::update() {
	int base = getBaseValue(_atk,level() - 1,ItemStat::ATK);
	_atk = getScaledValue(base,level(),ItemStat::ATK);

	base = getBaseValue(_spatk,level() - 1,ItemStat::SP_ATK);
	_spatk = getScaledValue(base,level(),ItemStat::SP_ATK);

	base = getBaseValue(_ch,level() - 1,ItemStat::CRIT_HIT);
	_ch = getScaledValue(base,level(),ItemStat::CRIT_HIT);

	base = getBaseValue(_dmgmin,level() - 1,ItemStat::MIN_DMG);
	_dmgmin = getScaledValue(base,level(),ItemStat::MIN_DMG);

	base = getBaseValue(_dmgmax,level() - 1,ItemStat::MAX_DMG);
	_dmgmax = getScaledValue(base,level(),ItemStat::MAX_DMG);

	Gear::update();

}
