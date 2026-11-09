#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif
#include "Graduate.h"

using namespace std;

Student nextCourse(Student s)
{
    if (s.getCourse() < 6)
        s.setCourse(s.getCourse() + 1);
    return s;
}

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif

    cout << "=== Різні способи створення об'єктів Student ===" << endl;
    Student s1;
    Student s2("Іваненко Петро");
    Student s3("Коваль Ірина", 2);
    Student s4("Шевченко Олег", 3, 1003);
    Student s5(s4);
    cout << "\ns1: "; s1.print();
    cout << "s2: "; s2.print();
    cout << "s3: "; s3.print();
    cout << "s4: "; s4.print();
    cout << "s5: "; s5.print();

    cout << "\n=== Методи встановлення Student ===" << endl;
    s1.setName("Мельник Андрій");
    s1.setCourse(4);
    s1.setId(1001);
    cout << "s1: " << s1 << endl;
    s5 = s3;
    cout << "s5 = s3: " << s5 << endl;

    cout << "\n=== Різні способи створення об'єктів Graduate ===" << endl;
    Graduate g1;
    Graduate g2("Бондар Марія");
    Graduate g3("Лисенко Денис", "Розробка ігрового рушія");
    Graduate g4("Ткачук Олена", 5, "Аналіз мережевого трафіку");
    Graduate g5("Гончар Максим", 6, 2005, "Система розпізнавання образів");
    Graduate g6(g5);
    cout << "\ng1: "; g1.print();
    cout << "g2: "; g2.print();
    cout << "g3: "; g3.print();
    cout << "g4: "; g4.print();
    cout << "g5: "; g5.print();
    cout << "g6: "; g6.print();

    cout << "\n=== Зміна назви роботи та ідентифікаційного номера ===" << endl;
    g5.changeThesis("Система розпізнавання образів на основі нейромереж");
    g5.changeId(3005);
    cout << "g5: " << g5 << endl;
    g1 = g5;
    cout << "g1 = g5: " << g1 << endl;

    cout << "\n=== Введення з клавіатури ===" << endl;
    Graduate gi;
    cin >> gi;
    cout << "Введено: " << gi << endl;

    cout << "\n=== Принцип підстановки ===" << endl;
    Student t1 = nextCourse(s3);
    Student t2 = nextCourse(g4);
    cout << "nextCourse(s3): " << t1 << endl;
    cout << "nextCourse(g4): " << t2 << " (повернено як Student)" << endl;

    Student* ps = &g3;
    cout << "через Student*: " << ps->getName() << ", курс " << ps->getCourse() << endl;
    Student& rs = g2;
    cout << "через Student&: " << rs << endl;

    cout << "\n=== Масиви ===" << endl;
    Student arr[2] = { Student("Масив Перший", 1, 11), Student("Масив Другий", 2, 12) };
    Graduate garr[2] = { Graduate("Диплом Перший", 5, 21, "Тема 1"),
                         Graduate("Диплом Другий", 6, 22, "Тема 2") };
    Graduate* dyn = new Graduate[2];
    dyn[0] = garr[0];
    dyn[1].setName("Динамічний Дипломник");
    dyn[1].setThesis("Динамічна тема");
    for (int i = 0; i < 2; i++) { arr[i].print(); garr[i].print(); dyn[i].print(); }
    delete[] dyn;

    cout << "\n=== Перевірка параметрів ===" << endl;
    Student bad("Некоректний", 9);
    cout << "сюди програма не дійде" << endl;
    return 0;
}
