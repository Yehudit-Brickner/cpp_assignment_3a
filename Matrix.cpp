    #include "Matrix.hpp"

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

    
    Matrix Matrix::operator+ (int i){

    }

    Matrix Matrix::operator+ (const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        vector<double> this_v=this->getV();
        vector<double> m_v=m.getV();
        int s=this_v.size();
        vector<double> new_v;
        new_v.reserve(s);
        for (int j=0;j<s;j++){
            new_v[j]=this_v[j]+m_v[j];
        }
        Matrix change{new_v,this->getCol(),this->getRow()};
    }

    void Matrix::operator+= (const Matrix & m){

    }


    void Matrix::operator+= (int i){
        //int max=this->getRow()*this->getCol();
        int max= this->getV().size();
        for (int j=0;j<max;j++){
            this->_v[j]=this->_v[j]+i;
        } 
    }

    Matrix Matrix::operator- (int i){

    }

    Matrix Matrix::operator- (const Matrix & m){

    }

    void Matrix::operator-= (const Matrix & m ){

    }


    void Matrix::operator-= (int i){
        int max= this->getV().size();
        for (int j=0;j<max;j++){
            this->_v[j]=this->_v[j]-i;
        } 
    }





    void Matrix:: operator++ (){
        int max= this->getV().size();
        for (int i=0;i<max;i++){
            this->_v[i]++;
        }  
    }

     void Matrix:: operator-- (){
        int max= this->getV().size();
        for (int i=0;i<max;i++){
            this->_v[i]--;
        }  
    }


    Matrix Matrix::operator++ (int i){

    }
    
    Matrix Matrix::operator-- (int i){

    }






    void Matrix::operator* (double d){
        int max= this->getV().size();
        for (int j=0;j<max;j++){
            this->_v[j]=this->_v[j]*d;
        } 
    }

    void Matrix::operator* (Matrix m){
        
    }

    void Matrix::operator*= (Matrix m){

    }
    void Matrix::operator*= (double d){

    };


    bool Matrix::operator== (const Matrix & m ){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
        int max1 = this->getV().size();
        double sum1 = 0;
        double sum2 = 0;
        for (int i=0; i<max1;i++){
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
    }

    bool Matrix::operator<= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
    }

    bool Matrix::operator> (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
    }

    bool Matrix::operator>= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
    }

    bool Matrix::operator!= (const Matrix & m){
        if(this->getCol()!=m.getCol()||this->getRow()!=m.getRow()){
            throw std::invalid_argument( "row or column dont match" );
        }
    }

    void Matrix::operator<< (const Matrix & m){

    }

    void Matrix::operator>> (const Matrix & m){

    }