#ifndef EFFECT_H
#define EFFECT_H
#include "combat.h"
#include "gamemanager.h"
#include "cosmicobject.h"
#include <vector>
class Effect : public CosmicObject {
public:
	Effect();
	Effect(oid id);
	virtual bool exec(GameManager* G, Combat* C, oid user, std::vector<oid> targets);
	virtual std::string toString();

private:

};

#endif // EFFECT_H
