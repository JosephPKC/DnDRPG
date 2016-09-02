#include "dbmanager.h"

DbManager::DbManager(const QString& path) {
	_db = QSqlDatabase::addDatabase("QSQLITE");
	_db.setDatabaseName(path);

	if (!_db.open()) {
		/* Error connecting with database */
	}
}

std::string DbManager::convert(const QString& str) {
	return str.toStdString();
}

QString DbManager::convert(const std::string& str) {
	return QString::fromStdString(str);
}

ArmorSet DbManager::queryArmor(oid id) {
	QSqlQuery q;
	string query = "SELECT * FROM ArmorView A WHERE A.iid == ";
	string qapp = toString(id);
	query += qapp;
	if (!q.exec(QString::fromStdString(query))) {
		qDebug() << "Exec returned false!\n";
		qDebug() << QString::fromStdString(query);
	}

	ArmorSet as;
	if (q.size() > 1) {
		qDebug() << "More than one row returned!\n";
	}

	if (q.next()) {
		if (q.value(0).toInt() != id) {
			qDebug() << "ID mismatch!\n";
		}
		as._id = id;
		as._name = convert(q.value(1).toString());
		as.ItemSet::_type = ItemTypeRLU.at(convert(q.value(2).toString()));
		as._type = GearTypeRLU.at(convert(q.value(3).toString()));
		as._slot = GearSlotRLU.at(convert(q.value(4).toString()));
		as._weight = ArmorWeightRLU.at(convert(q.value(5).toString()));
		as._armor = q.value(6).toInt();
		as._initiative = q.value(7).toInt();
		as._value = q.value(8).toInt();
	}

	return as;
}

OffHandSet DbManager::queryOffHand(oid id) {
	QSqlQuery q;
	string query = "SELECT * FROM OffHandView O WHERE O.iid == " + toString(id);
	if(!q.exec(QString::fromStdString(query))) {
		qDebug() << "Exec returned false!\n";
		qDebug() << QString::fromStdString(query);
	}

	OffHandSet os;
	if (q.size() > 1) {
		qDebug() << "More than one row returned!\n";
	}

	if (q.next()) {
		if (q.value(0).toInt() != id) {
			qDebug() << "ID mismatch!\n";
		}
		os._id = id;
		os._name = convert(q.value(1).toString());
		os.ItemSet::_type = ItemTypeRLU.at(convert(q.value(2).toString()));
		os._type = GearTypeRLU.at(convert(q.value(3).toString()));
		os._slot = GearSlotRLU.at(convert(q.value(4).toString()));
		os._shield = q.value(5).toInt();
		os._value = q.value(6).toInt();
	}
	return os;
}

WeaponSet DbManager::queryWeapon(oid id) {
	QSqlQuery q;
	string query = "SELECT * FROM WeaponView W WHERE W.iid == " + toString(id);
	if(!q.exec(QString::fromStdString(query))) {
		qDebug() << "Exec returned false!\n";
		qDebug() << QString::fromStdString(query);
	}

	WeaponSet ws;
	if (q.size() > 1) {
		qDebug() << "More than one row returned!\n";
	}

	if (q.next()) {
		if (q.value(0).toInt() != id) {
			qDebug() << "ID mismatch!\n";
		}
		ws._id = id;
		ws._name = convert(q.value(1).toString());
		ws.ItemSet::_type = ItemTypeRLU.at(convert(q.value(2).toString()));
		ws._type = GearTypeRLU.at(convert(q.value(3).toString()));
		ws._slot = GearSlotRLU.at(convert(q.value(4).toString()));
		ws._cl = WeaponClassRLU.at(convert(q.value(5).toString()));
		ws._hand = (q.value(6).toInt() == 0 ? false : true);
		ws._dmgnum = q.value(7).toInt();
		ws._dmgdice = q.value(8).toInt();
		ws._dmgbonus = q.value(9).toInt();
		ws._atkbonus = q.value(10).toInt();
		ws._chbonus = q.value(11).toInt();
		ws._spatkbonus = q.value(12).toInt();
		ws._value = q.value(13).toInt();
	}
	return ws;
}


