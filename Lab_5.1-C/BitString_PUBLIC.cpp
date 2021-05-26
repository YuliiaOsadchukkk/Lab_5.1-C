
//BitString_PUBLIC.cpp
#include "BitString_PUBLIC.h"

BitString_PUBLIC operator ^ (BitString_PUBLIC& a, BitString_PUBLIC& b)
{
    BitString_PUBLIC t;
    t.SetFirst(a.GetFirst() ^ b.GetFirst());
    t.SetSecond(a.GetSecond() ^ b.GetSecond());
    return t;
}

BitString_PUBLIC operator << (BitString_PUBLIC& a, int n)
{
    BitString_PUBLIC t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.GetFirst() << 1;
        tmp[1] = t.GetFirst() << 1;

        if (t.GetSecond() & (1 << last_bit))
            tmp[0] |= (1 << 0);
        else
            tmp[0] &= ~(1 << 0);

        t.SetFirst(tmp[0]);
        t.SetSecond(tmp[1]);
    }
    return t;
}

BitString_PUBLIC operator >> (BitString_PUBLIC& a, int n)
{
    BitString_PUBLIC t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.GetFirst() >> 1;
        tmp[1] = t.GetSecond() >> 1;
        if (t.GetFirst() & (1 << 0))
            tmp[1] |= (1 << last_bit);
        else
            tmp[1] &= ~(1 << last_bit);

        t.SetFirst(tmp[0]);
        t.SetSecond(tmp[1]);
    }
    return t;
}
BitString_PUBLIC& BitString_PUBLIC::operator ++() throw(MyException)
{
    SetFirst(GetFirst() + 1);
    if (GetSecond() > 20)
        throw logic_error("Number is bigger than 20");
    return *this;
}
BitString_PUBLIC& BitString_PUBLIC::operator --()  throw(MyDerivedException)
{
    SetFirst(GetFirst() - 1);
    if (GetFirst() < 0)
        throw new MyDerivedException();
    return *this;
}
BitString_PUBLIC BitString_PUBLIC::operator ++(int) throw(logic_error)
{
    BitString_PUBLIC t(*this);
    SetSecond(GetSecond() + 1);
    if (GetSecond() > 20)
        throw logic_error("Number is bigger than 20");
    return t;
}
BitString_PUBLIC BitString_PUBLIC::operator --(int) throw(MyDerivedException)
{
    BitString_PUBLIC t(*this);
    SetSecond(GetSecond() - 1);
    if (GetFirst() < 0)
        throw MyDerivedException();
    return t;
}
