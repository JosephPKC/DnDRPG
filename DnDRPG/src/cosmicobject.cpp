#include "cosmicobject.h"

CosmicObject::CosmicObject() {
	_id = C_DEF_ID;
	_desc = C_DEF_DESC;
}

CosmicObject::CosmicObject(oid id, string desc) {
	_id = id;
	_desc = desc;
}

oid CosmicObject::getID() const {
	return _id;
}

void CosmicObject::setID(oid id) {
	_id = id;
}

string CosmicObject::getDescription() const {
	return _desc;
}

void CosmicObject::setDescription(string desc) {
	_desc = desc;
}

string CosmicObject::toString() {
	return _id + ":" + _desc;
}
