//feladat leírás
#include <iostream>
#include <sstream>
//#include "../library/arrayenumerator.hpp"
//#include "../library/counting.hpp"
//#include "../library/enumerator.hpp"
//#include "../library/intervalenumerator.hpp"
//#include "../library/library_extend.hpp"
//#include "../library/linsearch.hpp"
#include "../library/maxsearch.hpp"
//#include "../library/procedure.hpp"
//#include "../library/selection.hpp"
#include "../library/seqinfileenumerator.hpp"
#include "../library/stringstreamenumerator.hpp"
#include "../library/summation.hpp"

using namespace std;

struct Orszag
{
    string regio;
    string nev;
    double meret;
    bool nincs30;
    friend istream& operator>>(istream& in, Orszag& e);
};
struct Ceg
{
    string nev;
    int bevetel;
    double reszesedes;
   friend istream& operator>>(istream& in, Ceg& e);
};

class MySummation : public Summation<Ceg, bool> {
    public:
    bool func(const Ceg& e) const override {return e.reszesedes<30;}
    bool neutral() const override {return true;}
    bool add( const bool& a, const bool& b) const override{return a && b;}
};

class MyMaxSearch : public MaxSearch<Orszag, int, Greater<int>> {
    public:
    int func(const Orszag& e) const override {return e.meret;}
    virtual bool  cond(const Orszag& e) const { return e.nincs30==0;}
};

istream& operator>>(istream& in, Orszag& e)
{
    string line;
    getline(in, line);
    stringstream is(line);
    is >> e.regio>>e.nev>>e.meret;
    //cout<<e.regio<<" "<<e.nev<<" "<<e.meret<<endl;
    StringStreamEnumerator<Ceg> enor(is);
    MySummation pr;
    pr.addEnumerator(&enor);
    pr.run();
    //cout<<e.nev<<endl;
    //cout<<pr.result()<<endl;
    e.nincs30=pr.result();
    //cout<<e.nincs30<<endl;
    return in;
}
istream& operator>>(istream& in, Ceg& e)
{

    in>>e.nev>>e.bevetel>>e.reszesedes;
    //cout<<e.nev<<" "<<e.bevetel<<" "<<e.reszesedes<<endl;
    return in;

}
struct Regio
{
    string nev;
    bool egyikgyartosemertelela30szazalekot;
};
class All : public Summation<Orszag,bool>{
    private:
    string _regio;

    public:
    All(const string& regio): _regio(regio){}
    bool func(const Orszag& e) const override {return e.nincs30==true;}
    bool neutral() const override {return false;}
    bool add( const bool& a, const bool& b) const override {return a || b;}

    bool whileCond(const Orszag& current) const override {return current.regio==_regio; }
    void first() override {}

};

class MyEnumerator : public Enumerator<Regio>{
    private:
    bool _end;
    Regio _cur;
    SeqInFileEnumerator<Orszag> _f;

    public:
        MyEnumerator(const string& fname): _f(fname) {}
        void first() override {_f.first();next();}
        void next() override {
            if( _end = _f.end()) return;
            string from = _f.current().regio;

            All p(from);
            p.addEnumerator(&_f);
            p.run();
            Regio c;
            c.nev=from;
            c.egyikgyartosemertelela30szazalekot = p.result();
            //cout<<c.egyikgyartosemertelela30szazalekot<<endl;
            _cur=c;
        }
        bool end() const override{return _end;}
        Regio current() const override{return _cur;}
};

class ConsoleOutput : public Summation<Regio,ostream>{
    public:
    string func(const Regio& e) const override {return e.nev + "\n";}
    ConsoleOutput(ostream * o): Summation(o){}
    bool cond(const Regio& e) const override { return e.egyikgyartosemertelela30szazalekot; }
};

int main(int argc, char const *argv[])
{
    try
    {
        MyEnumerator enor("input.txt");
        ConsoleOutput p(&cout);
        p.addEnumerator(&enor);
        p.run();
    }
    catch(SeqInFileEnumerator<Orszag>::Exceptions)
    {
        std::cerr <<"A file nem letezik"<< '\n';
    }

    return 0;
}
