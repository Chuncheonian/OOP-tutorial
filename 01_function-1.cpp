/**
 * @file    01_function[1].cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   Basic Function
 * @date    2020-03-24
 */
#include <iostream>   // cin, cout 사용하기 위해서 작성.
#include <cmath>      // cos, log, exp, sqrt,... 를 사하기 위해서 작성.
using namespace std;  // std안의 namespace 안의 함수가 cin, cout이다.

// 1. Function Declaration[1]
int square(int a);  // 함수 선언, main function 위에 작성

int main() {
  int x;
  x = 5;

  cout << square(x) << endl;

}

int square(int a) { // 위에서 선언한 함수를 정의.
  return a*a;
}

/*
// 2. Function Declaration[1]

// 함수 선언부
int get_data();
int sum(int a, int b);
int subt(int a, int b);
int mult(int a, int b);
float divi(int a, int b);

int main() {
  int x, y;
  x = get_data();
  y = get_data();

  cout << "x = " << x << ", y = "<< y << endl;
  cout << "x + y = " << sum(x , y) << endl;
  cout << "x - y = " << subt(x , y) << endl;
  cout << "x * y = " << mult(x , y) << endl;
  cout << "x / y = " << divi(x , y) << endl;
  
  return 0;
}

// 함수 정의부
int get_data() {
  int a;
  cout << "Enter a number: ";
  cin >> a;

  return a;
}

int sum(int a, int b) {
  return a + b;
}

int subt(int a, int b) {
  return a - b;
}

int mult(int a, int b) {
  return a * b;
}

float divi(int a, int b) {
  return (float)a / b;  // 형 변환 3가지 방법: (float)a, float(a), 1.0*a
}
*/

/*
// 3. Use Standard Library.
int main() {
  double val;
  val = 5;
  cout << sqrt(val) << endl;  // root
  cout << exp(val) << endl;   // exponential
  cout << log(val) << endl;   // log
  cout << cos(val) << endl;   // cosine
  
  return 0;
}
*/

/*
// 4. Function Declaration && Definition.
// 단점: main function이 밑으로 내려가서 가독성 불편
void applePrice(int n = 1000) {  // n = 1000 → default augment, [default augment는 선언부분에만 사용가능, 구현부분에서는 사용x]
  cout << "Apple price = " << n << endl;
}

int main() {
  applePrice(1500);
  applePrice();

  return 0;
}
*/