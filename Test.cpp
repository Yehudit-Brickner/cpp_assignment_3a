
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
    vector<double> newm_v=newm.getV();
    for (unsigned i=0;i<mat1.getV().size();i++){
        CHECK(a[i]==newm_v[i]);
    }
    CHECK(newm.getV()==mat1.getV());

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
    vector<double> new_v=mat_new1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==c[i]);
    }
    CHECK(mat_new1.getV()==mat_good.getV());
    CHECK_THROWS(mat1+mat3);
    CHECK_THROWS(mat3+mat1);
}

TEST_CASE("operator+=(mat other)"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};  
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix mat1{a,3,3};
    Matrix mat2{b,3,3};
    Matrix mat3{b,1,9};
    mat1+=mat2;
    Matrix mat_good{c,3,3};
    CHECK(mat1.getCol()==mat_good.getCol());
    CHECK(mat1.getRow()==mat_good.getRow());
    vector<double> new_v=mat1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==c[i]);
    }
    CHECK(mat1.getV()==mat_good.getV());
    CHECK_THROWS(mat1+=mat3);
    CHECK_THROWS(mat3+=mat1);
}

TEST_CASE("operator-()"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1}; 
    std::vector<double> b = {-1, 0, 0, 0, -1, 0, 0, 0, -1}; 
    Matrix mat1{a,3,3};
    Matrix newm= -mat1;
    CHECK(newm.getCol()==mat1.getCol());
    CHECK(newm.getRow()==mat1.getRow());
    vector<double> new_v=newm.getV();
    vector<double> mat1_v=mat1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
        CHECK(mat1_v[i]==a[i]);
    }
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
    vector<double> new_v=mat_new1.getV();
    vector<double> mat1_v=mat1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
        CHECK(mat1_v[i]==c[i]);
    }
    CHECK(mat_new1.getV()==mat_good.getV());
    CHECK(mat1.getV()==c);
    CHECK_THROWS(mat1-mat3);
    CHECK_THROWS(mat3-mat1);
}

TEST_CASE("operator-=(mat other)"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};  
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {6, 0, 0, 0, 6, 0, 0, 0, 6};
    Matrix mat1{c,3,3};
    Matrix mat2{a,3,3};
    Matrix mat3{b,1,9};
    mat1-=mat2;
    Matrix mat_good{b,3,3};
    CHECK(mat1.getCol()==mat_good.getCol());
    CHECK(mat1.getRow()==mat_good.getRow());
    vector<double> new_v=mat1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
    }
    CHECK(mat1.getV()==mat_good.getV());
    CHECK_THROWS(mat1-=mat3);
    CHECK_THROWS(mat3-=mat1);
}

TEST_CASE("operater++() prefix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b ={2, 1, 1, 1, 2, 1, 1, 1, 2};
    std::vector<double> c ={3, 2 , 2, 2, 3, 2, 2, 2, 3};
    Matrix mat1{a,3,3};
    Matrix mat2{b,3,3};
    Matrix mat3{c,3,3};
    mat1++;
    CHECK(mat1.getCol()==mat2.getCol());
    CHECK(mat1.getRow()==mat2.getRow());
    vector<double> new_v=mat1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
    }
    CHECK(mat1.getV()==mat2.getV());
    mat1++;
    CHECK(mat1.getCol()==mat3.getCol());
    CHECK(mat1.getRow()==mat3.getRow());
    CHECK(mat1.getV()==mat3.getV());
    new_v=mat1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==c[i]);
    }
}

TEST_CASE("operator--() prefix"){   
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b ={2, 1,1, 1, 2, 1, 1, 1, 2};
    std::vector<double> c ={3, 2, 2, 2, 3, 2, 2, 2, 3};
    Matrix mat1{a,3,3};
    Matrix mat2{b,3,3};
    Matrix mat3{c,3,3};
    mat3--;
    CHECK(mat3.getCol()==mat2.getCol());
    CHECK(mat3.getRow()==mat2.getRow());
    CHECK(mat3.getV()==mat2.getV());
    mat3--;
    CHECK(mat3.getCol()==mat1.getCol());
    CHECK(mat3.getRow()==mat1.getRow());
    CHECK(mat3.getV()==mat1.getV());
}

TEST_CASE("operater++(int i) postfix"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b ={2, 1, 1, 1, 2, 1, 1, 1, 2};
    std::vector<double> c ={3, 2, 2, 2, 3, 2, 2, 2, 3};
    Matrix mat1{a,3,3};
    Matrix mat2{b,3,3};
    Matrix mat3{c,3,3};
    Matrix old1{a,3,3};
    Matrix old2{b,3,3};
    Matrix new1 = ++mat1;
    CHECK(new1.getCol()==old1.getCol());
    CHECK(new1.getRow()==old1.getRow());
    vector<double> new_v=new1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==a[i]);
    }
    //CHECK(new1.getV()==old1.getV());
    
    CHECK(mat1.getCol()==mat2.getCol());
    CHECK(mat1.getRow()==mat2.getRow());
    CHECK(mat1.getV()==mat2.getV());
    Matrix new2 = ++mat1;
    CHECK(new2.getCol()==old2.getCol());
    CHECK(new2.getRow()==old2.getRow());
    new_v=new2.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
    }
    //CHECK(new2.getV()==old2.getV());
    CHECK(mat1.getCol()==mat3.getCol());
    CHECK(mat1.getRow()==mat3.getRow());
    CHECK(mat1.getV()==mat3.getV());
}

TEST_CASE("operator--(int i) postfix"){   
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b ={2, 1, 1, 1, 2, 1, 1, 1, 2};
    std::vector<double> c ={3, 2, 2, 2, 3, 2, 2, 2, 3};
    Matrix mat1{a,3,3};
    Matrix mat2{b,3,3};
    Matrix mat3{c,3,3};
    Matrix old2{b,3,3};
    Matrix old1{c,3,3};
    Matrix new1 = --mat3;
    CHECK(new1.getCol()==old1.getCol());
    CHECK(new1.getRow()==old1.getRow());
    //CHECK(new1.getV()==old1.getV());
    vector<double> new_v=new1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==c[i]);
    }
    CHECK(mat3.getCol()==mat2.getCol());
    CHECK(mat3.getRow()==mat2.getRow());
    CHECK(mat3.getV()==mat2.getV());
    Matrix new2 = --mat3;
    CHECK(new2.getCol()==old2.getCol());
    CHECK(new2.getRow()==old2.getRow());
    //CHECK(new2.getV()==old2.getV());
    new_v=new2.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
    }
    CHECK(mat3.getCol()==mat1.getCol());
    CHECK(mat3.getRow()==mat1.getRow());
    CHECK(mat3.getV()==mat1.getV());
}

TEST_CASE("operator*=(double d)"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {17.5, 0, 0, 0, 17.5, 0, 0, 0, 17.5};
    Matrix mat1{a,3,3};
    mat1*=5;
    CHECK(mat1.getV()==b);
    mat1*=3.5;
    CHECK(mat1.getV()==c);
}

TEST_CASE("operator*(double d)"){
    std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
    std::vector<double> c = {3.5, 0, 0, 0, 3.5, 0, 0, 0, 3.5};
    Matrix mat1{a,3,3};
    Matrix check1={b,3,3};
    Matrix check2={c,3,3};
    Matrix new1= mat1*5;
    CHECK(new1.getCol()==check1.getCol());
    CHECK(new1.getRow()==check1.getRow());
    //CHECK(new1.getV()==check1.getV());
    vector<double> new_v=new1.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==b[i]);
    }
    Matrix new2= mat1*3.5;
    CHECK(new2.getCol()==check2.getCol());
    CHECK(new2.getRow()==check2.getRow());
    //CHECK(new2.getV()==check2.getV());
    new_v=new2.getV();
    for (unsigned i=0;i<new_v.size();i++){
        CHECK(new_v[i]==c[i]);
    }
}


// tets case for mat * double
// TEST_CASE("operator*(double d, mat other)"){
//     std::vector<double> a = {1, 0, 0, 0, 1, 0, 0, 0, 1};
//     std::vector<double> b = {5, 0, 0, 0, 5, 0, 0, 0, 5};
//     std::vector<double> c = {3.5, 0, 0, 0, 3.5, 0, 0, 0, 3.5};
//     Matrix mat1{a,3,3};
//     Matrix check1={b,3,3};
//     Matrix check2={c,3,3};
//     Matrix new1= mat1*(5,&mat1);
//     CHECK(new1.getCol()==check1.getCol());
//     CHECK(new1.getRow()==check1.getRow());
//     //CHECK(new1.getV()==check1.getV());
//     vector<double> new_v=new1.getV();
//     for (unsigned i=0;i<new_v.size();i++){
//         CHECK(new_v[i]==b[i]);
//     }
//     Matrix new2= mat1*3.5;
//     CHECK(new2.getCol()==check2.getCol());
//     CHECK(new2.getRow()==check2.getRow());
//     //CHECK(new2.getV()==check2.getV());
//     new_v=new2.getV();
//     for (unsigned i=0;i<new_v.size();i++){
//         CHECK(new_v[i]==c[i]);
//     }
// }

TEST_CASE("operator*=(mat other)"){
    std::vector<double> a = {1, 2,3};
    std::vector<double> b = {1,1,1, 1,1,1, 1,1,1};
    std::vector<double> c = {6,6,6, 6,6,6, 6,6,6};
    std::vector<double> d = {1,2,3,4};
    Matrix mat1{a,3,1};
    Matrix mat2{b,3,3};
    Matrix mat3{d,4,1}; 
    Matrix mat4{d,2,2};
    Matrix mat_good{c,3,3};
    mat1*=mat2;
    CHECK(mat1.getCol()==mat_good.getCol());
    CHECK(mat1.getRow()==mat_good.getRow());
    CHECK(mat1.getV()==mat_good.getV());
    CHECK_THROWS(mat3*=mat1);
    CHECK_THROWS(mat4*=mat1);
}

// TEST_CASE("operator*(mat other)"){
//     std::vector<double> a = {1, 2,3};
//     std::vector<double> b = {1,1,1, 1,1,1, 1,1,1};
//     std::vector<double> c = {6,6,6, 6,6,6, 6,6,6};
//     std::vector<double> d = {1,2,3,4};
//     Matrix mat1{a,3,1};
//     Matrix mat2{b,3,3};
//     Matrix mat3{d,4,1}; 
//     Matrix mat4{d,2,2};
//     Matrix mat_good{c,3,3};
//     Matrix newm=mat1*mat2;
//     CHECK(newm.getCol()==mat_good.getCol());
//     CHECK(newm.getRow()==mat_good.getRow());
//     CHECK(newm.getV()==mat_good.getV());
//     CHECK_THROWS(mat3*=mat1);
//     CHECK_THROWS(mat4*=mat1); 
// }





TEST_CASE("operator==(mat other)"){
    std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    Matrix mat1{a,3,3};
    Matrix mat4{a,3,3};
    std::vector<double> b = {3, 2, 1, 3, 2, 1, 3, 2, 1};
    Matrix mat2{b,3,3};
    std::vector<double> c = {4,5,6,7};
    Matrix mat3{c,2,2};
    CHECK((mat1==mat2)==false);
    CHECK((mat2==mat1)==false);
    CHECK((mat1==mat4)==true);
    // CHECK_THROWS((mat1==mat3));
    // CHECK_THROWS(mat2==mat3);
    // CHECK_THROWS(mat3==mat2);
    // CHECK_THROWS(mat3==mat2);
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
    // CHECK_THROWS(mat4<mat1);
    // CHECK_THROWS(mat4<mat2);
    // CHECK_THROWS(mat4<mat3);
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
    // CHECK_THROWS(mat4<=mat1);
    // CHECK_THROWS(mat4<=mat2);
    // CHECK_THROWS(mat4<=mat3);
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
    // CHECK_THROWS(mat4>=mat1);
    // CHECK_THROWS(mat4>=mat2);
    // CHECK_THROWS(mat4>=mat3);
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
    // CHECK_THROWS(mat4>mat1);
    // CHECK_THROWS(mat4>mat2);
    // CHECK_THROWS(mat4>mat3);
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
    // CHECK_THROWS(mat4!=mat1);
    // CHECK_THROWS(mat4!=mat2);
    // CHECK_THROWS(mat4!=mat3);
}

// TEST_CASE("operator<<"){
//     std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
//     Matrix mat1{a,3,3};  
//     CHECK((<<mat1))=="[1 2 3]\n[1 2 3]\n[1 2 3]");
//     std::vector<double> b = {1, 2, 3, 4,5,6,7,8,9};
//     Matrix mat2{b,1,9};  
//     CHECK((<< mat2)=="[1 2 3 4 5 6 7 8 9]");
//     Matrix mat3{b,1,9};  
//     CHECK((<<mat3)=="[1]\n[2]\n[3]\n[4]\n[5]\n[6]\n[7]\n[8]\n[9]");
// }

// TEST_CASE("operator>>"){
//     std::vector<double> a = {1, 2, 3, 1, 2, 3, 1, 2, 3};
//     Matrix mat1{a,3,3};  

//     // Matrix mat2<< (3 3 1 2 3 1 2 3 1 2 3);
//     // CHECK(mat1.getCol()==mat2.getCol());
//     // CHECK(mat1.getRow()==mat2.getRow());
//     // CHECK(mat1.getV()==mat2.getV());
// }