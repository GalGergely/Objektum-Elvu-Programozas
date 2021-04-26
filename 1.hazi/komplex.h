#pragma once

#include <bits/stdc++.h>

class komplex {   
    public:   
        komplex(double x, double y);  
        komplex(const komplex &r);   

        void setReal (double x);  
        void setImag (double x); 

        double getReal () const;  
        double getImag () const;

        void add(const komplex &q) const;
        void sub(const komplex &q) const;
        void mul(const komplex &q) const;
        void div(const komplex &q) const;

    private:
        double real, imag; 
};   
