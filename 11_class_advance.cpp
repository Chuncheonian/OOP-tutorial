/**
 * @file    11_class_advance.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   class - Destructor, Dynamic Allocation, Operator Overloading, friend
 * @date    2020-05-12
 */
#include <iostream>
using namespace std;

// destructor(소멸자)         : 객체가 할당해제될 때 한번 자동으로 호출되는 함수
// this Pointer               : 현재 객체 자기자신의 주소 값을 저장하고 있는 Pointer
// static member-data/method  : 모든 객체가 공유하고, 접근할 수 있는 member-data/method
// friend                     : class의 모든 정보에 접근 가능(private 포함)
class Point {
private:
  int         m_x;
  int         m_y;
  static int  m_numCreatedObjects; // static: 정적 수명을 가진 지역 변수
  int*        m_arr;

public:
  Point(int _x = 0, int _y = 0) : m_x(_x), m_y(_y) {
    m_numCreatedObjects++;  // instance 생성할 때마다 1 증가
    m_arr = new int[10];
  }
  
  // Destructor(소멸자): 주로 할당해제, file close를 담당
  ~Point() {
    cout << "Destructed" << endl;
    delete[] m_arr;
  }

  int GetX() const { return this->m_x; }
  
  int GetY() const { return this->m_y; }

  // 외부의 값에 의해서 객체의 멤버변수가 변경되므로 const를 붙이면 안된다.
  void SetXY(int _x, int _y) {
    this->m_x = _x;
    this->m_y = _y;
  }

  Point operator+(const Point& pt) {
    Point result(this->m_x + pt.m_x, this->m_y + pt.m_y);
    return result;
  }

  Point operator=(const Point& pt) {
    this->m_x = pt.m_x;
    this->m_y = pt.m_y;
    return (*this);
  }

  static int GetNumCreatedObject() { return m_numCreatedObjects; }

  friend void Print(const Point& pt);
  
  friend ostream& operator<<(ostream& cout, const Point& pt);
  
  friend class Spy;
};

// static Member Variable Initialize
int Point::m_numCreatedObjects = 0;

// Object는 Call by Ref.로 전달하고, 이 때 const로 사용하여 parameter의 Object의 멤버 변수 변경 x
void Print(const Point& pt) {
  cout << pt.m_x << ", " << pt.m_y << endl;
}

// // Overload: 이름이 같은 함수지만 Parameter가 다른 경우
void Print(int a) {
  cout << a << endl;
}

// class안의 method를 이런 식으로 작성 가능
// Point operator+(const Point& pt1, const Point& pt2) {
//   Point result(pt1.GetX() + pt2.GetX(), pt1.GetY() + pt2.GetY());
//   return result;
// }

ostream& operator<<(ostream& cout, const Point& pt) {
  cout << pt.m_x << ", " << pt.m_y;
  return cout;
}

class Spy {
public:
  void HackAllInfo(const Point& pt) {
    cout << "Hacked by Spy" << endl;
    cout << "x : " << pt.m_x << endl;
    cout << "y : " << pt.m_y << endl;
    cout << "numCreatedObj : " << pt.m_numCreatedObjects << endl;
    cout << endl;
  }
};

int main() {
  Point pt1(1, 2);
  Print(pt1);
  cout << pt1.GetNumCreatedObject() << endl;
  cout << endl;

  // 1. Dynamic Allocation
  Point* pPt = new Point(10, 20); // pointer: "." 대신에 "->" 로 access
  cout << (*pPt).GetX() << ", " << (*pPt).GetY() << endl; // 비 추천
  cout << pPt->GetX() << ", " << pPt->GetY() << endl; // 추천
  cout << pt1.GetNumCreatedObject() << endl;
  cout << endl;

  int size = 5;
  Point* ptArr = new Point[size];
  for (int i = 0; i < size; i++) {
    cout << ptArr[i] << endl;
  }
  delete[] ptArr;
  cout << pt1.GetNumCreatedObject() << endl;
  cout << endl;

  // 2. Operator Overloading
  // int a = 2 + 3;  // basic
  Point pt2(10, 20), pt3(30, 40);
  Point pt4 = pt2 + pt3;
  cout << pt2 << endl;  // "<<" == ostream's Object
  cout << pt3 << endl;
  cout << pt4 << endl;
  cout << pt1.GetNumCreatedObject() << ", "<< pt2.GetNumCreatedObject() << endl;
  cout << endl;

  // 3. friend
  Spy spy;
  spy.HackAllInfo(pt1);
  spy.HackAllInfo(pt4);

  return 0;
}