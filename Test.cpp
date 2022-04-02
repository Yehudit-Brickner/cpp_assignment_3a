
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
    CHECK_THROWS(Matrix mat1(a,1,8));
    CHECK_THROWS(Matrix mat1(a,2,5));
    CHECK_THROWS(Matrix mat1(b,3,3));



}



TEST_CASE("add make new matrix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{a,3,3};
    Matrix new_mat1=mat1+5;
    std::vector<double> b = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    CHECK(new_mat1.getV()==b);
}

TEST_CASE("add to same matrix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{a,3,3};
    std::vector<double> b = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    mat1+5;
    CHECK(mat1.getV()==b);
}

TEST_CASE("add+="){

}

TEST_CASE("add+="){

}

TEST_CASE("sub make new amtrix"){
    std::vector<double> a = {4, 0, 0, 0, 4, 0, 0, 0, 4};
    Matrix mat1{a,3,3};
    std::vector<double> b ={2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix new_mat1=mat1-2;
    CHECK(new_mat1.getV()==b);
}

TEST_CASE("sub to new matrix"){
    std::vector<double> a = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat1{a,3,3};
    std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    mat1-1;
    CHECK(mat1.getV()==b);
}

TEST_CASE("sub-="){

}

TEST_CASE("sub-="){

}

TEST_CASE("increment to new matrix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{a,3,3};
    std::vector<double> b ={2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix new_mat1=mat1++;
    CHECK(new_mat1.getV()==b);
    Matrix new_mat2=mat1++;
    CHECK(new_mat1.getV()==b);
}

TEST_CASE("increment to same matrix"){   
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{a,3,3};  
    for (int i=1; i<5;i++){
        mat1++;
        b[0]=b[0]+1;
        b[4]=b[4]+1;
        b[8]=b[8]+1;
        CHECK(mat1.getV()==b);
    } 
}

TEST_CASE("decrement to new matrix"){
    std::vector<double> identity = {2, 0, 0, 0, 2, 0, 0, 0, 2};
    Matrix mat1{identity,3,3}; 
    std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix new_mat1=mat1--;
    CHECK(new_mat1.getV()==b);
    Matrix new_mat2=mat1++;
    CHECK(new_mat1.getV()==b);

}

TEST_CASE("decrement to same matrix"){
    std::vector<double> a = {10, 0, 0, 0, 10, 0, 0, 0, 10};
    std::vector<double> b = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    Matrix mat1{a,3,3};  
    for (int i=1; i<5;i++){
        mat1++;
        b[0]=b[0]-1;
        b[4]=b[4]-1;
        b[8]=b[8]-1;
        CHECK(mat1.getV()==b);
    } 
}

TEST_CASE("mult to same matrix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {17.5, 0, 0, 0, 17.5, 0, 0, 0, 17.5};
    Matrix mat1{a,3,3};
    mat1*5;
    CHECK(mat1.getV()==b);
    mat1*3.5;
    CHECK(mat1.getV()==c);
}

TEST_CASE("mult*"){

}

TEST_CASE("mult*="){

}

TEST_CASE("mult*="){

}

TEST_CASE("equal=="){
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

TEST_CASE("small<"){
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

TEST_CASE("smalleq<="){
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

TEST_CASE("bigeq>="){
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

TEST_CASE("big>"){
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

TEST_CASE("noteq!="){
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
