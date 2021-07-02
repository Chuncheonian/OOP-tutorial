/**
 * @file    10_class_basic.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   class declaration, class practice
 * @date    2020-04-30
 */
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// 1. class declaration
//  1). class Name {};
//  2). private: 영역에 data member를 선언
//  3). public:  영역에 member function(method)를 선언
//      - get(): data member를 외부로 반환
//      - set(): 외부에서 data member를 변경
//  4). 생성자(constructor)
//      - 기능: 객체를 선언할 때 자동으로 1회 호출 -> data member 초기화
//      - 모양: return type이 없고, 이름은 class 이름과 동일
//      - 만약 생성자를 만들지 않으면, default 생성자가 자동 생성 e.g. Point(){}
//      - 만약 생성자를 만들면, default 생성자가 생성되지 않음
//      - default argument 이용 -> 다양한 입력 효과적으로 생성자를 만들 수 있다.
//      - initialization list : 멤버 변수 초기화, 예외처리를 구분
class Point {
// class 내부에서만 사용가능 == 외부에서 사용 불가
private:
  int m_x;  // data member 선언
  int m_y;

// class 내,외부 사용가능 (member function, method)
public:
  Point() { // pt1처럼 Argument가 없을 경우
    m_x = 0;
    m_y = 0;
  }
  
  Point(int _x, int _y) { // 사용할 수 없는 method, 초기화를 위해 딱 한번 자동적으로 사용
    m_x = _x;
    m_y = _y;
  }

  // 아래 4개의 함수는 Method
  void setXY(int _x, int _y) {
    m_x = _x;
    m_y = _y;
  }

  int getX() { return m_x; }
  
  int getY() { return m_y; }
  
  void print() {
    cout << "(" << m_x << ", " << m_y << ")" << endl;
  }
};

int main() {
  Point pt1, pt2(10, 20);
  
  pt1.setXY(1, 2);
  cout << pt1.getX() << endl; // class private한 data member를 직접적으로 사용 불가
  cout << pt1.getY() << endl; // 사용할려면 method 이용

  pt1.print();
  pt2.print();

  return 0;
}

/*
// 2. class practice
class Account {
private:
  string m_name;
  string m_id;
  double m_balance; // data member 선언

public:
  Account(string _name = "xxx", string _id = "0000", double _bal = 0.0)
  : m_name(_name), m_id(_id), m_balance(_bal) {
    if (m_balance < 0)
      m_balance = 0;
  }

  // method를 선언과 정의 분리 가능
  void print();

  void deposit(int _amt);

  bool withdraw(int _amt);
};

void Account::print() {
  cout << setw(10) << m_name
    << setw(10) << m_id
    << setw(10) << m_balance << endl;
}

void Account::deposit(int _amt) {
  m_balance += _amt;
}

bool Account::withdraw(int _amt) {
  int temp = m_balance - _amt;
  if (temp < 0)
    return false;
  else {
    m_balance = temp;
    return true;
  }
}

int main() {
  Account ac1("KDY", "1002", 5000), ac2, ac3("HGD");  // Accout: class, ac: instance
  ac1.print();
  ac2.print();
  ac3.print();
  cout << endl;

  ac1.deposit(10000);
  ac1.print();
  cout << endl;

  if (!ac1.withdraw(1000000)) {
    cout << "Error: negative balance" << endl;
  }
  
  if (ac1.withdraw(5000)) {
    ac1.print();
  }
  cout << endl;

  vector<Account> vec(10);
  for (auto& elem: vec) {
    elem.print();
  }

  return 0;
}
*/