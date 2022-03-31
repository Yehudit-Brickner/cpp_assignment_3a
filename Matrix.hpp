#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;


class Matrix{

    private:
        int _row;
        int _col;
        std::vector<double> _v;
    
    public:
        Matrix();
        int getRow() const {return this->_row;}
        int getCol() const {return this->_col;}
        vector<double> getV() const {return this->_v;}

        void setRow(int r){this->_row=r;}
        void setCol(int c){this->_col=c;}
        void setV(vector<double>& v){this->_v=v;}
        
        void setMatrix(vector<double> v= {1},int r=1, int c=1); 
        
        Matrix();

        
        
        void operator+(int i); // made func
        //void operator=+();
        void operator+(const Matrix & m );

         void operator-(int i); // made func
        //void operator=-();
        void operator-(const Matrix & m);

        void operator++(); // made func
        void operator--(); // made func

        // void ++operator();
        // void --operator();

       

        void operator*(double d);
        void operator==(const Matrix & m );
        void operator<(const Matrix & m);
        void operator<=(const Matrix & m);
        void operator>(const Matrix & m);
        void operator>=(const Matrix & m);
        void operator!=(const Matrix & m);
      




};
