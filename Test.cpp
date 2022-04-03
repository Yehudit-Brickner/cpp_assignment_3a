
#pragma once 
#include "doctest.h"
#include "Matrix.hpp"

#include <string>
#include <vector>
// #include <ctime>
// #include <random>
using namespace zich;




TEST_CASE("building a matrix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b={};
    CHECK_THROWS(Matrix mat1(a,-3,3));
    CHECK_THROWS(Matrix mat1(a,3,-3));
    CHECK_THROWS(Matrix mat1(a,-3,-3));
    CHECK_THROWS(Matrix mat1(a,1,8));
    CHECK_THROWS(Matrix mat1(a,2,5));
    CHECK_THROWS(Matrix mat1(b,3,3));
}





TEST_CASE("operator+()"){
   std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
   Matrix mat1{a,3,3}; 
   Matrix newm = +mat1;
   CHECK(mat1.getCol()==newm.getCol());
   CHECK(mat1.getRow()==newm.getRow());
   CHECK(mat1.getV()==newm.getV());

}

TEST_CASE("operator+(mat other)"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};  
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix mat1{a,3,3};
    Matrix mat2{b,3,3};
    Matrix mat3{b,1,9};
    Matrix mat_new1=mat1+mat2;
    Matrix mat_good{c,3,3};
    CHECK(mat_new1.getCol()==mat_good.getCol());
    CHECK(mat_new1.getRow()==mat_good.getRow());
    CHECK(mat_new1.getV()==mat_good.getV());
    CHECK_THROWS(mat1+mat3);
    CHECK_THROWS(mat3+mat1);



}

// TEST_CASE("operator+=()"){
//     std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};  
//     std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
//     std::vector<double> c = {6, 0, 0, 0, 6, 0, 0, 0, 6};
//     Matrix mat1{a,3,3};
//     Matrix mat2{b,3,3};
//     Matrix mat3{b,1,9};
//     Matrix mat_good{c,3,3};
//     mat1+mat2;
//     CHECK(mat1.getCol()==mat_good.getCol());
//     CHECK(mat1.getRow()==mat_good.getRow());
//     CHECK(mat1.getV()==mat_good.getV());
//     CHECK_THROWS(mat1+mat3);
//     CHECK_THROWS(mat3+mat1);
// }





TEST_CASE("operator-()"){
   std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1}; 
   std::vector<double> b = {-1, 0, 0, 0, -1, 0, 0, 0, -1}; 
   Matrix mat1{a,3,3};
   Matrix newm= -mat1;
   CHECK(mat1.getCol()==newm.getCol());
   CHECK(mat1.getRow()==newm.getRow());
   CHECK(b==newm.getV());
}

TEST_CASE("operator-(mat other)"){
std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};  
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix mat1{c,3,3};
    Matrix mat2{a,3,3};
    Matrix mat3{b,1,9};
    Matrix mat_new1=mat1-mat2;
    Matrix mat_good{b,3,3};
    CHECK(mat_new1.getCol()==mat_good.getCol());
    CHECK(mat_new1.getRow()==mat_good.getRow());
    CHECK(mat_new1.getV()==mat_good.getV());
    CHECK_THROWS(mat1-mat3);
    CHECK_THROWS(mat3-mat1);

}


// TEST_CASE("increment to new matrix"){
//     std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     Matrix mat1{a,3,3};
//     std::vector<double> b ={2, 0, 0, 0, 2, 0, 0, 0, 2};
//     Matrix new_mat1=mat1++;
//     CHECK(new_mat1.getV()==b);
//     Matrix new_mat2=mat1++;
//     CHECK(new_mat1.getV()==b);
// }

// TEST_CASE("increment"){   
//     std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     Matrix mat1{a,3,3};  
//     for (int i=1; i<5;i++){
//         mat1++;
//         b[0]=b[0]+1;
//         b[4]=b[4]+1;
//         b[8]=b[8]+1;
//         CHECK(mat1.getV()==b);
//     } 
// }

// TEST_CASE("decrement to new matrix"){
//     std::vector<double> identity = {2, 0, 0, 0, 2, 0, 0, 0, 2};
//     Matrix mat1{identity,3,3}; 
//     std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     Matrix new_mat1=mat1--;
//     CHECK(new_mat1.getV()==b);
//     Matrix new_mat2=mat1++;
//     CHECK(new_mat1.getV()==b);

// }

// TEST_CASE("decrement to same matrix"){
//     std::vector<double> a = {10, 0, 0, 0, 10, 0, 0, 0, 10};
//     std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     Matrix mat1{a,3,3};  
//     for (int i=1; i<5;i++){
//         mat1++;
//         b[0]=b[0]-1;
//         b[4]=b[4]-1;
//         b[8]=b[8]-1;
//         CHECK(mat1.getV()==b);
//     } 
// }

TEST_CASE("operator*=()"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {17.5, 0, 0, 0, 17.5, 0, 0, 0, 17.5};
    Matrix mat1{a,3,3};
    mat1*=5;
    CHECK(mat1.getV()==b);
    mat1*=3.5;
    CHECK(mat1.getV()==c);
}

TEST_CASE("operator*()"){
    std::vector<double> a = {1, 2,3};
    std::vector<double> b = {1,1,1, 1,1,1, 1,1,1};
    std::vector<double> c = {6,6,6, 6,6,6, 6,6,6};
    Matrix mat1{a,3,1};
    Matrix mat2{b,3,3};
    Matrix mat_good{c,3,3};
    Matrix newm=mat1*mat2;
    CHECK(newm.getCol()==mat_good.getCol());
    CHECK(newm.getRow()==mat_good.getRow());
    CHECK(newm.getV()==mat_good.getV());
    
}

TEST_CASE("operator*=(mat other)"){
    std::vector<double> a = {1, 2,3};
    std::vector<double> b = {1,1,1, 1,1,1, 1,1,1};
    std::vector<double> c = {6,6,6, 6,6,6, 6,6,6};
    Matrix mat1{a,3,1};
    Matrix mat2{b,3,3};
    Matrix mat_good{c,3,3};
    mat1*=mat2;
    CHECK(mat1.getCol()==mat_good.getCol());
    CHECK(mat1.getRow()==mat_good.getRow());
    CHECK(mat1.getV()==mat_good.getV());



}

TEST_CASE("operator*(mat other)"){

}

TEST_CASE("operator==(mat other)"){
    std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {4,5,6,7};
    Matrix mat3{c,2,2};
    CHECK((mat1==mat2)==true);
    CHECK((mat2==mat1)==true);
    CHECK_THROWS(mat1==mat3);
    CHECK_THROWS(mat2==mat3);
    CHECK_THROWS(mat3==mat2);
    CHECK_THROWS(mat3==mat2);

}

TEST_CASE("operator<(mat other)"){
    std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {2, 2, 1, 2, 2, 1, 2, 2, 1};
    Matrix mat3{c,3,3};
    std::vector<double> d = {4,5,6,7};
    Matrix mat4{d,2,2};
    CHECK((mat1<mat2)==false);
    CHECK((mat2<mat1)==false);
    CHECK((mat1<mat3)==false);
    CHECK((mat2<mat3)==false);
    CHECK((mat3<mat1)==true);
    CHECK((mat3<mat2)==true);
    CHECK_THROWS(mat4<mat1);
    CHECK_THROWS(mat4<mat2);
    CHECK_THROWS(mat4<mat3);
}

TEST_CASE("operator<=(mat other)"){
    std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {2, 2, 1, 2, 2, 1, 2, 2, 1};
    Matrix mat3{c,3,3};
    std::vector<double> d = {4,5,6,7};
    Matrix mat4{d,2,2};
    CHECK((mat1<=mat2)==true);
    CHECK((mat2<=mat1)==true);
    CHECK((mat1<=mat3)==false);
    CHECK((mat2<=mat3)==false);
    CHECK((mat3<=mat1)==true);
    CHECK((mat3<=mat2)==true);
    CHECK_THROWS(mat4<=mat1);
    CHECK_THROWS(mat4<=mat2);
    CHECK_THROWS(mat4<=mat3);
}

TEST_CASE("operator>=(mat other)"){
    std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {2, 2, 1, 2, 2, 1, 2, 2, 1};
    Matrix mat3{c,3,3};
    std::vector<double> d = {4,5,6,7};
    Matrix mat4{d,2,2};
    CHECK((mat1>=mat2)==true);
    CHECK((mat2>=mat1)==true);
    CHECK((mat1>=mat3)==true);
    CHECK((mat2>=mat3)==true);
    CHECK((mat3>=mat1)==false);
    CHECK((mat3>=mat2)==false);
    CHECK_THROWS(mat4>=mat1);
    CHECK_THROWS(mat4>=mat2);
    CHECK_THROWS(mat4>=mat3);
}

TEST_CASE("operator>(mat other)"){
std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {2, 2, 1, 2, 2, 1, 2, 2, 1};
    Matrix mat3{c,3,3};
    std::vector<double> d = {4,5,6,7};
    Matrix mat4{d,2,2};
    CHECK((mat1>mat2)==false);
    CHECK((mat2>mat1)==false);
    CHECK((mat1>mat3)==true);
    CHECK((mat2>mat3)==true);
    CHECK((mat3>mat1)==false);
    CHECK((mat3>mat2)==false);
    CHECK_THROWS(mat4>mat1);
    CHECK_THROWS(mat4>mat2);
    CHECK_THROWS(mat4>mat3);
}

TEST_CASE("operator!=(mat other)"){
std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {2, 2, 1, 2, 2, 1, 2, 2, 1};
    Matrix mat3{c,3,3};
    std::vector<double> d = {4,5,6,7};
    Matrix mat4{d,2,2};
    CHECK((mat1!=mat2)==false);
    CHECK((mat2!=mat1)==false);
    CHECK((mat1!=mat3)==true);
    CHECK((mat2!=mat3)==true);
    CHECK((mat3!=mat1)==true);
    CHECK((mat3!=mat2)==true);
    CHECK_THROWS(mat4!=mat1);
    CHECK_THROWS(mat4!=mat2);
    CHECK_THROWS(mat4!=mat3);
}




TEST_CASE("operator<<"){
}

TEST_CASE("operator>>"){
}