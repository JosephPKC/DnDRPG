#ifndef ESSENTIALS_H
#define ESSENTIALS_H
#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstdlib>
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
}

namespace error {
	//Define Error Codes
	//For universal error detection, either use a global error flag, or use exceptions
}

string toString(size_t i); //Uses sstream

int roll(int min, int max, int num = 1); //Uses cmath, cstdlib
#endif // ESSENTIALS_H
