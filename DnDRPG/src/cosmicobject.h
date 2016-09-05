#ifndef COSMICOBJECT_H
#define COSMICOBJECT_H
#pragma once
#include "../data/essentials.h"
using namespace constant;
class CosmicObject {
public:
	CosmicObject();
	CosmicObject(oid i, std::string desc);

	oid getID() const;
	void setID(oid id);

	std::string getDescription() const;
	void setDescription(std::string desc);


private:
	oid _id;
	std::string _desc;
};

#endif // COSMICOBJECT_H
