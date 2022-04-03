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

            //constructor
            Matrix(vector<double> v= {1},int r=1, int c=1);
            Matrix(const Matrix& other);
           
            int getRow() const {return this->_row;}
            int getCol() const {return this->_col;}
            vector<double> getV() const {return this->_v;}

            // void setRow(int r){this->_row=r;}
            // void setCol(int c){this->_col=c;}
            // void setV(vector<double>& v){this->_v=v;}
            
            void setMatrix(vector<double> v,int r, int c); 
            
           
            // addition
            
            Matrix operator+(const Matrix & m );
            Matrix operator+();
            void operator+=(const Matrix & m);
           


            // subtraction
            Matrix operator-(const Matrix & m);
            Matrix operator-();
            void operator-=(const Matrix & m );
        


            // increment decrement
            //prefix
            Matrix operator++(); 
            Matrix operator--(); 
            //postfix
            Matrix operator++(int i);
            Matrix operator--(int i);

        
            // multiplacation
            Matrix operator*(double d);
            friend Matrix& operator*(double d, Matrix m); // not in cpp
            Matrix operator*(const Matrix m);
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
            friend ostream& operator<<(ostream& output, const Matrix& m); // not in cpp
            friend ostream& operator>>(ostream& input,  Matrix& m); // not in cpp

    };
}
