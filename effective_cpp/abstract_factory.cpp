// 工厂方法 A
class AbstractProductA {
 public:
  virtual ~AbstractProductA(){};
  virtual std::string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
 public:
  std::string UsefulFunctionA() const override {
    return "The result of the product A1.";
  }
};

class ConcreteProductA2 : public AbstractProductA {
  std::string UsefulFunctionA() const override {
    return "The result of the product A2.";
  }
};

// 工厂方法 B
class AbstractProductB {
 public:
  virtual ~AbstractProductB(){};
  virtual std::string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductB {
 public:
  std::string UsefulFunctionA() const override {
    return "The result of the product A1.";
  }
};

class ConcreteProductA2 : public AbstractProductB {
  std::string UsefulFunctionA() const override {
    return "The result of the product A2.";
  }
};


// 当 A1 B1, A2 B2 存在强相关关系时, 防止出现 A1 B2, A2 B1的情况
class AbsFactory() {
 public:
  virtual AbstractProductA *CreateProductA() const = 0;
  virtual AbstractProductB *CreateProductB() const = 0;
}

// 将 A1 B1 工厂强绑定到新的抽象类里
class ConcreteFactory1 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA1();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB1();
  }
};

// 将 A2 B2 强绑定到新的抽象类里
class ConcreteFactory2 : public AbstractFactory {
 public:
  AbstractProductA *CreateProductA() const override {
    return new ConcreteProductA2();
  }
  AbstractProductB *CreateProductB() const override {
    return new ConcreteProductB2();
  }
};


