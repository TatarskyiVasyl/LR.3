#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif
#include "Fraction.h"

using namespace std;

Pair maxPair(const Pair& a, const Pair& b)
{
    return (a >= b) ? a : b;
}

void compareAll(const Pair& a, const Pair& b)
{
    cout << a << " vs " << b << ":  "
        << "==" << (a == b) << "  !=" << (a != b)
        << "  >" << (a > b) << "  <" << (a < b)
        << "  >=" << (a >= b) << "  <=" << (a <= b) << endl;
}

void compareAll(const Fraction& a, const Fraction& b)
{
    cout << a << " vs " << b << ":  "
        << "==" << (a == b) << "  !=" << (a != b)
        << "  >" << (a > b) << "  <" << (a < b)
        << "  >=" << (a >= b) << "  <=" << (a <= b) << endl;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    cout << "=== Pair ===" << endl;
    Pair p1(3, 5), p2, p3(p1);
    p2.set(3, 7);
    cout << "p1 = " << p1 << ", p2 = " << p2 << ", p3 = " << p3 << endl;
    compareAll(p1, p2);
    compareAll(p1, p3);
    compareAll(Pair(4, 0), p2);

    p3.setFirst(1);
    p3.setSecond(9);
    cout << "p3 після змін: " << p3 << " (first = " << p3.getFirst()
        << ", second = " << p3.getSecond() << ")" << endl;

    cout << "\nВведіть пару p1:" << endl;
    cin >> p1;
    cout << "p1 = " << p1 << endl;

    cout << "\n=== Fraction ===" << endl;
    Fraction f1(3, 14), f2(3, 5), f3(f1), f4;
    Fraction f5 = Pair(2, 75);
    cout << "f1 = " << f1 << ", f2 = " << f2 << ", f3 = " << f3
        << ", f4 = " << f4 << ", f5 = " << f5 << endl;
    compareAll(f1, f2);
    compareAll(f1, f3);
    compareAll(f5, f1);

    f4.setInt(10);
    f4.setFrac(25);
    cout << "f4 після змін: " << f4 << " (ціла = " << f4.getInt()
        << ", дробова = " << f4.getFrac() << ")" << endl;

    cout << "\nВведіть дріб f4:" << endl;
    cin >> f4;
    cout << "f4 = " << f4 << endl;

    cout << "\n=== Принцип підстановки ===" << endl;
    Pair m1 = maxPair(p1, p2);
    Pair m2 = maxPair(f1, f2);
    cout << "maxPair(p1, p2) = " << m1 << endl;
    cout << "maxPair(f1, f2) = " << m2 << " (повернено як Pair)" << endl;

    Pair* pp = &f1;
    cout << "через Pair*: " << *pp << ", first = " << pp->getFirst() << endl;
    Pair& pr = f2;
    cout << "через Pair&: " << pr << endl;

    cout << "\n=== Масиви ===" << endl;
    Pair arr[3] = { Pair(1, 2), Pair(1, 1), Pair(0, 9) };
    Fraction farr[3] = { Fraction(1, 2), Fraction(1, 11), Fraction(0, 9) };
    Pair* dyn = new Pair[2]{ Pair(5, 5), Pair(5, 6) };
    Fraction* fdyn = new Fraction[2]{ Fraction(7, 1), Fraction(7, 25) };

    Pair maxP = arr[0];
    for (int i = 1; i < 3; i++)
        if (arr[i] > maxP) maxP = arr[i];
    cout << "max у масиві Pair: " << maxP << endl;

    Fraction maxF = farr[0];
    for (int i = 1; i < 3; i++)
        if (farr[i] > maxF) maxF = farr[i];
    cout << "max у масиві Fraction: " << maxF << endl;

    cout << "dyn: " << dyn[0] << ", " << dyn[1] << "  ->  max = "
        << maxPair(dyn[0], dyn[1]) << endl;
    cout << "fdyn: " << fdyn[0] << ", " << fdyn[1] << "  ->  max = "
        << maxPair(fdyn[0], fdyn[1]) << endl;

    delete[] dyn;
    delete[] fdyn;

    cout << "\n=== Перевірка параметрів ===" << endl;
    Fraction bad(-1, 5);
    cout << "сюди програма не дійде" << endl;
    return 0;
}