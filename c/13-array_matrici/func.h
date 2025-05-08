#ifndef _FUNC_H_
  #define _FUNC_H_

  #include <stdio.h>
  #include <stdlib.h>

  // Scrivere una funzione char *binarizza(char *str) che, ricevuta in input una
  // stringa di caratteri qualsiasi str, crea dinamicamente un array di caratteri
  // di pari lunghezza più uno. La funzione deve quindi scandire la stringa
  // passata in input. Per ciascun suo elemento, se la codifica del carattere è un
  // numero pari, inserirà nella corrispondente posizione della stringa creata il
  // carattere 1, se invece tale codifica è un numero dispari, inserirà il
  // carattere 0. La funzione restituisce come risultato l'array così costruito
  // terminato dal carattere '\0' che lo rende una stringa C che può ad esempio
  // essere stampata.

  // Esempio. “auto” -> “0010”,  “arte” -> “0110”,  “ippopotamo” -> “0110101000”

  char *binarizza(char *str);

  // Scrivere una funzione int conv_palindroma(char *str) che dapprima invoca
  // binarizza sul  suo parametro e poi verifica se il risultato è palindromo,
  // restituendo 1 se lo è, 0 altrimenti.

  // Esempio. conv_palindroma(“auto”) -> 0 perché binarizza(“auto”) restituisce
  // “0010”, conv_palindroma(“arte”) -> 1 perché binarizza(“arte”) restituisce
  // “0110”

  int conv_palindroma(char *str);

  // Scrivere una funzione int *pari_dispari(int **str, int N) che, data in input
  // una matrice quadrata di numeri interi di lato pari a N, crea dinamicamente un
  // array di N interi e quindi assegna a ciascuno come valore il numero 1 se la
  // somma della riga di pari indice è pari, 0 altrimenti. L'array deve essere
  // restituito come risultato.
  
  // Esempio. Se la matrice è
  
  // 1  2  4                   il risultato sarà [0, 0, 1]  
  // 0  1  0
  // 1  2  3

  int *pari_dispari(int **str, int N);
  
#endif
