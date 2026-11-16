#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif
#include "Vector3D.h"
#include <limits>

using namespace std;

struct Fields { double x, y, z; };
struct Example { char c; double d; int i; };
#pragma pack(push, 1)
struct FieldsPacked { double x, y, z; };
struct ExamplePacked { char c; double d; int i; };
#pragma pack(pop)

Vector3D twice(Vector3D v)
{
    cout << "  всередині twice: Count = " << Object::Count() << endl;
    return v + v;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    cout << "=== Лічильник об'єктів ===" << endl;
    cout << "На початку: Object::Count() = " << Object::Count() << endl;

    Vector3D v1, v2(1, 2, 3), v3(4, 5, 6), v4(v2);
    cout << "v1 = " << v1 << ", v2 = " << v2 << ", v3 = " << v3 << ", v4 = " << v4 << endl;
    cout << "після створення 4 векторів: Count = " << Object::Count()
        << " (Vector3D::Count() = " << Vector3D::Count() << ")" << endl;

    {
        Vector3D inner(7, 8, 9);
        Object plain;
        cout << "у внутрішньому блоці: Count = " << Object::Count() << endl;
    }
    cout << "після виходу з блоку: Count = " << Object::Count() << endl;

    cout << "\n=== Операції ===" << endl;
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
    cout << "після присвоєння: Count = " << Object::Count() << " (присвоєння об'єктів не додає)" << endl;
    v1.setX(10);
    cout << "v1.setX(10) -> x = " << v1.getX() << ", y = " << v1.getY()
        << ", z = " << v1.getZ() << endl;

    cout << "\n=== Копіювання та тимчасові об'єкти ===" << endl;
    cout << "до виклику twice: Count = " << Object::Count() << endl;
    Vector3D d = twice(v2);
    cout << "d = twice(v2) = " << d << ", Count = " << Object::Count() << endl;

    cout << "\nВведіть вектор v1:" << endl;
    cin >> v1;
    cout << "v1 = " << v1 << endl;

    cout << "\n=== Масиви ===" << endl;
    cout << "до масивів: Count = " << Object::Count() << endl;
    Vector3D arr[3] = { Vector3D(1, 0, 0), Vector3D(0, 1, 0), Vector3D(0, 0, 1) };
    cout << "після масиву з 3 елементів: Count = " << Object::Count() << endl;
    Vector3D* dyn = new Vector3D[2]{ Vector3D(1, 1, 1), Vector3D(2, 2, 2) };
    cout << "після динамічного масиву з 2 елементів: Count = " << Object::Count() << endl;
    cout << "dyn[0] * dyn[1] = " << dyn[0] * dyn[1] << endl;
    delete[] dyn;
    cout << "після delete[]: Count = " << Object::Count() << endl;

    cout << "\n=== Розміри ===" << endl;
    cout << "sizeof(Object) = " << sizeof(Object)
        << ", sizeof(Vector3D) = " << sizeof(Vector3D) << endl;
    cout << "поля класу без pack(1): " << sizeof(Fields)
        << ", з #pragma pack(1): " << sizeof(FieldsPacked) << endl;
    cout << "для порівняння {char, double, int}: без pack(1) = " << sizeof(Example)
        << ", з #pragma pack(1) = " << sizeof(ExamplePacked) << endl;

    cout << "\n=== Перевірка параметрів ===" << endl;
    Vector3D bad(1, numeric_limits<double>::infinity(), 0);
    (void)bad;
    cout << "сюди програма не дійде" << endl;
    return 0;
}
