#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

namespace zich{
    class Matrix{

        private:
            int _row;
            int _col;
            std::vector<double> _v;
            void setRow(int r){this->_row=r;}
            void setCol(int c){this->_col=c;}
            void setV(vector<double>& v){this->_v=v;}
        
        public:
            Matrix(vector<double> v= {1},int r=1, int c=1);
           
            int getRow() const {return this->_row;}
            int getCol() const {return this->_col;}
            vector<double> getV() const {return this->_v;}

            // void setRow(int r){this->_row=r;}
            // void setCol(int c){this->_col=c;}
            // void setV(vector<double>& v){this->_v=v;}
            
            void setMatrix(vector<double> v,int r, int c); 
            
           
            // addition
            Matrix operator+(int i); 
            Matrix operator+(const Matrix & m );
            void operator+=(const Matrix & m);
            void operator+=(int i); // made func


            // subtraction
            Matrix operator-(int i); 
            Matrix operator-(const Matrix & m);
            void operator-=(const Matrix & m );
            void operator-=(int i); // made func


            // increment decrement
            void operator++(); // made func
            void operator--(); // made func
            Matrix operator++(int i);
            Matrix operator--(int i);

        
            // multiplacation
            void operator*(double d);
            void operator*(const Matrix m);
            void operator*=(const Matrix m);
            void operator*=(double d);
            

            // comparing
            bool operator==(const Matrix & m );
            bool operator<(const Matrix & m);
            bool operator<=(const Matrix & m);
            bool operator>(const Matrix & m);
            bool operator>=(const Matrix & m);
            bool operator!=(const Matrix & m);


            //print
            void operator<< (const Matrix & m);
            void operator>> (const Matrix & m);
            void cout(const Matrix m);

    };
}
