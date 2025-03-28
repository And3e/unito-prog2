#include "pdcomplexOpq.h"

// #define ABS(x) ((x) > 0) ? (x) : -(x);
double ABS(double x) {
  if (x > 0) {
    return x;
  }
  return -x;
}

struct dcomplex {
  double re;
  double im;
};

Pdcomplex mkPdcomplex(double re, double im) {
  Pdcomplex c;
  c = malloc(sizeof(struct dcomplex));
  c->re = re;
  c->im = im;
  return c;
}

void dsPdcomplex(Pdcomplex *pc) {
  free(*pc);
  *pc = NULL;
}

Pdcomplex sum(Pdcomplex c1, Pdcomplex c2) {
  return mkPdcomplex(c1->re + c2->re, c1->im + c2->im);
}

Pdcomplex product(Pdcomplex c1, Pdcomplex c2) {
  return mkPdcomplex((c1->re * c2->re) - (c1->im * c2->im),
                     (c1->re * c2->im) - (c1->im * c2->re));
}

double modulus(Pdcomplex c) { return sqrt((c->re * c->re) + (c->im * c->im)); }

double agument(Pdcomplex c) { return atan2(c->im, c->re); }

double re(Pdcomplex c) { return c->re; }

double im(Pdcomplex c) { return c->im; }

Bool equal(Pdcomplex c1, Pdcomplex c2, double epsilon) {
  return (ABS(c1->re - c2->re) <= epsilon) && (ABS(c1->im - c2->im) <= epsilon);
}