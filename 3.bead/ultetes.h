#pragma once

#include "novenyek.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

enum Error {FILE_OPEN_ERROR,UNKNOWN_SPECIES};

class Ultetes
{
private:
    std::vector<Novenyek*> _novenyek;
    int _nap;
    int alfaIgeny=0;
    int deltaIgeny=0;
    string sugarzasmero;
    int nincsCntr=0;
    std::vector<Novenyek*> _final;

public:
    Ultetes() {};
    std::vector<Novenyek*> getFinal() {return _final;}
    void read(const std::string& fname);
    void szimulacio();
    void setSugarzas();
    void igenyek();
    void novenyek();
    void print();
};