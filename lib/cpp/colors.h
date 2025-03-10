#ifndef _COLORS_H_
	#define _COLORS_H_

	#include <iostream>
	#include <stdlib.h>
	#include <iomanip>

	#ifdef __linux__
		#define WS false
	#endif
	#ifdef __APPLE__
		#define WS false
	#endif
	#ifdef _WIN32
		#define WS true
		#include <windows.h>
	#endif

	using namespace std;

	// functions
	void setColor(unsigned int color);
	void setColor();
	void outTab();
	void errorMSG(string msg);
	void warningMSG(string msg);
	void infoMSG(string msg);
	void goodMSG(string msg);
	void error();
#endif
