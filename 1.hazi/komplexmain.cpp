#include <bits/stdc++.h>
#include "komplex.h"

using namespace std;

void printMenu();

int main(void) {
    string file;
    int a,b;
    komplex r(0,0), p(0,0);

    int inp;
    bool ended = false;

    printMenu();

    while (!ended && cin >> inp) {
        switch (inp) {
            case 0:
                printMenu();
                break;
            case 1:
                 cout << "What is the value of the real part?\n";
                if (cin >> inp) {
                    r.setReal(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "What is the value of the imaginarius part?\n";
                if (cin >> inp) {
                    r.setImag(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                break;
            case 2:
                cout << "The value of the real part: " << r.getReal() << endl;
                cout << "The value of the imaginarius part: " << r.getImag() << endl;
                break;
            case 3:
                cout << "What is the value of the real part of the komplex number that you want to add?\n";
                if (cin >> inp) {
                    p.setReal(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "What is the value of the imaginarius part of the komplex number that you want to add?\n";
                if (cin >> inp) {
                    p.setImag(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "The sum of the two komplex numbers: ";
                 r.add(p);
                 cout<<endl;
                break;
            case 4:
                cout << "What is the value of the real part of the komplex number that you want to multiply with?\n";
                if (cin >> inp) {
                    p.setReal(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "What is the value of the imaginarius part of the komplex number that you want to multiply with?\n";
                if (cin >> inp) {
                    p.setImag(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "The product of the two komplex numbers: " ;
                r.mul(p);
                cout<<endl;
                break;
            case 5:
                cout << "What is the value of the real part of the komplex number that you want to divide with?\n";
                if (cin >> inp) {
                    p.setReal(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "What is the value of the imaginarius part of the komplex number that you want to divide with?\n";
                if (cin >> inp) {
                    p.setImag(inp);
                }
                else {
                    cerr << "Invalid value read.\n";
                }
                cout << "The result of the division of the two komplex numbers: ";
                r.div(p);
                break;
            case 6:{
            cout<<"give me a file"<<endl;
            cin>>file;
            ifstream be(file);
            be>>a>>b;
            r.setReal(a);
            r.setImag(b);
            }break;
            case 7:
            default:
                ended = true;
                break;
        }
    }

    return 0;
}

void printMenu() {
    cout << "0 : Menu\n1 : Set the number\n"
         << "2 : Get the number\n3 : Add\n"
         << "4 : Multiply\n"
         << "5 : Divide\n6 : File read\n7 : Exit\n";
}
