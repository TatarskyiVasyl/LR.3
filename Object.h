#pragma once

class Object
{
    static unsigned int count;

public:
    static unsigned int Count() { return count; }

    Object();
    Object(const Object&);
    Object& operator = (const Object&) { return *this; }
    ~Object();
};
