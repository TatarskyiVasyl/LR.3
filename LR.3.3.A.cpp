#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif
#include "Vector3DPublic.h"
#include "Vector3DPrivate.h"
#include <limits>

using namespace std;

struct Fields { double x, y, z; };
struct Example { char c; double d; int i; };
#pragma pack(push, 1)
struct FieldsPacked { double x, y, z; };
struct ExamplePacked { char c; double d; int i; };
#pragma pack(pop)

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    cout << "=== Базовий клас Vector3D ===" << endl;
    Vector3D b1, b2(1, 2, 3), b3(b2);
    cout << "b1 = " << b1 << ", b2 = " << b2 << ", b3 = " << b3 << endl;
    b1.setX(4); b1.setY(5); b1.setZ(6);
    cout << "b1 після змін = " << b1 << " (x = " << b1.getX()
        << ", y = " << b1.getY() << ", z = " << b1.getZ() << ")" << endl;
    b1.set(7, 8, 9);
    cout << "b1.set(7, 8, 9) = " << b1 << endl;

    cout << "\n=== Відкрите успадкування: Vector3DPublic ===" << endl;
    Vector3DPublic p1, p2(1, 2, 3), p3(4, 5, 6), p4(p2), p5 = b2;
    cout << "p1 = " << p1 << ", p2 = " << p2 << ", p3 = " << p3
        << ", p4 = " << p4 << ", p5 (з базового) = " << p5 << endl;
    cout << "p2 + p3 = " << p2 + p3 << endl;
    cout << "p3 - p2 = " << p3 - p2 << endl;
    cout << "p2 * p3 = " << p2 * p3 << endl;

    cout << "++p2 = ";  cout << ++p2 << endl;
    cout << "p2++ = ";  cout << p2++ << endl;
    cout << "p2 після p2++ = " << p2 << endl;
    cout << "--p2 = ";  cout << --p2 << endl;
    cout << "p2-- = ";  cout << p2-- << endl;
    cout << "p2 після p2-- = " << p2 << endl;

    p1 = p3;
    string s1 = p1;
    cout << "p1 = p3 -> " << s1 << endl;

    cout << "\nВведіть вектор p1 (операція >> успадкована від базового класу):" << endl;
    cin >> p1;
    cout << "p1 = " << p1 << endl;

    Vector3D& br = p2;
    cout << "через Vector3D&: " << br << endl;

    cout << "\n=== Закрите успадкування: Vector3DPrivate ===" << endl;
    Vector3DPrivate q1, q2(1, 2, 3), q3(4, 5, 6), q4(q2), q5(b2);
    cout << "q1 = " << q1 << ", q2 = " << q2 << ", q3 = " << q3
        << ", q4 = " << q4 << ", q5 (з базового) = " << q5 << endl;
    cout << "q2 + q3 = " << q2 + q3 << endl;
    cout << "q3 - q2 = " << q3 - q2 << endl;
    cout << "q2 * q3 = " << q2 * q3 << endl;
    cout << "++q2 = ";  cout << ++q2 << endl;
    cout << "q2++ = ";  cout << q2++ << endl;
    cout << "--q2 = ";  cout << --q2 << endl;
    cout << "q2-- = ";  cout << q2-- << endl;
    q1 = q3;
    string s2 = q1;
    cout << "q1 = q3 -> " << s2 << endl;
    q1.setX(10);
    cout << "q1.setX(10) -> x = " << q1.getX() << endl;

    cout << "\nВведіть вектор q1 (операція >> визначена в нащадку):" << endl;
    cin >> q1;
    cout << "q1 = " << q1 << endl;

    cout << "\n=== Масиви ===" << endl;
    Vector3DPublic arr[3] = { Vector3DPublic(1, 0, 0), Vector3DPublic(0, 1, 0), Vector3DPublic(0, 0, 1) };
    Vector3DPublic sum;
    for (int i = 0; i < 3; i++)
        sum = sum + arr[i];
    cout << "сума масиву Vector3DPublic = " << sum << endl;

    Vector3DPrivate* dyn = new Vector3DPrivate[2]{ Vector3DPrivate(1, 1, 1), Vector3DPrivate(2, 2, 2) };
    cout << "dyn[0] * dyn[1] = " << dyn[0] * dyn[1] << endl;
    delete[] dyn;

    cout << "\n=== Розміри ===" << endl;
    cout << "sizeof(Vector3D) = " << sizeof(Vector3D)
        << ", sizeof(Vector3DPublic) = " << sizeof(Vector3DPublic)
        << ", sizeof(Vector3DPrivate) = " << sizeof(Vector3DPrivate) << endl;
    cout << "поля класу без pack(1): " << sizeof(Fields)
        << ", з #pragma pack(1): " << sizeof(FieldsPacked) << endl;
    cout << "для порівняння {char, double, int}: без pack(1) = " << sizeof(Example)
        << ", з #pragma pack(1) = " << sizeof(ExamplePacked) << endl;

    cout << "\n=== Перевірка параметрів ===" << endl;
    Vector3DPublic bad(1, numeric_limits<double>::infinity(), 0);
    cout << "сюди програма не дійде" << endl;
    return 0;
}
