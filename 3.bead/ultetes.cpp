#include "ultetes.h"

using namespace std;

void Ultetes::read(const string& fname)
{
ifstream f(fname);
        if(f.fail()) throw FILE_OPEN_ERROR;

        int lines, nutrients, napok;
        string name, species, line;
        getline(f,line);
        istringstream is(line);
        is>>lines;
        for(int i=0; i<lines; i++)
        {
            getline(f,line);
            istringstream is(line);
            is >> name >> species >> nutrients;
            Novenyek* novenyek;
            if(species=="d")
            {
                 novenyek = new Deltafa(nutrients, name);
                 _novenyek.push_back(novenyek);
            }
            else if(species=="b")
            {
                 novenyek = new Parabokor(nutrients, name);
                 _novenyek.push_back(novenyek);
            }
            else if(species=="p")
            {
                 novenyek = new Puffancs(nutrients, name);
                 _novenyek.push_back(novenyek);
            }
            else
            {
                throw UNKNOWN_SPECIES;
            }
        }
        getline(f,line);
        istringstream is1(line);
        is1>>napok;
        _nap=napok;
}

void Ultetes::szimulacio()
 {
        print();
        for(int i=0; i<_nap; i++)
        {
           igenyek();
           novenyek();
           print();
           setSugarzas();
           if(nincsCntr==2)
           {
                break;
           }
        }
 }

void Ultetes::setSugarzas()
{
          if(sugarzasmero=="alfa")
          {
               alfaIgeny=0;
               nincsCntr=0;
          }
          if(sugarzasmero=="delta")
          {
               deltaIgeny=0;
               nincsCntr=0;
          }
          if(sugarzasmero=="nincs")
          {
               nincsCntr++;
          }
}

void Ultetes::igenyek()
{
        for(int i=0; i<_novenyek.size(); i++)
        {
            if(_novenyek[i]->getFajta()==Novenyek::Puffancs)
            {
                alfaIgeny=alfaIgeny+10;
            }
            if(_novenyek[i]->getFajta()==Novenyek::Deltafa && _novenyek[i]->getNutrinets()<5)
            {
                deltaIgeny=deltaIgeny+4;
            }
            if(_novenyek[i]->getFajta()==Novenyek::Deltafa && _novenyek[i]->getNutrinets()>5 && _novenyek[i]->getNutrinets()<10)
            {
                deltaIgeny=deltaIgeny+1;
            }
        }
}

void Ultetes::novenyek()
{

        for(int i=0; i<_novenyek.size(); i++)
        {
            if(_novenyek[i]->getAlive()==false)
            {
                _novenyek.erase(_novenyek.begin()+i);
                
            }
            if(alfaIgeny>deltaIgeny+3)
            {
                _novenyek[i]->alfa();
               // std::cout<<"alfa"<<std::endl;
                sugarzasmero="alfa";
            }
            else if(alfaIgeny+3<deltaIgeny)
            {
                _novenyek[i]->delta();
               //std::cout<<"delta"<<std::endl;
                sugarzasmero="delta";
                
            }
            else
            {
                _novenyek[i]->nincs();
                //std::cout<<"nincs"<<std::endl;
                sugarzasmero="nincs";
            }
        }
}

void Ultetes::print()
   {
       _final.clear();
        cout<<sugarzasmero<<endl;
        int i=0;
        for(Novenyek* a : _novenyek)
        {
            if(_novenyek[i]->getAlive()==1)
            {
             cout<<a->getFajta()<<" "<<a->getName()<<" "<<a->getNutrinets()<<" "<<a->getAlive()<<endl;
            _final.push_back(a);
            }
            i++;
        }
        cout<<endl;
    }
