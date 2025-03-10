#ifndef _CONVERSIONS_H_
	#define _CONVERSIONS_H_
 #include "base.h"

 // isTypes
 bool isInt(string s);
 bool isLongInt(string str);
 bool isFloat(string str);
 bool isDouble(string str);
 bool isChar(string str);

 // input check
 char getCond(string in);
 bool inputCheck(string in, string param);

	// string utils
	vector<string> split(string in, string sep);
	string trim(string in, char sep);
	string substring(string in, int inizio, int fine);

 // conversions
 // → to be added as needed
	
#endif
