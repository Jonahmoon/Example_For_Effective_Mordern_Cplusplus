#include<iostream>
#include<string>
#include<vector>

template<typename Container,typename Index>     //最终的C++14版本
decltype(auto)
authAndAccess(Container&& c,Index i){
    //authenticateUser();
    return std::forward<Container>(c)[i];
};

template<typename Container,typename Index>     //最终的C++11版本
auto
_authAndAccess(Container&& c,Index i)
->decltype(std::forward<Container>(c)[i])
{
    //authenticateUser();
    return std::forward<Container>(c)[i];
};

int main() {
    const int x=0;
    std::vector<int> d{1,2,3,4};
    std::cout<<authAndAccess(d,1)<<std::endl;
    std::cout<<_authAndAccess(d,2);
}