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

/*
item_16
成对使用 new 和 delete 时要采取相同形式

std::string* stringArray = new std::string[100];
delete stringArray;
该方式会导致内存泄漏
delete stringArray[];   // bingo

不要使用数组的形式进行 typedef
typedef std::string addLines[2];  // not good
*/

/*
以独立语句将 new 对象置入智能指针
以独立语句将 new 对象存储于智能指针中. 如果不这样做, 一旦异常有可能导致难以察觉的资源泄漏.
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
