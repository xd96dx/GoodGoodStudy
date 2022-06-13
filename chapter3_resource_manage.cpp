/*
item_13

使用对象管理资源
使用智能指针管理资源
std::shared_ptr
std::unique_ptr

boost::scoped_array
boost::array
*/


/*
item_14

资源管理的类里, 小心 copy 行为
当在类中发生了 copy 时, 有时在析构不一定需要释放资源的操作, 使用 shared_ptr 来指定某个动作结束时的行为.
*/

/*
item_15

在资源类中, 提供对原始资源的访问
在类中, 提供显示转换 (类似 shared_ptr 的get 方法) 或隐式转换 (opeartor () const {return} )
*/

#include <memory>
#include <cstdio>
#include <iostream>

class A;

void print(int* n) {
    std::cout << *n << std::endl;
}

// void print(A a) {}

bool print_bool(bool n) {
    std::cout << n << std::endl;
    return n;
}

class A {};


class Item {
public:
    explicit Item(int* num) 
     : m(num, print)
    {
        std::cout << "in constructor" << std::endl;
    }
    ~Item() {
        std::cout << "in destructor" << std::endl;
    }

    operator bool() const {
        return m == nullptr;
    }

    operator A() const {}  // operator 居然可以这样隐式转换 太吊了!!!

private:
    std::shared_ptr<int> m;  // 当发生 copy assigment 时, 只会增加当前变量的引用计数, 而且不用特地写 copy 构造函数
};

int main() {
    auto p = new int(10);
    auto i = Item(p);
    auto i2 = i;
    print_bool(i);

    // using PTYPE = decltype(print);
    using T = decltype(print(std::declval<int*>()))(int*);
    std::shared_ptr<int> m1(p, print);
    std::unique_ptr<int, T*> m(p, print);

    std::cout << "leaving main..." << std::endl;
    return 0;
}
