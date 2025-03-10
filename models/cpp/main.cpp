#include "func.h"

void outMenu(int m){
	menu men=menu();

	men.setTitle("Titolo");

	// main menu
	men.add("Prima opzione", true);

	// elementi
	men.add("Primo menu", false);

	// stampa del menu
	men.out(m);
}

void es1(){
	ciao();
}

void es2(){}

int main(){
	string m;
	srand(time(NULL));

	do{
		outMenu(0);
		do{
			cin>>m;
		}while(!inputCheck(m, "int"));
		canc();

		switch(stoi(m)){
			case 1:{
				outMenu(1);
				es1();
				fresh();
			break;
			}
			case 2:{
				outMenu(2);
				es2();
				fresh();
			break;
			}
		}
	}while(m!="0");

	outMenu(-1);

	return 0;
}

