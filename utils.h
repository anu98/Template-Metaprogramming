
#include <algorithm>
#include <iostream>
#include <vector>
#include<tuple>
#include<string>

// implement your code here
template<int m, int n> class ackermann
{
    public:
    static int const result= ackermann<m-1,ackermann<m,n-1>::result>::result;
};
template < int m > class ackermann <m, 0>{
public:
static int const result = ackermann<m-1, 1>::result;
};
 
template <int n> class ackermann <0,n> {
public:
static int const result = n+1;
};

template<typename T>
std::vector<int> unionAndFilterContainer(std::vector<T> a, std::vector<T> b,bool(func)(int)){
    std::vector<int> c;
    for(int z:a){
        if(func(z) && std::find(c.begin(),c.end(),z)!=c.end()){
            c.push_back(z);
        }
    }
    for(int z:b){
        if(func(z) && std::find(c.begin(),c.end(),z)!=c.end()){
            c.push_back(z);
        }
    }
    return c;
}
//Equality Function
//template <typename A0, typename ... Args>
auto equalityU =[](auto const & a0, auto const & ... args)
 { return ( (args == a0) && ... && true ); };

 
template<typename rest>
auto matMulPossible(rest const& tuple1){
    int i=0;
    int prev_elem;
    if(std::tuple_size<rest>{}%2 !=0){return false;}
    auto const eval =[&](auto const& pair){
    if(i %2==0){
        prev_elem=std::get<1>(pair);
        i++;
    }
    else{
        if(prev_elem!=get<0>(pair)){
                return false;    }
    }
    return true;

    };

 return std::apply([&eval](auto const& ...pairs){
     return(eval(pairs)&&...);},tuple1);
 }