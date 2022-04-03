    #include "Matrix.hpp"
    #include <iostream>
    #include <stdexcept>
    using namespace zich;

    void Matrix::setMatrix (vector<double> v,int r, int c){
        if( r<1 || c<1){
            throw std::invalid_argument( "row or col invalid size" ); 
        }
        if(v.size()<1){
           throw std::invalid_argument( " vector  is invalid" ); 
        }
        if(r*c!=v.size()){
           throw std::invalid_argument( "size of vector doesnt match row*col" ); 
        }

        this->setRow(r);
        this->setCol(c);
        this->setV(v);
    }

    Matrix::Matrix (vector<double> v, int r, int c){
        this->setMatrix(v,r,c);
    }
    Matrix::Matrix(const Matrix & other){
        int r=other.getRow();
        int c =other.getCol();
        vector<double> old=other.getV();
        unsigned long s=old.size();
        vector<double> new_v;
        new_v.reserve(s);
        for (unsigned long i;i<s;i++){
            new_v[i]=old[i];
        }
        this->setCol(c);
        this->setRow(r);
        this->setV(new_v);
    }

    
    Matrix Matrix::operator+ (){
       return *this;
    }

    Matrix Matrix::operator+ (const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        unsigned long s=this_v.size();
        vector<double> new_v;
        new_v.reserve(s);
        for (unsigned int j=0;j<s;j++){
            new_v[j]=this_v[j]+m_v[j];
        }
        Matrix change{new_v,this->getCol(),this->getRow()};
        return change;
    }

    void Matrix::operator+= (const Matrix & m){
         
    }




    Matrix Matrix::operator- (){
         return *this;
    }

    Matrix Matrix::operator- (const Matrix & m){
         return *this;
    }

    void Matrix::operator-= (const Matrix & m ){

    }






    Matrix Matrix:: operator++ (){
        int max= this->getV().size();
        for (unsigned long i=0;i<max;i++){
            this->_v[i]++;
        }  
         return *this;
    }

     Matrix Matrix:: operator-- (){
        int max= this->getV().size();
        for (unsigned long i=0;i<max;i++){
            this->_v[i]--;
        } 
         return *this; 
    }


    Matrix Matrix::operator++ (int i){
        return *this;
    }
    
    Matrix Matrix::operator-- (int i){
         return *this;
    }






    Matrix Matrix::operator* (double d){
        int max= this->getV().size();
        for (unsigned long j=0;j<max;j++){
            this->_v[j]=this->_v[j]*d;
        } 
         return *this;
    }


    Matrix& operator*(double d, Matrix m){
       Matrix mnew=m*d;
       return mnew;
    }


    Matrix Matrix::operator* (Matrix m){
         return *this;
    }



    void Matrix::operator*= (Matrix m){

    }
    void Matrix::operator*= (double d){

    }


    bool Matrix::operator== (const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        for (unsigned long i=0; i<max1;i++){
            sum1+=this->_v[i];
            sum2+=m._v[i];
        }
        if(sum1==sum2){
            return true;
        }
        return false;
    }

    bool Matrix::operator< (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        return false;
    }

    bool Matrix::operator<= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        return false;
    }

    bool Matrix::operator> (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        return false;
    }

    bool Matrix::operator>= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        return false;
    }

    bool Matrix::operator!= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        return false;
    }

   ostream& operator<< (ostream& output,const Matrix & m){
        return output;
    }

   istream& operator>> (istream& input,const Matrix & m){
       return input;
    }