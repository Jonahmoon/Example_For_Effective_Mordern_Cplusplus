针对左值，万能引用等效左值引用；针对右值，万能引用等效右值引用；
 

针对左/右值，万能引用都正确进行了推导，那为啥还要有std::forward?
因为右值引用是左值！！万恶之源
 

有点绕，为啥右值引用是左值？
右值，就是“无名”的value，只有值，没有变量名；
右值引用，本身就是一个变量，当然是左值；
右值引用在绑定了右值后，为右值增加了一个“句柄”，这样看也当然是左值；
 

右值引用是左值，会造成什么问题？
当我们调用wrapper(3)时， wrapper将会尝试调用 func(int &)， 而非 func(int &&)；
 

那么std::forward到底干了什么？
针对这种特殊情况，进行了“强制类型转换”, int & -> int &&
std::string&& forward(std::string& param) { return static_cast<std::string&&>(param); }
左值引用本身就是左值，因而无需特殊处理；
 

 

#include <iostream>
#include <string>
 
template <typename T>
void wrapper(T&& arg) {
    func(arg);
}
 
template<typename T>
T&& forward(typename std::remove_reference<T>::type& param) {
    return static_cast<T&&>(param);
}
 
/*
 如果是左值，啥事都不干；
std::string& forward(std::string& param) {
    return static_cast<std::string&>(param);
}
std::string&& forward(std::string& param) {
    return static_cast<std::string&&>(param);
}
 */
 
int main() {
    std::string s("hello");
 
    std::string &&arg = "hello";
 
    std::string &lref = arg;
 
    std::cout << lref << std::endl;
 
    wrapper(s);
    /*
        左值, T -> std::string&, T&& -> std::string&， 左值引用
        void wrapper(std::string &arg) {
            func(arg);
        }
     */
    
    wrapper("hello");
    /*
         右值, T -> std::string, T&& -> std::string&&， 右值引用
        void wrapper(std::string &&arg) {
            func(arg);
        }
      */
    
    return 0;
}