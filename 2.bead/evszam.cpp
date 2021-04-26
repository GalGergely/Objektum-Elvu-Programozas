#include "evszam.h"

using namespace std;

Evszamok::Evszamok(const string &str)
{
    _x.open(str);
    if(_x.fail()) throw FILEERROR;
}
Evszamok::~Evszamok(){ _x.close();}

void Evszamok::read()
{
    _x >> _cur;
    _sx = _x.fail() ? abnorm : norm;
    //cout << _cur << endl;
}

int nameChecks(string line)
{
    int i = 0;
    for(char& c : line){
        if(!isdigit(c))
        {
            i++;
        }
        else { break; }
    }
    return i;
}

std::istream& operator>>(std::istream& is, Evszam &h)
{
    std::string line;
    getline(is, line);
    h.nev=line.substr(0,nameChecks(line));
    istringstream ss(line.substr(nameChecks(line)));
    h.evszam = 0;
    ss >> h.evszam;
    h.eredmeny.clear();
    Sporteredmenyek a;
    while (ss >> a.sportag >> a.helyezes) 
    {
        h.eredmeny.push_back(a);
    }
    return is;
}

std::ostream& operator<<(ostream& out, Evszam& s)
{
    out << "Nev: " << s.nev;
    out << endl <<"Ev: " << s.evszam << endl << "Eredmenyek: "<< endl;
    for(int i = 0; i < s.eredmeny.size(); i++)
    {
        out << s.eredmeny[i].sportag << ": " << s.eredmeny[i].helyezes << ". helyezes" << endl;
    }
    return out;
}
void Evszamok::first()
{
    read();
    _prev=_cur;
}

void Evszamok::next()
{
    _prev = _cur;
    _end = (_sx == abnorm);
    if(!end())
    {
        read();
        _sx = _x.fail() ? abnorm : norm;
    }
}