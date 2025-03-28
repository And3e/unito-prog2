#include "pdcomplexOpq.h"

// #define ABS(x) ((x) > 0) ? (x) : -(x);
double ABS(double x) {
  if (x > 0) {
    return x;
  }
  return -x;
}

struct dcomplex {
  double modulus;
  double argument;
};

Pdcomplex mkDcomplex(double re, double im) {
  Pdcomplex c;
  c = malloc(sizeof(struct dcomplex));
  c->modulus = sqrt((re * re) + (im * im));
  c->argument = atan2(im, re);
  return c;
}

void dsDcomplex(Pdcomplex *pc) {
  free(*pc);
  *pc = NULL;
}

Pdcomplex sum(Pdcomplex c1, Pdcomplex c2) {
  return mkPdcomplex(re(c1) + re(c2), im(c1) + im(c2));
}

Pdcomplex product(Pdcomplex c1, Pdcomplex c2) {
  Pdcomplex c;
  c = malloc(sizeof(struct dcomplex));
  c->modulus = c1->modulus * c2->modulus;
  c->argument = c1->argument + c2->argument;
  return c;
}

double modulus(Pdcomplex c) { return c->modulus; }

double agument(Pdcomplex c) { return c->argument; }

double re(Pdcomplex c) { return c->modulus * cos(c->argument); }

double im(Pdcomplex c) { return c->modulus * sin(c->argument); }

Bool equal(Pdcomplex c1, Pdcomplex c2, double epsilon) {
  return (ABS(re(c1) - re(c2) <= epsilon) && (ABS(im(c1) - im(c2) <= epsilon)));
}