#include<iostream>

int main() {
    const char name1[] =     //name的类型是const char[13]
    "R. N. Briggs";
    char name2[] =     //name的类型是const char[13]
    "R. N. Briggs";
    auto y =name1;
    auto x = name2;

    auto x1=27;         //类型是int，值是27
    auto x2(27);        //同上
    auto x3={27};       //类型是std::initializer_list<int>,值是{27}
    auto x4{27};        //同上
    std::initializer_list<int> x5={1,2,3};
}