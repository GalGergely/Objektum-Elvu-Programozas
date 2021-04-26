#include <iostream>
#include "enor.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int aktualCount=1;

    char const *filename="input.txt";
    if(argc==2){
        filename=argv[1];
    }

    Enor t(filename);

    t.first();
    Nums i = t.current();
    //cout << i.f << " " << i.c << " " << i.n << endl;
    if (i.f == i.c)
    {
        aktualCount++;
    } 
    else 
    {
        cout << i.f << " " << aktualCount << endl;
    }

    t.next();
    while (!t.end())
    {
        i = t.current();
        if (i.f == i.c)
        {
            aktualCount++;
        }
        else
        {
            cout << i.f << " " << aktualCount << endl;
            aktualCount = 1;
        }
        
        t.next();
    }
    if (i.c == i.n)
    {
        aktualCount++;
        cout << i.c << " " << aktualCount << endl;
    }
    else
    {
        cout << i.c << " " << aktualCount << endl;
        cout << i.n << " " << 1 << endl;
    }

    return 0;
}
