#include <iostream>
#include "ultetes.h"
#include <Windows.h>

using namespace std;

//#define NORMAL_MODE
#ifdef NORMAL_MODE

int main(int argc, char const *argv[])
{
    SetConsoleOutputCP( CP_UTF8 );
    Ultetes u = Ultetes();
    try
    {
        u.read("infile2.txt");
        u.szimulacio();
    }
    catch(Error &e)
    {
        cout<<"Error"<<endl;
    }
    
    return 0;
}

#else //Vagyis ha nem volt definiálva a NORMAL_MODE
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include "ultetes.h"

TEST_CASE("inp1")
{
    SetConsoleOutputCP( CP_UTF8 );
    Ultetes u = Ultetes();
    u.read("infile1.txt");
    u.szimulacio();
    CHECK(u.getFinal()[0]->getName()=="Falánk");
    CHECK(u.getFinal()[1]->getName()=="Köpcös");
    CHECK(u.getFinal()[0]->getNutrinets()==20);
    CHECK(u.getFinal()[1]->getNutrinets()==12);
    CHECK(u.getFinal()[0]->getFajta()==2);
    CHECK(u.getFinal()[1]->getFajta()==1);
};

TEST_CASE("inp2")
{
    SetConsoleOutputCP( CP_UTF8 );
    Ultetes u = Ultetes();
    u.read("infile2.txt");
    u.szimulacio();
    CHECK(u.getFinal()[0]->getName()=="Falánk");
    CHECK(u.getFinal()[1]->getName()=="Furi");
    CHECK(u.getFinal()[2]->getName()=="Köpcös");
    CHECK(u.getFinal()[0]->getNutrinets()==7);
    CHECK(u.getFinal()[1]->getNutrinets()==5);
    CHECK(u.getFinal()[2]->getNutrinets()==3);
    CHECK(u.getFinal()[0]->getFajta()==2);
    CHECK(u.getFinal()[1]->getFajta()==0);
    CHECK(u.getFinal()[2]->getFajta()==1);
};

TEST_CASE("inp3")
{
    SetConsoleOutputCP( CP_UTF8 );
    Ultetes u = Ultetes();
    u.read("infile3.txt");
    u.szimulacio();
    CHECK(u.getFinal()[0]->getName()=="Falánk");
    CHECK(u.getFinal()[1]->getName()=="Furi");
    CHECK(u.getFinal()[2]->getName()=="Köpcös");
    CHECK(u.getFinal()[0]->getNutrinets()==20);
    CHECK(u.getFinal()[1]->getNutrinets()==18);
    CHECK(u.getFinal()[2]->getNutrinets()==12);
    CHECK(u.getFinal()[0]->getFajta()==2);
    CHECK(u.getFinal()[1]->getFajta()==1);
    CHECK(u.getFinal()[2]->getFajta()==1);
};

TEST_CASE("inp4")
{
    //ennek a számításnak a levezetését a kiszamolaskezzel-ben találni
    SetConsoleOutputCP( CP_UTF8 );
    Ultetes u = Ultetes();
    u.read("infile4.txt");
    u.szimulacio();
    CHECK(u.getFinal()[0]->getName()=="Falánk");
    CHECK(u.getFinal()[1]->getName()=="Furi");
    CHECK(u.getFinal()[2]->getName()=="Köpcös");
    CHECK(u.getFinal()[0]->getNutrinets()==10);
    CHECK(u.getFinal()[1]->getNutrinets()==11);
    CHECK(u.getFinal()[2]->getNutrinets()==5);
    CHECK(u.getFinal()[0]->getFajta()==2);
    CHECK(u.getFinal()[1]->getFajta()==1);
    CHECK(u.getFinal()[2]->getFajta()==1);
};
#endif