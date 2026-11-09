#pragma once
#include <iostream>
#include <string>

using namespace std;

class Student
{
    char* name;
    int course;
    int id;

protected:
    static void error(const char* msg);
    static char* copyString(const char* s);

public:
    Student(void);
    Student(const char* n);
    Student(const char* n, const int c);
    Student(const char* n, const int c, const int i);
    Student(const Student& r);
    Student& operator = (const Student& r);
    ~Student(void);

    const char* getName() const { return name; }
    int getCourse() const { return course; }
    int getId() const { return id; }

    void setName(const char* value);
    void setCourse(const int value);
    void setId(const int value);

    void print() const;

    operator string() const;
    friend ostream& operator << (ostream& out, const Student& r);
    friend istream& operator >> (istream& in, Student& r);
};
