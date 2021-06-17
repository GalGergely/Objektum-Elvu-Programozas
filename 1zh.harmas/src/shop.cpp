#include "shop.h"

using namespace std;

shop::shop(const string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}

shop::~shop()
{
    _x.close();
}
void shop::first()
{
    _sx= norm;
    next();
    if( _sx==abnorm)
    {
        throw FILEERROR;
    }
}
void shop::next()
{
    _end = (_sx == abnorm);
    if(!end())
    {
        read();
    }
}

void shop::read()
{
    _x >> _cur;
    _sx = _x.fail() ? abnorm : norm;
    //cout << _cur << endl;
}

std::istream& operator>>(std::istream& is, Shops &h)
{
    std::string line;
    getline(is, line);
    istringstream ss(line);
    ss >> h.nev;
    h.shopdetail.clear();
    Shopdetails a;
    while (ss >> a.datum >>a.szam)
    {
        h.shopdetail.push_back(a);
    }
    h.osszkonyv=h.konyvszamlal();
    return is;
}


int Shops::konyvszamlal()
{
    int ossz=0;
    for(int i=0; i<shopdetail.size(); i++)
    {
        //cout<<ossz<<endl;
        ossz=ossz+shopdetail[i].szam;
    }
    return ossz;

}

