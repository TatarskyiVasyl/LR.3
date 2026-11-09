#include "Graduate.h"
#include <sstream>

Graduate::Graduate(void) : Student(), thesis(nullptr)
{
    setThesis("Тема не визначена");
    cout << "Graduate: конструктор за умовчанням" << endl;
}

Graduate::Graduate(const char* n) : Student(n), thesis(nullptr)
{
    setThesis("Тема не визначена");
    cout << "Graduate: конструктор з 1 параметром" << endl;
}

Graduate::Graduate(const char* n, const char* t) : Student(n), thesis(nullptr)
{
    setThesis(t);
    cout << "Graduate: конструктор з 2 параметрами" << endl;
}

Graduate::Graduate(const char* n, const int c, const char* t) : Student(n, c), thesis(nullptr)
{
    setThesis(t);
    cout << "Graduate: конструктор з 3 параметрами" << endl;
}

Graduate::Graduate(const char* n, const int c, const int i, const char* t)
    : Student(n, c, i), thesis(nullptr)
{
    setThesis(t);
    cout << "Graduate: конструктор з 4 параметрами" << endl;
}

Graduate::Graduate(const Graduate& r) : Student(r), thesis(nullptr)
{
    thesis = copyString(r.thesis);
    cout << "Graduate: конструктор копіювання" << endl;
}

Graduate& Graduate::operator = (const Graduate& r)
{
    if (this != &r)
    {
        Student::operator = (r);
        char* t = copyString(r.thesis);
        delete[] thesis;
        thesis = t;
    }
    return *this;
}

Graduate::~Graduate(void)
{
    cout << "Graduate: деструктор (" << (thesis ? thesis : "-") << ")" << endl;
    delete[] thesis;
}

void Graduate::setThesis(const char* value)
{
    if (value == nullptr || value[0] == '\0')
        error("тема дипломної роботи не може бути порожньою");
    char* t = copyString(value);
    delete[] thesis;
    thesis = t;
}

void Graduate::print() const
{
    cout << (string)*this << endl;
}

Graduate::operator string() const
{
    stringstream ss;
    ss << Student::operator string() << ", тема диплома: \"" << getThesis() << "\"";
    return ss.str();
}

ostream& operator << (ostream& out, const Graduate& r)
{
    return out << (string)r;
}

istream& operator >> (istream& in, Graduate& r)
{
    in >> static_cast<Student&>(r);
    string t;
    cout << "тема    = "; in >> ws; getline(in, t);
    r.setThesis(t.c_str());
    return in;
}
