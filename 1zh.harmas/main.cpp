#include <iostream>
#include "shop.h"


using namespace std;

int main(int argc, char const *argv[])
{
    string filename="inp.txt";
    if(argc==2)
    {
        filename=argv[1];
    }
    Shopdetails legtobb;
    try
    {
        shop t(filename);
        int cntr=0;
        for(t.first(); !t.end(); t.next())
        {
            if(t.current().osszkonyv>400)
            {
                cntr++;
            }
        }
        cout<<cntr<<" bolt van ahol tobb mint 400 konyv volt"<<endl;
    }
    catch(const shop::Errors& e)
    {
        std::cerr << "File open error" << '\n';
    }
    return 0;
}
