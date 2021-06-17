#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <ostream>

struct Shopdetails
{
    std::string datum="failed";
    int szam=0;

};
struct Shops
{
    std::string nev;
    std::vector <Shopdetails> shopdetail;
    friend std::istream &operator>>(std::istream &is, Shops &h);
    int konyvszamlal();
    int osszkonyv;


};

class shop
{
public:
    enum Errors { FILEERROR };
    shop(const std::string &str);
    ~shop();
    bool end() const { return _end; }
    void first();
    void read();
    void next();
    Shops current() const { return _cur; }

private:
    enum Status { abnorm, norm };
    Shops _cur;
    std::ifstream _x;
    Status _sx;
    bool _end=false;
};

#endif // SHOP_H
