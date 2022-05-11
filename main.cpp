#include "utils.h"
#include <vector>
#include<tuple>

int main() {
    std::vector<int> a = {1,2,3,4,5};
    std::vector<int> b = {6,7,8,9,10};   
    // get all even numbers from a and b
    
    auto c = unionAndFilterContainer(a,b,[](int x){return x%2==0;});
    if (std::all_of(c.begin(), c.end(), [](auto x){return x%2==0;}))
        std::cout << "QUESTION 2 PASSED" << std::endl;
    else
        std::cout << "QUESTION 2 FAILED" << std::endl;

    // for(int value: c){
    //     std::cout<< value<<std::endl;
    // }
    std::cout << std::endl;
    std::cout << ackermann<1,2>::result << std::endl;
     std::pair<int,int> p1 (2,3);
     std::pair<int,int> p2 (3,4);
    // std::pair<int,int> p3 (4,5);
    // std::pair<int,int> p4 (5,6);
    std::tuple<std::pair<int,int>,std::pair<int,int>> tup1(p1,p2);
    
    
    int possible = matMulPossible(tup1);
    if(possible==1){
        std::cout << "Matrix Multiplication Possible"<< std::endl;;
    }
    else{
         std::cout << "Matrix Multiplication not Possible"<<std::endl;
    }
    std::tuple tuple1(1,1,1,1);
    std::tuple tuple2(1,2,3,4);
    //std::tuple <std::pair<int,int>,std::pair<int,int>> t1 (p1,p2);
    std::cout << "Equality function with equal parameters : ";
    bool possible2=std::apply(equalityU,tuple1);
    std::cout<< possible2 << std::endl;
    std::cout << "Equality function with unequal parameters : ";
    bool possible1=std::apply(equalityU,tuple2);
    std::cout<< possible1 << std::endl;




 }

