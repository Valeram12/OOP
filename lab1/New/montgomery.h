#ifndef MONTGOMERY_H
#define MONTGOMERY_H


unsigned int bitLength(unsigned int n);
long long modular(long long base, long long exp, int mod);
class Montgomery
{
 public:
    unsigned long long  mod;
    unsigned long long  rrm;
    int BLn;
private:

     unsigned long long  reduce(Montgomery mont, unsigned long long  t);
     Montgomery Montg(unsigned long long  mod);
public:
    unsigned long long  MontPow(unsigned long long  x, unsigned long long  pow, unsigned long long  mod);
};
int MontgPow(int a, int b, int mod = 13);
int power(long long x, unsigned int y, int p);
#endif // MONTGOMERY_H
