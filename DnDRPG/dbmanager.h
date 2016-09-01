#ifndef DBMANAGER_H
#define DBMANAGER_H
#pragma once
#include <iostream>
#include <QtSQL>

/* Needs table specific query functions */
class DbManager {
public:
	DbManager(const QString& path);

private:
	QSqlDatabase _db;

	std::string convert(const QString& str);
	QString convert(const std::string& str);
};

#endif // DBMANAGER_H
