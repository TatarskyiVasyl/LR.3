#include "Student.h"
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <stdexcept>

void Student::error(const char* msg)
{
#ifdef UNIT_TEST
    throw invalid_argument(msg);
#else
    cout << "Помилка: " << msg << endl;
    exit(1);
#endif
}

char* Student::copyString(const char* s)
{
    const size_t len = strlen(s) + 1;
    char* t = new char[len];
    memcpy(t, s, len);
    return t;
}

Student::Student(void) : name(nullptr), course(1), id(1)
{
    setName("Без імені");
    cout << "Student: конструктор за умовчанням" << endl;
}

Student::Student(const char* n) : name(nullptr), course(1), id(1)
{
    setName(n);
    cout << "Student: конструктор з 1 параметром" << endl;
}

Student::Student(const char* n, const int c) : name(nullptr), course(1), id(1)
{
    setCourse(c);
    setName(n);
    cout << "Student: конструктор з 2 параметрами" << endl;
}

Student::Student(const char* n, const int c, const int i) : name(nullptr), course(1), id(1)
{
    setCourse(c);
    setId(i);
    setName(n);
    cout << "Student: конструктор з 3 параметрами" << endl;
}

Student::Student(const Student& r) : name(nullptr), course(r.course), id(r.id)
{
    name = copyString(r.name);
    cout << "Student: конструктор копіювання" << endl;
}

Student& Student::operator = (const Student& r)
{
    if (this != &r)
    {
        char* t = copyString(r.name);
        delete[] name;
        name = t;
        course = r.course;
        id = r.id;
    }
    return *this;
}

Student::~Student(void)
{
    cout << "Student: деструктор (" << (name ? name : "-") << ")" << endl;
    delete[] name;
}

void Student::setName(const char* value)
{
    if (value == nullptr || value[0] == '\0')
        error("ім'я студента не може бути порожнім");
    char* t = copyString(value);
    delete[] name;
    name = t;
}

void Student::setCourse(const int value)
{
    if (value < 1 || value > 6)
        error("курс має бути в межах від 1 до 6");
    course = value;
}

void Student::setId(const int value)
{
    if (value <= 0)
        error("ідентифікаційний номер має бути додатним");
    id = value;
}

void Student::print() const
{
    cout << (string)*this << endl;
}

Student::operator string() const
{
    stringstream ss;
    ss << "Студент: " << getName() << ", курс " << getCourse()
        << ", ID " << getId();
    return ss.str();
}

ostream& operator << (ostream& out, const Student& r)
{
    return out << (string)r;
}

istream& operator >> (istream& in, Student& r)
{
    string n;
    int c, i;
    cout << "ім'я    = "; in >> ws; getline(in, n);
    cout << "курс    = "; in >> c;
    cout << "ID      = "; in >> i;
    r.setName(n.c_str());
    r.setCourse(c);
    r.setId(i);
    return in;
}