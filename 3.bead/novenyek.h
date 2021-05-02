#pragma once

#include <string>
#include <iostream>

class Novenyek
{
public:
    enum fajtak{Deltafa,Parabokor,Puffancs};
    Novenyek(int nutrients, std::string name) 
    {_name=name; _nutrients=nutrients; _alive=true;}
    ~Novenyek();
   std::string getName() const {return _name;}
   int getNutrinets() const {return _nutrients;}
   fajtak getFajta() const {return _fajta;}
   void isAlive() { if(this->_nutrients<=0)
   {
    this->_alive=false; 
    std::cout<<_name<<" meghalt"<<std::endl;
   } }
   bool getAlive() {return _alive;}
   void alfa();
   void delta();
   void nincs();

protected:
    std::string _name;
    int _nutrients;
    bool _alive;
    fajtak _fajta;
};


class Deltafa : public Novenyek
{
public:
    Deltafa(int nutrients, std::string name) : Novenyek(nutrients,name) {_fajta=Novenyek::Deltafa;}
    ~Deltafa();
};

class Parabokor : public Novenyek
{
public:
    Parabokor(int nutrients, std::string name) : Novenyek(nutrients,name) {_fajta=Novenyek::Parabokor;}
    ~Parabokor();
};

class Puffancs : public Novenyek
{
public:
    Puffancs(int nutrients, std::string name) : Novenyek(nutrients,name)  {_fajta=Novenyek::Puffancs;}
    ~Puffancs();
};