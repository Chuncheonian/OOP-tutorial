/**
 * @file    12_class_inheritance.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   class - Inheritance, Dynamic Binding, Overrie
 * @date    2020-05-21
 */
#include <iostream>
#include <vector>
using namespace std;

// private(class내 접근 가능), protected(class내 접근 가능), public(class내/외 접근 가능)
// protected: Base class에서 상속을 위해 사용

//     Base type   |  Inheritance type    |   Derived type
// ------------------------------------------------------------------------------------------------
//    private    |  상관 없음           |   접근 불가(Base의 다른 접근가능한 method를 통해 접근)
//   protected  |  상관 없음           |   private
//  public     |  private/protected   |   private
// public     |  public              |   public

class Base {
public: // Base type
  virtual ~Base() {}  // virtual 사용 시 destructor도 virtual 선언해야 compile 가능

  void print_base() { cout << "Base" << endl; }

  virtual void print() { cout << "Base::print()" << endl; }

};

class Derived: public Base {  // Inheritanace type
public: // Derived type
  void print_base() {
    cout << "Derived" << endl;
    Base::print_base();
  }

  void print() override { cout << "Derived::print()" << endl; }
};

int main() {
  Base base;
  Derived derived;
  base.print_base();
  derived.print_base();
  derived.print();
  cout << endl;

  // Overriding: Base class의 method를 Derived class에서 같은 선언으로 재 정의
  // Static Binding: compile할 때 Object가 어떤 method를 호출할 지 미리 결정(변경 x)
  base.print();
  derived.print();
  cout << endl;

  // Dynamic Binding: run-time시 호출할 methodfmf 상황에 맞게 결정(변경 o)
  // - 부모 class의 Pointer의 자식 class Object의 주소값을 할당할 수 있다.
  // - 핵심 keyword: virtual, override
  // - 응용:  다형성 (Single interface로 다양한 자식 class를 사용)
  Base* pBase = &derived;
  pBase->print();
  pBase = &base;
  pBase->print();
  cout << endl;

  vector<Base*> vec{ new Base, new Derived, new Base};
  pBase = new Derived;
  vec.push_back(pBase);

  for (auto& elem: vec)
    elem->print();

  for (auto& elem: vec)
    delete elem;

  return 0;
}