//
// Created by Max on 20.03.2024.
//

#include "LongLong.h"

LongLong::LongLong() : LongLong(0, 0)
{}

LongLong::LongLong(long highPartValue, long lowPartValue)
        : highPart(highPartValue), lowPart(lowPartValue)
{
    if (lowPart < 0)
        lowPart = 0;
}

LongLong::LongLong(const LongLong &other)
        : highPart(other.highPart), lowPart(other.lowPart)
{}

long LongLong::getHighPart() const
{
    return highPart;
}

void LongLong::setHighPart(long value)
{
    highPart = value;
}

long LongLong::getLowPart() const
{
    return lowPart;
}

void LongLong::setLowPart(long value)
{
    if (value >= 0)
        lowPart = value;
}

LongLong &LongLong::operator=(const LongLong &longLong)
{
    if (&longLong == this)
        return *this;

    highPart = longLong.highPart;
    lowPart = longLong.lowPart;
    return *this;
}

LongLong::operator string() const
{
    stringstream sout;
    sout << "(h=" << highPart << ";l=" << lowPart << ")";
    return sout.str();
}

ostream &operator<<(ostream &out, const LongLong &longLong)
{
    out << (string) longLong;
    return out;
}

istream &operator>>(istream &in, LongLong &longLong)
{
    in >> longLong.highPart;

    long lowPart;
    in >> lowPart;
    if (lowPart >= 0)
        longLong.lowPart = lowPart;

    return in;
}

LongLong operator-(const LongLong &num1, const LongLong &num2)
{
    LongLong result;
    result.highPart = num1.highPart - num2.highPart;
    result.lowPart = num1.lowPart - num2.lowPart;

    if (result.lowPart < 0)
    {
        result.highPart--;
        result.lowPart++;
        result.lowPart += LONG_MAX;
    }
    return result;
}

double operator/(const LongLong &num1, const LongLong &num2)
{
    double numerator = num1.highPart * (LONG_MAX + 1.0) + num1.lowPart;
    double denominator = num2.highPart * (LONG_MAX + 1.0) + num2.lowPart;
    return numerator / denominator;
}

bool operator==(const LongLong &num1, const LongLong &num2)
{
    return num1.highPart == num2.highPart && num1.lowPart == num2.lowPart;
}

bool operator!=(const LongLong &num1, const LongLong &num2)
{
    return !(num1 == num2);
}

bool operator>(const LongLong &num1, const LongLong &num2)
{
    if (num1.highPart > num2.highPart)
        return true;

    if (num1.highPart < num2.highPart)
        return false;

    return num1.lowPart > num2.lowPart;
}

bool operator<(const LongLong &num1, const LongLong &num2)
{
    if (num1.highPart < num2.highPart)
        return true;

    if (num1.highPart > num2.highPart)
        return false;

    return num1.lowPart < num2.lowPart;
}

bool operator>=(const LongLong &num1, const LongLong &num2)
{
    return !(num1 < num2);
}

bool operator<=(const LongLong &num1, const LongLong &num2)
{
    return !(num1 > num2);
}

LongLong &LongLong::operator++()
{
    ++highPart;
    return *this;
}

LongLong &LongLong::operator--()
{
    --highPart;
    return *this;
}

LongLong LongLong::operator++(int)
{
    LongLong copy = *this;
    lowPart++;
    return copy;
}

LongLong LongLong::operator--(int)
{
    LongLong copy = *this;
    lowPart--;
    return copy;
}
