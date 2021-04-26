#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;

void printMenu();

int main(int argc, char const *argv[])
{

    Matrix a;
    Matrix b;
    Matrix z;
    int inp;
    bool ended = false;

    printMenu();

    while (!ended && cin >> inp) {
        switch (inp) {
            case 0:
                printMenu();
                break;
            case 1:
            default:
                ended = true;
                break;
            case 2:
                a.clear();
                cout<<"Gimme the size"<<endl;
                if (cin >> inp) {
                a.setRow(inp);
                a.setCol(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                a.set();
                 break;
            case 3:
                cout<<a.getRow()<<endl;
                cout<<a.getCol()<<endl;
                break;
            case 4:
                a.show();
                break;
            case 5:
            cout<<"Gimme matrix to sum with"<<endl;
            cout<<"First give me the size"<<endl;
            if (cin >> inp) {
                b.setRow(inp);
                b.setCol(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                if(a.checker()!=b.checker())
                {
                    cout<<"You cant summ 2 different sized matrixes silly"<<endl;
                    b.clear();
                    break;
                }
                else{
                    b.manual();
                    a.sum(b);
                    a.show();
                    break;
                }
                break;
            case 6:
            cout<<"Gimme matrix to multiplicate with"<<endl;
            cout<<"First gimme the size"<<endl;
            if (cin >> inp) {
                b.setRow(inp);
                b.setCol(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                if(a.checker()!=b.checker())
                {
                    cout<<"You cant multiplicate 2 different sized matrixes silly"<<endl;
                    b.clear();
                    break;
                }
                else{
                    b.manual();
                    z.mul(a, b);
                    z.show();
                    z.clear();
                    break;
                }
                break;
            case 7:
                a.clear();
                b.clear();
                z.clear();
                break;
            
        }
    }

    return 0;
}

void printMenu() {
   cout<<"0:Menu"<<endl;
   cout<<"1:Exit"<<endl;
   cout<<"2:Set size"<<endl;
   cout<<"3:Get size"<<endl;
   cout<<"4:Show the matrix"<<endl;
   cout<<"5:Summ"<<endl;
   cout<<"6:Multiplicate"<<endl;
   cout<<"7:Clear the matrix"<<endl;
}
