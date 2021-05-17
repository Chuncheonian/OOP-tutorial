/**
 * @file    02_function[2].cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   Local Var, Global Var, Recursive Function, Ref Var, Pass By Ref.
 * @date    2020-03-26
 */
#include <iostream>
using namespace std;

// 1. Local Variable
// local variable(지역변수): 함수 안에서 선언/사용되다가 함수가 끝나면 소멸.
void increase(int x) {
  x++;
  cout << "in increase: " << x << endl;
}

int main() {
  int x = 10; // 선언 + 할당 = 초기화
  cout << x << endl;
  increase(x);
  cout << x << endl;

  return 0;
}

/*
// 2. Global Var vs. Local Var
// local variable:  함수 안에서 선언&사용&소멸
// global variable: 함수 외부에서 선언&모든곳에서 사용&소멸x && 한번 만들면 없앨 수 없음 == 메모리 비효율적
// 충돌 시: local variable > global variable

int gX; // global var

void print() {
  gX = 1000; // 타입형을 넣으면 local var.
  cout << "gX in print: " << gX << endl;
}

int main() {
  gX = 10; // 타입형을 넣으면 local var.
  cout << gX << endl;
  print();
  cout << gX << endl;

  return 0;
}
*/

/*
// 3. Recursive Function
// Recursive function(재귀함수): 자기자신을 함수 내부에서 호출하는 함수
// 5! = 5*4! || f(n) = n * f(n-1)
int factorial(int n) {
  if (n == 0) // termination condition
    return 1;
  
  return n * factorial(n-1); // base condition
}

int pow2(int n) {
  if (n == 0)
    return 1;

  return 2 * pow2(n - 1);
}

int main() {
  int x;
  cin >> x;

  cout << factorial(x) << endl;
  cout << pow2(x) << endl;

  return 0;
}
*/

/*
// 4. Reference Variable
int main() {
  int x = 10;
  // int y = x;
  int& y = x; // y는 x의 reference variable
  cout << x << '\t' << y << endl;
  x = 1000;
  cout << x << '\t' << y << endl;
  y = 100;
  cout << x << '\t' << y << endl;

  return 0;
}
*/

/*
// 5. Pass By Ref
// Pass by value(복사) int a = x; int b = y;
// Pass by reference(참조) int &a = x; int &b = y;
// - 장점: (1) 함수의 return값을 여러개 만들 수 있다.
// -       (2) 메모리 효율 - 복사가 필요없음
void swap(int& a, int& b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int x = 10, y = 1000;
  cout << x << '\t' << y << endl;
  swap(x, y);
  cout << x << '\t' << y << endl;

  return 0;
}
*/