#ifndef _PDCOMPLEXOPQ_H_
  #define _PDCOMPLEXOPQ_H_

  #include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include <math.h>
  typedef bool Bool;

  /**
   * Un tipo di dato opaco per i numeri complessi
   */
  typedef struct dcomplex *Pdcomplex;

  /**
   * Puntatore a struttura opaca
   */
  Pdcomplex mkPdcomplex(double re, double im);

  /**
   *  @brief libera la memoria puntata da *‘pc’ e setta *‘pc’ a NULL
   */
  void dsPdcomplex(Pdcomplex *pc);

  Pdcomplex sum(Pdcomplex c1, Pdcomplex c2);

  Pdcomplex product(Pdcomplex c1, Pdcomplex c2);

  double modulus(Pdcomplex c);

  /**
   *  @brief Restituisce l’argomento nell’intervallo[−pi, +pi] radianti
   */
  double agument(Pdcomplex c);

  double re(Pdcomplex c);

  double im(Pdcomplex c);

  /**
   * @brief Controlla se le componenti di due complessi sono uguali a meno di un
          espilon reale
  */
  Bool equal(Pdcomplex c1, Pdcomplex c2, double epsilon);

#endif
