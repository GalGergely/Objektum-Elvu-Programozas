#pragma once
#include <iostream>
#include <fstream>

struct Nums
{
    int f;
    int c;
    int n;
};


class Enor
{
private:
    enum Status {abnorm, norm};
    std::ifstream _f;
    bool _end;
    Nums _cur; 
    int _i;
    Status _st;
public:
    enum Error {FILE_OPEN_ERROR};
    Enor(const std::string &filename);
    void first();
    void next();
    Nums current() const;
    bool end() const;
    Status read(int &e);
};
