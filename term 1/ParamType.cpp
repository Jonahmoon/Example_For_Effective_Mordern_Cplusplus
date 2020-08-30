#include<iostream>

using namespace std;

template<typename T>
void f(T& param) {
    std::cout<<"f"<<std::endl;
};

template<typename T, std::size_t N>
constexpr std::size_t g(T (&)[N]) noexcept
{
    std::cout<<N<<std::endl;
}

int main() {
    int x[2]={1,3};
    f(x);
    g(x);
    return 1;
}