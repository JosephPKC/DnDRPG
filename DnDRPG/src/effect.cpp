#include "effect.h"


Effect::Effect() : CosmicObject() {

}

Effect::Effect(oid id) : CosmicObject(id,"") {

}

bool Effect::exec(Combat* C, oid user, std::vector<oid> targets) {
	/* Only checks parameters for general validity */
	if (C == nullptr) return false;
	if (user < 1) return false;
	for (std::size_t i = 0; i < targets.size(); ++i) {
		if (targets[i] < 1) return false;
	}
	return true;
}

string Effect::toString() {
	return "(Effect)" + CosmicObject::toString();
}
