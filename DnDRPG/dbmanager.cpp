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
