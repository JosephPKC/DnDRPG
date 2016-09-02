#ifndef EFFECTREFERENCELIST_H
#define EFFECTREFERENCELIST_H
#pragma once
#include "../src/effect.h"

/* Racial Feature Effects */

/* Class Mechanic Effects */

/* Class Skill Effects */

/* Monster Action Effects */

/* Basic Action Effects */

/* Item Effects */

/* Basic Healing Potion Effec Template */
class R_HEALING_POTION_BASE : public Effect {
public:
	R_HEALING_POTION_BASE(oid id = 0, int resnum, int resdice, int resbonus) : Effect(id) {
		_resnum = resnum;
		_resdice = resdice;
		_resbonus = resbonus;
	}

	bool exec(GameManager* G, Combat* C, oid user, std::vector<oid> targets) {
		if (!Effect::exec(G,C,user,targets)) return false;

		//Roll the Restore Dice
		//Restore that many Hit Points to user.
		return true;
	}

	int resnum() const {
		return _resnum;
	}
	void setResnum(int resnum) {
		_resnum = resnum;
	}

	int resdice() const {
		return _resdice;
	}
	void setResdice(int resdice) {
		_resdice = resdice;
	}

	int resbonus() const {
		return _resbonus;
	}
	void setResbonus(int resbonus) {
		_resbonus = resbonus;
	}

private:
	int _resnum;
	int _resdice;
	int _resbonus;
};

/* Lesser Healing Potion Effect */
class R_LESSER_HEALING_POTION : public R_HEALING_POTION_BASE {
public:
	R_LESSER_HEALING_POTION() : R_HEALING_POTION_BASE(1,1,8,0) {}
};
static const Effect S_LESSER_HEALING_POTION = R_LESSER_HEALING_POTION();

/* Effect Master List */
static const Effect* L_EFFECT_MASTER[C_EFFECT_NUM_SIZE] = {
	&S_LESSER_HEALING_POTION
};
#endif // EFFECTREFERENCELIST_H
