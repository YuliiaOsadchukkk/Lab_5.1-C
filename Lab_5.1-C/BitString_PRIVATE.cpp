//BitString_PRIVATE.cpp
#include "BitString_PRIVATE.h"

BitString_PRIVATE operator ^ (BitString_PRIVATE& a, BitString_PRIVATE& b)
{
    BitString_PRIVATE t;
    t.SetFirst(a.GetFirst() ^ b.GetFirst());
    t.SetSecond(a.GetSecond() ^ b.GetSecond());
    return t;
}

BitString_PRIVATE operator << (BitString_PRIVATE& a, int n)
{
    BitString_PRIVATE t = a;
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

BitString_PRIVATE operator >> (BitString_PRIVATE& a, int n)
{
    BitString_PRIVATE t = a;
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
ostream& operator << (ostream& out, const BitString_PRIVATE& r)
{
    out << string(r);
    return out;
}
istream& operator >> (istream& in, BitString_PRIVATE& r) throw(logic_error)
{
    long first, second;
    cout << "first = "; in >> first;
    cout << "second = "; in >> second;

    if ((first < 0 || first>20) && (second < 0 || second>20))
        throw logic_error("Condition is not met");

    r.SetFirst(first);
    r.SetSecond(second);

    return in;
}

BitString_PRIVATE& BitString_PRIVATE::operator ++() throw(MyException)
{
    SetFirst(GetFirst() + 1);
    if (GetSecond() > 20)
        throw logic_error("Number is bigger than 20");
    return *this;
}
BitString_PRIVATE& BitString_PRIVATE::operator --()  throw(MyDerivedException)
{
    SetFirst(GetFirst() - 1);
    if (GetFirst() < 0)
        throw new MyDerivedException();
    return *this;
}
BitString_PRIVATE BitString_PRIVATE::operator ++(int) throw(logic_error)
{
    BitString_PRIVATE t(*this);
    SetSecond(GetSecond() + 1);
    if (GetSecond() > 20)
        throw logic_error("Number is bigger than 20");
    return t;
}
BitString_PRIVATE BitString_PRIVATE::operator --(int) throw(MyDerivedException)
{
    BitString_PRIVATE t(*this);
    SetSecond(GetSecond() - 1);
    if (GetFirst() < 0)
        throw MyDerivedException();
    return t;
}
