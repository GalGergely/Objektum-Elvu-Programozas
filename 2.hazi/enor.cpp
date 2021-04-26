#include "enor.h"

using namespace std;

    Enor::Enor(const std::string &filename){
        _f.open(filename);
        if(_f.fail()) throw FILE_OPEN_ERROR;
    }

    void Enor::first(){
        _st=read(_cur.f);
        if(_st == abnorm) {throw FILE_OPEN_ERROR; }
        _st=read(_cur.c);
        _st=read(_cur.n);
    }

    void Enor::next(){
        _st=read(_i);
        _end=_st==abnorm;
        if(!_end){
            _cur.f=_cur.c;
            _cur.c=_cur.n;
            _cur.n=_i;
        }
    }

    Nums Enor::current() const{
        return _cur;
    }

    bool Enor::end() const{
        return _end;
    }

    Enor::Status Enor::read(int &e){
        _f >> e;
        return _f.fail() ? abnorm : norm;
    }