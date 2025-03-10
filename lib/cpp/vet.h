#ifndef _VET_H_
	#define _VET_H_
	// base
	void randVet(int d, int a[], int min, int max);
	void sBVet(int d, int a[], bool cresc); // bubble sort
	void sSVet(int d, int a[], bool cresc); // selection sort vettore

	// stampa
	void outVet(int d, int a[]);

	// ricerca
	int rDVet(int x, int a[], int d); // dicotomic research
	int rSVet(int x, int a[], int d); // selection research
#endif