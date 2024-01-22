#include "atkin.hpp"
#include "miller-rabin.hpp"
using namespace std;

mpz_class X;
long long Xll;

void run_primality() {
    auto res = Atkin(X);
    if (res == 0) {
        cout << "Proved primality!" << '\n';
    }
}

void run_compositeness() {
    auto res = MillerRabinTest::CheckCompositeness(Xll, mt19937_64());
    if (res == 1) {
        cout << "Proved compositeness!" << '\n';
    }
}

int main() {
    cin >> X;
    mpz_export(&Xll, 0, -1, sizeof Xll, 0, 0, X.get_mpz_t());
    std::thread t1(run_primality);
    std::thread t2(run_compositeness);
    t1.join();
    t2.join();
}