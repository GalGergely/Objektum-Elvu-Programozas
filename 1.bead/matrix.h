#pragma once
#include <vector>


class Matrix
{
public:
   void clear();
   void sum(Matrix x);
   void mul(Matrix x,Matrix z);
   void read();
   void show();
   void set();
   void setRow(int x);
   void setCol(int x);
   int getRow() const;
   int getCol() const;
   int checker();
   void manual();

private:
    int row;
    int col;
    std::vector< std::vector<int> > matrix;   
};
