#include <iostream>
#include "filesystem.h"

using namespace std;

int main()
{
    FileSystem* sys = new FileSystem;

    sys->root.add(new File(2));

    Folder* f = new Folder();
    sys->root.add(f);
    f->add(new File(20));
    f->add(new File(10));

    Folder* ff = new Folder();
    f->add(ff);
    ff->add(new File(100));

    sys->root.add(new File(3));
    sys->root.add(new Folder());

    cout<<sys->root.getSize()<<endl;
    if(sys->root.getSize() == 135){
        cout << "Helyes eredmeny!" <<endl;
    }else{
        cout << "Helytelen eredmeny!" <<endl;
    }

    delete sys;

    return 0;
}