    #include "Matrix.hpp"

    void Matrix::setMatrix(vector<double> v,int r, int c){
        this->setRow(r);
        this->setCol(c);
        this->setV(v);
    }

    Matrix::Matrix(){
        this->setMatrix();
    }





    void Matrix::operator+(int i){
        int max=this->getRow()*this->getCol();
        for (int j=0;j<max;j++){
            this->_v[j]=this->_v[j]+i;
        } 
    }


    void Matrix::operator+(const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            std::throw
        }
    }

    void Matrix::operator-(int i){
        int max=this->getRow()*this->getCol();
        for (int j=0;j<max;j++){
            this->_v[j]=this->_v[j]-i;
        } 
    }





    void Matrix:: operator++(){
        int max=this->getRow()*this->getCol();
        for (int i=0;i<max;i++){
            this->_v[i]++;
        }  
    }

     void Matrix:: operator--(){
        int max=this->getRow()*this->getCol();
        for (int i=0;i<max;i++){
            this->_v[i]--;
        }  
    }


    void Matrix::operator*(double d){
        int max=this->getRow()*this->getCol();
        for (int j=0;j<max;j++){
            this->_v[j]=this->_v[j]*d;
        } 
    }
