#include "base.h"
#include "mat.h"

int M;

// inizializzazione
void insRC(int &R, int &C){ // menu inserimento righe e colonne
	do{
		cout<<" *Inserisci il numero di righe (max: "<<r<<") ";
		cin>>R;
	}while(R<1 || R>r);

	do{
		cout<<" *Inserisci il numero di colonne (max: "<<c<<") ";
		cin>>C;
	}while(C<1 || C>c);
}

void insmM(int &min, int &max){ // menu inserimento min e max
	cout<<"\n *Inserisci il range di estrazione: ";
	cout<<"\n    *Range minimo: ";
	cin>>min;
	do{
		cout<<"    *Range massimo: ";
		cin>>max;
	}while(max<min);

	detM(min, max);
}

// base
void randMat(int R, int C, int in[][c], int min, int max){
	for(int i=0; i<R; i++){
		for(int k=0; k<C; k++){
			in[i][k]=random(min, max);
		}
	}
}

void sSMat(int R, int C, int in[][c]){ // selection sort matrice
	int x;
	for(int i=0; i<R; i++){
		for(int k=0; k<C; k++){
			x=k+1;
			for(int j=i; j<R; j++){
				for(int l=x; l<C; l++){
					if(in[j][l]<in[i][k]){
						swap(in[i][k], in[j][l]);
					}
				}
				x=0;
			}
		}
	}
}

// stampa
int countCifre(int n){
	bool e=false;
	if(n<0){
		n-=n*2;
		e=true;
	}
	else if(n>0){
		e=true;
	}
	string tmp=to_string(n);
	if(e){
		return tmp.size()+1;
	}
	return tmp.size();
}

void detM(int min, int max){ // per setw  --> outMat
	if(max<0){
		M=min;
	}
	else{
		M=max;
	}
	if(countCifre(M)<countCifre(min)){
		M=min;
	}
}

void outMat(int R, int C, int in[][c]){
	int j=0, d=countCifre(M);

	cout<<setw(d+3)<<"";
	for(int i=0; i<C; i++){
		cout<<" "<<setw(d)<<left<<i+1<<"  ";
	}
	cout<<"\n";

	for(int i=0; i<R; i++){
		j++;
		cout<<setw(d+1)<<right<<j<<"  ";
		for(int k=0; k<C; k++){
			if(in[i][k]>0){
				string tmp="+"+to_string(in[i][k]);
				cout<<"|"<<setw(d)<<right<<tmp<<"| ";
			}
			else{
				cout<<"|"<<setw(d)<<right<<in[i][k]<<"| ";
			}
		}
		cout<<"\n";
	}
}

// copie
void cpVetInMatR(int C, int in[][c], int rg, int a[]){
	for(int i=0; i<C; i++){
		in[rg][i]=a[i];
	}
}

void cpVetInMatC(int R, int in[][c], int cl, int a[]){
	for(int i=0; i<R; i++){
		in[i][cl]=a[i];
	}
}

// estrazione
void vetFromMat(int C, int in[][c], int iC, int a[]){
	for(int i=0; i<C; i++){
		a[i]=in[i][iC];
	}
}

void vetFromMatR(int C, int in[][c], int rg, int a[]){
	for(int i=0; i<C; i++){
		a[i]=in[rg][i];
	}
}

void vetFromMatC(int R, int in[][c], int cl, int a[]){
	for(int i=0; i<R; i++){
		a[i]=in[i][cl];
	}
}
