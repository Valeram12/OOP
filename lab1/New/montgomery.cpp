#include "montgomery.h"


unsigned int bitLength(unsigned int n)
{
    unsigned int count = 0;
    while (n)
    {
        count++;
        n >>= 1;
    }
    return count;
}


unsigned long long Montgomery::reduce(Montgomery mont, unsigned long long  t) {
    unsigned long long  a = t;
    int i;

    for (i = 0; i < mont.BLn; i++) {
        if ((a & 1) == 1) {
            a += mont.mod;
        }
        a = a >> 1;
    }

    if (a >= mont.mod) {
        a -= mont.mod;
    }
    return a;
}


unsigned long long Montgomery:: MontPow(unsigned long long  x, unsigned long long  pow, unsigned long long  mod) {
        Montgomery M;
        M.mod = mod;
        M.BLn = bitLength(mod);
        M.rrm = (1ULL << (M.BLn * 2)) % mod;
        unsigned long long  p = reduce(M, M.rrm);
        unsigned long long  main = reduce(M, x * M.rrm);
        unsigned long long  exp = pow;
        while (bitLength(exp) > 0) {
            if ((exp & 1) == 1) {
                p = reduce(M, p * main);
            }
            exp >>= 1;
            main = reduce(M, main * main);
        }
        return reduce(M, p);
}

int power(long long x, unsigned int y, int p)
{
    int res = 1;     // Initialize result

    x = x % p; // Update x if it is more than or
                // equal to p

    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0)
    {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res*x) % p;

        // y must be even now
        y = y>>1; // y = y/2
        x = (x*x) % p;
    }
    return res;
}






