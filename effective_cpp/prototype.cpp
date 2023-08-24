/*
主要用于对复杂对象的创建, 拷贝一个相同的对象
*/

class Base
{
public:
    Base() {}
    virtual ~Base() {}

    virtual Base* clone() = 0;
};

class ProtoA : public Base
{
public:
    ProtoA() {}
    ~ProtoA() {}

    virtual Base* clone() override {
        return new ProtoA(*this);
    }
};

class ProtoB : public Base
{
public:
    ProtoB() {}
    ~ProtoB() {}

    virtual Base* clone() override {
        return new ProtoB(*this);
    }
};

int main() {
    Base* A = new ProtoA;
    Base* copy_A = A->clone();
    return 0;
}
