/*
item_18
使接口容易被使用, 难以被误用
1. 接口一致性, 内置类型兼容性
2. 防止误用: 建立新类型, 限制类型的操作, 束缚对象值, 消除客户的资源管理责任
3. 任何要求用户必须做的某件事情, 就是 "不正确" 的倾向, 因为用户都会忘记做那件事 
4. 使用 智能指针 防止动态链接问题

class Date {
public:
    Date(int day, int month, int year);
}
这种日期类的传入时, 没有限制任何参数

class Day {
public:
    static Day day1() {return Day(1);}
    static Day day2() {return Day(2);}
    ...
    static Day day31() {return Day(31);}
private:
    explicit Day(int d) : day(d) // 以private 构造的方式防止 1~31 以外的日期被构造
    int day;
}

class Date{
public:
    Date(const Day::day31(), int mouth, int year);
}
以限制 day 的类型来传入参数, 则可以防止误用
*/

/*
item_19
treat class design as type design. 设计 class 如同设计 type

1. 对象的创建和销毁
2. 对象的初始化和赋值差别
3. 被 passeed by value 时意味着什么
4. 新type 的合法值
5. 新type 需要配合的继承有哪些
6. 新type 需要哪些转换
7. 什么样的操作符和函数对新type 是合理的
8. 什么样的标准函数是不合理的
9. 谁该取用type 的成员
10. 新type 的 未声明接口
11. type 是否需要模板化
12. 是否真的需要一个新 type
*/

/*
item_20
用 pass-by-reference-to-const 替换 pass-by-value
内置类型, STL迭代器和函数对象 使用pass-by-value

class A{};
void func(const A& a);
*/

/*
item_21
必须返回对象时, 不要返回其 reference

当函数返回一个 reference 或者 pointer 时, 指向的 heap-allocate 对象或 local static 对象, 可能在多个结果中返回的是同一个对象
*/

/*
将成员变量声明为 private

1. private 提供了更好的访问权限控制能力
2.当 private 变量在继承或者其他场景使用时, 如果将其修改为 protected 或 public 对现有的代码改动很小, 
  反过来如果改动 protected 或 public, 则影响很大
*/

/*
item_23
以 non-member, non-friend 替换 member函数

1. 让一个 non-member 函数位于 class 的同一个命名空间里
namespace WebBrowser{
    class WebBrowsser{...};
    void clearBrowser(WebBrowsser& wb);
}
2. 将一个 class 相关的函数放在多个头文件但隶属于同一个命名空间, 可以在使用时不 include 所有class 相关项, 减少编译项
*/

#include <memory>
#include <cstdio>

void print(int* n) {
    printf("%d", *n);
}

class A{};

int main() {
    std::shared_ptr<A> p(0, print);
    auto native_pp = p.get();
    delete native_pp;
    native_pp = nullptr;
    p.reset();
    return 0;
}
