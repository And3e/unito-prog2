#ifndef _BASE_H_
	#define _BASE_H_
	#include <iostream>
	#include <stdlib.h>
	#include <time.h>
	#include <math.h>
	#include <ncurses.h>
	#include <iomanip>
	#include <string>
	#include <vector>
	#include <sys/stat.h>

	using namespace std;

	#ifdef __linux__
		#define OS "ln"
	#endif
	#ifdef __APPLE__
		#define OS "clear"
	#endif
	#ifdef _WIN32
		#define OS "cls"
	#endif

	struct menu_out{
		string campo;
		bool main;
		int id=-1;
		menu_out* next;
	};

	typedef menu_out* menuE;

	struct menu_sc{
		menuE riga;
		int id;
		menu_sc* next;
	};

	typedef menu_sc* scelte; // per choice

	class menu{
		private:
			// caratteri per stampa menu
			/* Orrizontale, Verticale, AltoSinistra, AltoDestra,
			BassoSinistra, BassoDestra, CentroSinistra, CentroDestra
			*/
			const char mO=196, mV=179, mAS=218, mAD=191, mBS=192, mBD=217, mCS=195, mCD=180;

			menuE mmain=nullptr;
			menuE melemento=nullptr;
			int margin_ma, margin_el;
			string title, name, classroom, date;

			// metodi
			void aggiungi(menuE &in, menu_out n);
			void menuID(menuE in);
			string getDate();
			int count(menuE in);
			int countInt(int in);
			vector<string> LtoV(menuE in);
			int Max(vector<string> in);
			string line(char c, int d);
			void stampa(menuE in, int notmain);

		public:
			menu();
			// set
			void setTitle(string titolo);
			void setName(string nome);
			void setClassroom(string classe);
			void setDate(string data);
			void setLastMenu(string nome, string classe, string data);
			void setMarginMain(int margin_main);
			void setMarginElement(int margin_main);
			void setMargin(int margin_main, int margin_element);
			// functions
			void add(string elemento, bool main);
			void out(int m);
	};

	class scelta{
		private:
			// caratteri per stampa menu
			/* Orrizontale, Verticale, AltoSinistra, AltoDestra,
			BassoSinistra, BassoDestra, CentroSinistra, CentroDestra
			*/
			const char mO=196, mV=179, mAS=218, mAD=191, mBS=192, mBD=217, mCS=195, mCD=180;

			scelte choice=nullptr;
			int max_choice, margin;

			// metodi
			void aggiungi(menuE &in, menu_out n);
			void aggiungi(scelte &in, menuE n);
			int getID(string in);
			int count(scelte in);
			void errore(string error, string message);
			vector<string> LtoV(menuE in);
			vector<vector<string>> StoV(scelte in);
			int Max(vector<string> in);
			int Max(vector<vector<string>> in);
			int Size(vector<vector<string>> in);
			int Tot(vector<string> in);
			vector<string> Colonna(vector<vector<string>> in, int i);
			string line(char c, int d);

		public:
			scelta();
			// set
			void setMax(int max);
			void setMargin(int m);
			// functions
			void add(string elemento, int id);
			void add(vector<string> elmenti, int id);
			void out();
	};

	void canc();
	void pausa(string in);
	void pausa(int in);
	void pausa();
	void fresh();
	int random(int min, int max);
	double random(int min, int max, int ndec);
#endif
