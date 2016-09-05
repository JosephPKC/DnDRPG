#ifndef ESSENTIALS_H
#define ESSENTIALS_H
#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include "enumerations.h"
using namespace std;

typedef size_t oid;
typedef std::vector<std::tuple<int,int,std::string,bool>> qres;

/* Constants */
namespace constant {
	/* Default Values */
	static const int C_DEF_GEN_INT = 0;
	static const string C_DEF_GEN_STRING = "";
	static const bool C_DEF_GEN_BOOL = true;

	static const oid C_DEF_ID = 0;
	static const string C_DEF_DESC = "";

	static const int C_EFFECT_NUM_SIZE = 100;

	/* DB Constants */


	/* Game Values */
	static const double C_MIN_DMG_SCALING = 7;
	static const double C_MAX_DMG_SCALING = 2;
	static const double C_ATK_BONUS_SCALING = 5;
	static const double C_CRIT_HIT_BONUS_SCALING = 10;
	static const double C_SP_ATK_BONUS_SCALING = 5;
	static const double C_ARMOR_BONUS_SCALING = 5;
	static const double C_INIT_BONUS_SCALING = 6;
	static const double C_STR_BONUS_SCALING = 8;
	static const double C_DEX_BONUS_SCALING = 8;
	static const double C_CON_BONUS_SCALING = 8;
	static const double C_INT_BONUS_SCALING = 8;
	static const double C_HP_BONUS_SCALING = 1;
	static const double C_BAR_BONUS_SCALING = 3;
	static const double C_SAVE_BONUS_SCALING = 10;
	static const double C_CRIT_MIN_BONUS_SCALING = 10;
	static const double C_THORNS_BONUS_SCALING = 4;
	static const double C_REG_BONUS_SCALING = 5;
	static const double C_BAR_REG_BONUS_SCALING = 5;

	static const int C_MAX_LEVEL = 20;
}

namespace error {
	//Define Error Codes
	//For universal error detection, either use a global error flag, or use exceptions
}

string toString(size_t i); //Uses sstream

int roll(int min, int max, int num = 1); //Uses cmath, cstdlib

/* Value Scaling Function */
int getScaling(ItemStat stat);

int getScaledValue(int base, int level, ItemStat stat);

int getBaseValue(int value, int level, ItemStat stat);
#endif // ESSENTIALS_H
