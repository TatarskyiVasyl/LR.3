#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif
#include "Vector3D.h"
#include <limits>

using namespace std;

struct Fields { double a, b, c; };
struct Example { char c; double d; int i; };
#pragma pack(push, 1)
struct FieldsPacked { double a, b, c; };
struct ExamplePacked { char c; double d; int i; };
#pragma pack(pop)

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    cout << "=== Базовий клас Triad ===" << endl;
    Triad t1, t2(1, 2, 3), t3(t2), t4 = makeTriad(1, 2, 4);
    cout << "t1 = " << t1 << ", t2 = " << t2 << ", t3 = " << t3 << ", t4 = " << t4 << endl;
    cout << "t2 vs t4:  == " << (t2 == t4) << "  != " << (t2 != t4)
        << "  > " << (t2 > t4) << "  < " << (t2 < t4)
        << "  >= " << (t2 >= t4) << "  <= " << (t2 <= t4) << endl;
    cout << "t2 vs t3:  == " << (t2 == t3) << "  >= " << (t2 >= t3)
        << "  <= " << (t2 <= t3) << "  > " << (t2 > t3) << endl;
    t1.setFirst(5); t1.setSecond(6); t1.setThird(7);
    cout << "t1 після змін = " << t1 << endl;

    cout << "\n=== Відкритий нащадок Vector3D ===" << endl;
    Vector3D v1, v2(1, 2, 3), v3(4, 5, 6), v4(v2), v5 = t4;
    cout << "v1 = " << v1 << ", v2 = " << v2 << ", v3 = " << v3
        << ", v4 = " << v4 << ", v5 (з Triad) = " << v5 << endl;
    cout << "v2 + v3 = " << v2 + v3 << endl;
    cout << "v3 - v2 = " << v3 - v2 << endl;
    cout << "v2 * v3 = " << v2 * v3 << endl;

    cout << "++v2 = ";  cout << ++v2 << endl;
    cout << "v2++ = ";  cout << v2++ << endl;
    cout << "v2 після v2++ = " << v2 << endl;
    cout << "--v2 = ";  cout << --v2 << endl;
    cout << "v2-- = ";  cout << v2-- << endl;
    cout << "v2 після v2-- = " << v2 << endl;

    v1 = v3;
    string s = v1;
    cout << "v1 = v3 -> " << s << endl;
    v1.setX(10);
    cout << "v1.setX(10) -> x = " << v1.getX() << ", y = " << v1.getY()
        << ", z = " << v1.getZ() << endl;

    cout << "\nУспадковані операції порівняння (правило Triad):" << endl;
    cout << "v2 < v3: " << (v2 < v3) << ", v2 == v4: " << (v2 == v4)
        << ", v3 >= v2: " << (v3 >= v2) << endl;

    cout << "\nВведіть вектор v1 (операція >> успадкована від Triad):" << endl;
    cin >> v1;
    cout << "v1 = " << v1 << endl;

    Vector3D m = makeVector3D(7, 8, 9);
    cout << "makeVector3D(7, 8, 9) = " << m << endl;

    Triad& tr = v2;
    cout << "через Triad&: " << tr << endl;

    cout << "\n=== Масиви ===" << endl;
    Vector3D arr[3] = { Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1) };
    Vector3D sum, maxV = arr[0];
    for (int i = 0; i < 3; i++)
    {
        sum = sum + arr[i];
        if (arr[i] > maxV) maxV = arr[i];
    }
    cout << "сума = " << sum << ", найбільший за Triad = " << maxV << endl;

    Vector3D* dyn = new Vector3D[2]{ Vector3D(1, 1, 1), Vector3D(2, 2, 2) };
    cout << "dyn[0] * dyn[1] = " << dyn[0] * dyn[1] << endl;
    delete[] dyn;

    cout << "\n=== Розміри ===" << endl;
    cout << "sizeof(Triad) = " << sizeof(Triad)
        << ", sizeof(Vector3D) = " << sizeof(Vector3D) << endl;
    cout << "поля класу без pack(1): " << sizeof(Fields)
        << ", з #pragma pack(1): " << sizeof(FieldsPacked) << endl;
    cout << "для порівняння {char, double, int}: без pack(1) = " << sizeof(Example)
        << ", з #pragma pack(1) = " << sizeof(ExamplePacked) << endl;

    cout << "\n=== Перевірка параметрів ===" << endl;
    Vector3D bad = makeVector3D(1, numeric_limits<double>::quiet_NaN(), 0);
    (void)bad;
    cout << "сюди програма не дійде" << endl;
    return 0;
}
