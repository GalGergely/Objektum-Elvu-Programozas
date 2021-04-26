#include "matrix.h"
#include <iostream>
#include <vector>

using namespace std;

void Matrix::setRow(int x){
    row=x;
}
void Matrix::setCol(int x){
    col=x;
}
int Matrix::getRow() const{
    return row;
}
int Matrix::getCol() const{
    return col;
}
void Matrix::set(){
for (int i=0; i<row; i++)
{
    vector<int>temp;
    for(int j=0; j<col; j++)
    {
        int temp2=0;
        if(i==j || j==0 || j==col-1){
            temp2=1;
            temp.push_back(temp2);
        }
        else{
            temp.push_back(temp2);
        }
        
    }
    matrix.push_back(temp);
}
}
void Matrix::read(){
for (int i=0; i<row; i++)
{
    vector<int>temp;
    for(int j=0; j<col; j++)
    {
        int temp2;
        cout<<"Enter item"<<i<<" "<<j<<endl;
        cin>>temp2;
        temp.push_back(temp2);
    }
    matrix.push_back(temp);
}
}
void Matrix::show(){
for (int i=0; i< matrix.size(); i++)
{
    for(int j=0; j< matrix[i].size(); j++)
    {
        cout<< matrix[i][j]<<" ";
    }
    cout<<endl;
}
}
void Matrix::sum(Matrix y){
for (int i=0; i< matrix.size(); i++)
{
    for(int j=0; j< matrix[i].size(); j++)
    {
        matrix[i][j]=matrix[i][j]+y.matrix[i][j];
    }
}
}
void Matrix::mul(Matrix y, Matrix z){
for (int i=0; i<y.row; i++)
{
    vector<int>temp;
    for(int j=0; j<y.col; j++)
    {
        int temp2=0;
        temp.push_back(temp2);
    }
    matrix.push_back(temp);
}
for(int i = 0; i < row; ++i)
        for(int j = 0; j < y.col; ++j)
            for(int k = 0; k < col; ++k)
            {
                matrix[i][j] += z.matrix[i][k] * y.matrix[k][j];
            }
}
void Matrix::clear(){
 matrix.clear();
}
int Matrix::checker(){
    return row;
}
void Matrix::manual(){
for (int i=0; i<row; i++)
{
    vector<int>temp;
    for(int j=0; j<col; j++)
    {
        int temp2;
        cout<<"Gimme the "<<i<<" "<<j<<"th number"<<endl;
        cin>>temp2;
        temp.push_back(temp2);
        
    }
    matrix.push_back(temp);
}
}