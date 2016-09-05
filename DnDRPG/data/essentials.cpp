#include "essentials.h"

string toString(size_t i) {
	stringstream ss;
	ss << i;
	return ss.str();
}

/* Does not srand */
int roll(int min, int max, int num) {
	int sum = 0;
	for (std::size_t i = 0; i < num; ++i) {
		sum += (rand() % (max - min + 1)) + min;
	}
	return sum;
}

int getScaling(ItemStat stat) {
	using namespace constant;
	switch (stat) {
		case ItemStat::STR: {
			return C_STR_BONUS_SCALING;
		}
		case ItemStat::DEX: {
			return C_DEX_BONUS_SCALING;
		}
		case ItemStat::INT: {
			return C_INT_BONUS_SCALING;
		}
		case ItemStat::CON: {
			return C_CON_BONUS_SCALING;
		}
		case ItemStat::MIN_DMG: {
			return C_MIN_DMG_SCALING;
		}
		case ItemStat::MAX_DMG: {
			return C_MAX_DMG_SCALING;
		}
		case ItemStat::ATK: {
			return C_ATK_BONUS_SCALING;
		}
		case ItemStat::SP_ATK: {
			return C_SP_ATK_BONUS_SCALING;
		}
		case ItemStat::AC: {
			return C_ARMOR_BONUS_SCALING;
		}
		case ItemStat::INIT: {
			return C_INIT_BONUS_SCALING;
		}
		case ItemStat::CRIT_HIT: {
			return C_CRIT_HIT_BONUS_SCALING;
		}
		case ItemStat::CRIT_MIN: {
			return C_CRIT_MIN_BONUS_SCALING;
		}
		case ItemStat::HP: {
			return C_HP_BONUS_SCALING;
		}
		case ItemStat::BAR: {
			return C_BAR_BONUS_SCALING;
		}
		case ItemStat::SAVE: {
			return C_SAVE_BONUS_SCALING;
		}
		case ItemStat::THORNS: {
			return C_THORNS_BONUS_SCALING;
		}
		case ItemStat::REG: {
			return C_REG_BONUS_SCALING;
		}
		case ItemStat::BAR_REG: {
			return C_BAR_REG_BONUS_SCALING;
		}
		default: {
			return -1; //Error Code eventually
		}
	}
}


int getScaledValue(int base, int level, ItemStat stat) {
	if (base == 0) return 0;
	int scale = getScaling(stat);
	if (scale < 0) return -2;
	return base + (level / scale);
}


int getBaseValue(int value, int level, ItemStat stat) {
	if (value < 0) return -1;
	if (value == 0) return 0;
	int scale = getScaling(stat);
	if (scale < 0) return -2;
	return value - (level / scale);
}
