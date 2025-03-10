#include "base.h"
#include "vet.h"

// base
void randVet(int d, int a[], int min, int max){
	for(int i=0; i<d; i++){
		a[i]=random(min, max);
	}
}

void sBVet(int d, int a[], bool cresc){ // bubble sort
	for(int i=0; i<d-1; i++){
		for(int k=0; k<(d-1)-i; k++){
			if(cresc){
				if(a[k]>a[k+1]){
					swap(a[k], a[k+1]);
				}
			}
			else{
				if(a[k]<a[k+1]){
					swap(a[k], a[k+1]);
				}
			}
		}
	}
}

void sSVet(int d, int a[], bool cresc){ // selection sort vettore
	int x;
	for(int i=0; i<d-1; i++){
		x=i;
		for(int k=i+1; k<d; k++){
			if(cresc){
				if(a[k]<a[x]){
					x=k;
				}
			}
			else{
				if(a[k]>a[x]){
					x=k;
				}
			}
		}
		swap(a[i], a[x]);
	}
}

// stampa
void outVet(int d, int a[]){
	for(int i=0; i<d; i++){
		cout<<"|"<<a[i]<<"| ";
	}
}

// ricerca
int rDVet(int x, int a[], int d){ // dicotomic research
	int sx=0, dx=d-1, m=(sx+dx)/2, e=-1;

	sBVet(d, a, true);

	do{
		if(a[m]>x){
			dx=m-1;
		}
		else if(a[m]<x){
			sx=m+1;
		}
		else{
			e=m;
		}
		m=(sx+dx)/2;
	}while(sx<=dx && e==-1);

	// se e=-1 --> elemento non trovato
	return e;
}

int rSVet(int x, int a[], int d){ // selection research
	int e=-1;

	sBVet(d, a, true);

	for(int i=0; i<d; i++){
		if(a[i]==x){
			e=i;
			break;
		}
	}

	// se e=-1 --> elemento non trovato
	return e;
}