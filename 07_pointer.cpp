/**
 * @file    07_pointer.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   Pointer Variable, Pass by Pointer, Function Pointer
 * @date    2020-04-14
 */
#include <iostream>
using namespace std;

// 1. Pointer Variable
// &x:      x의 메모리 주소값을 반환
// int* px: (int*)는 정수형 변수의 주소값을 저장하는 data type
//          포인터형 변수에 대한 data type
//          px는 정수형 변수의 주소값을 저장하는 pointer Variable
// *px:     px에 저장된 주소값으로 jump
// &:       주소값을 가리키는 것
// *:       점프
int main() {
  int x = 10;
  
  // 포인터 변수는 초기화를 수행하도록 작성하는 것이 좋다.
  // 그 이유는 실수로 선언만 하고 대입을 안하면 오류가 발생하기 때문
  int* px = &x;

  cout << &x << ", " << x << endl;
  cout << px << ", " << *px << endl;

  return 0;
}

/*
// 2. Pass by Pointer
// Pass by Value   (int a = x; int b = y; ):    단순 복사
// Pass by Ref     (int& a = x; int& b = y; ):  a는 x의 reference var
// Pass by Pointer (int* a = &x; int* b = &y;): a, b는 주소값을 저장할 수 있는 변수로 바뀜
void swap(int* a, int* b) {
  int tmp = *a; // *a == *(x's address) == 10
  *a = *b;      // *b == *(y's address) == 20
  *b = tmp;
}

int main() {
  int x = 10, y = 20;
  cout << x << ", " << y << endl;
  swap(&x, &y);
  cout << x << ", " << y << endl;

  return 0;
}
*/

/*
// 3. Function Pointer : 함수의 시작주소를 저장하는 변수
int sum(int a, int b) { return a + b; }
int mult(int a, int b) { return a * b; }
int evaluate(int (*f)(int, int), int a, int b) { return f(a, b); }

int main() {
  int (*func)(int, int);  // (int, int)의 입력, int의 출력을 가진 함수포인터. 즉, 입력 2개 출력 1개를 가진 포인터변수
  func = &sum;  // *func이 아님... 헷갈리지말자
  // int (*func)(int, int) = &sum 으로 해도됨!
  cout << func(10, 20) << endl;

  func = &mult;
  cout << func(10, 20) << endl;

  cout << evaluate(&sum, 10, 20) << endl;
  cout << evaluate(&mult, 10, 20) << endl;

  return 0;
}
*/