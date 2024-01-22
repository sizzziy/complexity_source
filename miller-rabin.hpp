#include <bits/stdc++.h>
using namespace std;

namespace MillerRabinTest {
    template <typename T>
    T binpow(T x, T p, T mod) {
        if (p == 0) {
            return 1;
        }
        if (p % 2 == 0) {
            T xp = binpow(x, p / 2, mod);
            return xp * xp % mod;
        }
        return binpow(x, p - 1, mod) * x % mod;
    }

    template <typename T>
    static bool CheckCompositeness(T x, auto rnd, size_t maxIterations = 1000) {
        if (x % 2 == 0) {
            return true;
        }
        T previous = x - 1;
        T n = 0;
        while (previous % 2 == 0) {
            ++n;
            previous /= 2;
        }
        T m = previous;
        for (size_t iter = 0; iter < maxIterations; ++iter) {
            T a = rnd() % (x - 3) + 2;
            T powered = binpow(a, m, x);
            T y = x - 1;
            for (size_t s = 0; s < n; ++s) {
                y = powered * powered % x;
                if (y == 1 && powered != 1 && powered != x - 1) {
                    return true;
                }
                powered = y;
            }
            if (powered != 1) {
                return true;
            }
        }
        return false;
    }
};