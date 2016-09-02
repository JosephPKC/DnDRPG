#ifndef DBMANAGER_H
#define DBMANAGER_H
#pragma once
#include "resultset.h"
#include <QtSQL>

/* Needs table specific query functions */
class DbManager {
public:
	DbManager(const QString& path);

	/* Queries on Tables with Tags require manual sorting of Tags into the result vector */
	ArmorSet queryArmor(oid id);
	bool queryClass(oid id);
	bool queryMechanic(oid id);
	bool queryMonster(oid id);
	bool queryObject(oid id);
	OffHandSet queryOffHand(oid id);
	bool queryPath(oid id);
	bool queryPotion(oid id);
	bool queryRace(oid id);
	bool querySkill(oid id);
	bool queryStatus(oid id);
	bool queryTreasure(oid id);
	WeaponSet queryWeapon(oid id);


private:
	QSqlDatabase _db;

	string convert(const QString& str);
	QString convert(const std::string& str);
};

#endif // DBMANAGER_H
