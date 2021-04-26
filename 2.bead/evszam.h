#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <ostream>

struct Sporteredmenyek
{
    std::string sportag;
    int helyezes; 
};

struct Evszam
{
    std::string nev;
    int evszam;
    friend std::istream &operator>>(std::istream &is, Evszam &h);
    friend std::ostream& operator<<(std::ostream& out, Evszam &s);
    std::vector <Sporteredmenyek> eredmeny;
};

class Evszamok
{
public:
    enum Errors { FILEERROR };
    Evszamok(const std::string &str);
    ~Evszamok();
    bool end() const { return _end; }
    void first();
    void read();
    void next();
    Evszam current() const { return _cur; }
    Evszam previous() const { return _prev; }
    int nameChecks(std::string line);

private:
    enum Status { abnorm, norm };
    Evszam _cur;
    Evszam _prev;
    std::ifstream _x;
    Status _sx;
    bool _end=false;
};