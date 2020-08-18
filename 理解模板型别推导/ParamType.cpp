#include<iostream>

using namespace std;

template<typename T>
void f(T& param) {
    std::cout<<param<<std::endl;
};

int main() {
    int x = 27;
    const int cx = x;
    const int& rx = x;
    cout<<x<<endl;
    f(x);
    f(cx);
    f(rx);
    return 1;
}