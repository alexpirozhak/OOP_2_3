//
// Created by Max on 20.03.2024.
//

#ifndef OOP_LAB_2_3_LONGLONG_H
#define OOP_LAB_2_3_LONGLONG_H


#include <string>
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

class LongLong
{
private:
    long highPart;
    long lowPart;

public:
    LongLong();

    LongLong(long highPartValue, long lowPartValue);

    LongLong(const LongLong &other);

    long getHighPart() const;

    void setHighPart(long value);

    long getLowPart() const;

    void setLowPart(long value);

    LongLong &operator++();

    LongLong &operator--();

    LongLong operator++(int);

    LongLong operator--(int);

    LongLong &operator=(const LongLong &longLong);

    operator string() const;

    friend ostream &operator<<(ostream &out, const LongLong &longLong);

    friend istream &operator>>(istream &in, LongLong &longLong);

    friend LongLong operator-(const LongLong &num1, const LongLong &num2);

    friend double operator/(const LongLong &num1, const LongLong &num2);

    friend bool operator==(const LongLong &num1, const LongLong &num2);

    friend bool operator!=(const LongLong &num1, const LongLong &num2);

    friend bool operator>(const LongLong &num1, const LongLong &num2);

    friend bool operator<(const LongLong &num1, const LongLong &num2);

    friend bool operator>=(const LongLong &num1, const LongLong &num2);

    friend bool operator<=(const LongLong &num1, const LongLong &num2);
};


#endif //OOP_LAB_2_3_LONGLONG_H
