#include "colors.h"

void setColor(unsigned int color){ // colore testo
	#ifdef _WIN32
		HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hCon, color);
	#else
		cout<<"\033[0;3"<<color<<"m";
	#endif

	//google: 'codice colore c++' || outTab()
}

void setColor(){
	setColor(15);
}

void outTab(){
	for(int i=0; i<256; i++){
		if(i%16==0){
			std::cout<<"\n";
		}

		setColor(i);
		cout<<setw(4)<<i;
	}

	setColor();
	cout<<"\n\n";
}

void errorMSG(string msg){
	cout<<"\n";
	setColor(79);
	cout<<"ERRORE";
	setColor();
	cout<<" "<<msg<<"\n\n";
}

void warningMSG(string msg){
	cout<<"\n";
	setColor(224);
	cout<<"ATTENZIONE";
	setColor();
	cout<<" "<<msg<<"\n\n";
}

void infoMSG(string msg){
	cout<<"\n";
	setColor(31);
	cout<<"INFO";
	setColor();
	cout<<" "<<msg<<"\n\n";
}

void goodMSG(string msg){
	cout<<"\n";
	setColor(47);
	cout<<"SUCCESSO";
	setColor();
	cout<<" "<<msg<<"\n\n";
}

void error(){
	cout<<"\n";
	setColor(71);
	cout<<"ERRORE";
	setColor();
	cout<<"\n\n";
}
