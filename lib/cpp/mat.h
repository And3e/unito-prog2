#ifndef _MAT_H_
	#define _MAT_H_
	#include <iomanip>
	#include <string>

	const int r=100, c=100; // righe - colonne max

	// inizializzazione
	void insRC(int &R, int &C); // menu inserimento righe e colonne
	void insmM(int &min, int &max); // menu inserimento min e max

	// base
	void randMat(int R, int C, int in[][c], int min, int max); // inserimento random Matrice
	void sSMat(int R, int C, int in[][c]); // selection sort Matrice

	// stampa
	int countCifre(int n); // conteggio massimi caratteri | per setw  --> outMat
	void detM(int min, int max); // per setw  --> outMat
	void outMat(int R, int C, int in[][c]); // stampa della Matrice

	// copie
	void cpVetInMatR(int C, int in[][c], int rg, int a[]); // copia Vettore in una riga della Matrice
	void cpVetInMatC(int R, int in[][c], int cl, int a[]); // copia Vettore in una colonna della Matrice
	
	// estrazione
	void vetFromMat(int C, int in[][c], int iC, int a[]); // copia tutta la matrice Matrice in un Vettore
	void vetFromMatR(int C, int in[][c], int rg, int a[]); // copia una riga della Matrice in un Vettore
	void vetFromMatC(int C, int in[][c], int cl, int a[]); // copia una colonna della Matrice in un Vettore
#endif