//BitStringBase.cpp
#include "BitStringBase.h"
using namespace std;

BitStringBase::BitStringBase()
    : first(0), second(0)
{}

BitStringBase::BitStringBase(const BitStringBase& obj)
{
    first = obj.first;
    second = obj.second;
}

BitStringBase::BitStringBase(const long& first, const long& second) throw(logic_error)
{
    if ((first < 0 || first>20) && (second < 0 || second>20))
        throw logic_error("Condition is not met");

    this->SetFirst(first);
    this->SetSecond(second);
}

BitStringBase& BitStringBase::operator = (const BitStringBase& pr)
{
    first = pr.first;
    second = pr.second;
    return *this;
}
BitStringBase::operator string() const
{
    stringstream ss;
    ss << first << ", " << second;
    return ss.str();
}
ostream& operator << (ostream& out, const BitStringBase& r)
{
    out << string(r);
    return out;
}
istream& operator >> (istream& in, BitStringBase& r) throw(logic_error)
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
