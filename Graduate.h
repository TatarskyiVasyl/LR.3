#pragma once
#include "Student.h"

class Graduate :
    public Student
{
    char* thesis;

public:
    Graduate(void);
    Graduate(const char* n);
    Graduate(const char* n, const char* t);
    Graduate(const char* n, const int c, const char* t);
    Graduate(const char* n, const int c, const int i, const char* t);
    Graduate(const Graduate& r);
    Graduate& operator = (const Graduate& r);
    ~Graduate(void);

    const char* getThesis() const { return thesis; }
    void setThesis(const char* value);

    void changeThesis(const char* newTitle) { setThesis(newTitle); }
    void changeId(const int newId) { setId(newId); }

    void print() const;

    operator string() const;
    friend ostream& operator << (ostream& out, const Graduate& r);
    friend istream& operator >> (istream& in, Graduate& r);
};
