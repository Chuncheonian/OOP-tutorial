/**
 * @file    08_array.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   Static Array, Dynamic Array, 2-D Dynamic Array, String vs Array
 * @date    2020-04-16
 */
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// 1. Static Array
int sum(int* arr, int size) {
  int result = 0;

  for (int i = 0; i < size; i++)
    result += arr[i];
  
  return result;
}

void print(int* begin, int* end) {
  for (int* curr = begin; curr != end; curr++)
    cout << setw(4) << *curr;
}

// Array: 배열의 시작 주소값을 저장하는 Pointer
int main() {
  int arr[3] = {10, 20, 30};    // Initialize Array
  // int arr[] = {10, 20, 30};  // 이 또한 가능

  cout << arr[0] << '\t' << arr[1] << '\t' << arr[2] << endl; // 배열의 원소 출력

  int size_arr = sizeof(arr) / 4;     // sizeof(): Return Array size
  cout << sum(arr, size_arr) << endl; // Array를 함수로 보낼 때 size도 보냄, 함수 안에서 sizeof()사용시 값 안나옴.

  cout << arr << '\t' << &arr[0] << '\t' << *arr << endl; // 배열의 이름은 첫번째 원소의 주소를 저장하는 포인터이다.
  cout << (arr+1) << '\t' << *(arr+1) << endl;            // arr+1: 주소값 1++가 아니다.
  cout << (arr+2) << '\t' << *(arr+2) << endl;            // 주소값은 4byte(int)씩 증가

  int* begin = arr;           // 시작 주소값
  int* end = arr + size_arr;  // 끝 주소값
  cout << *begin << '\t' << *(end-1) << endl;
  print(begin, end);

  return 0;
}

/*
// 2. Dynamic Array
void get_data(int* begin, int* end) {
  cout << "Enter the elements: ";
  for (int* curr = begin; curr != end; curr++)
    cin >> *curr;
}

void print(int* begin, int* end) {
  cout << "Print elements: ";
  for (int* curr = begin; curr != end; curr++)
    cout << setw(4) << *curr;
  cout << endl;
}

// Static Array(정적 배열)  : 프로그램 실행 중(Run-time) 크기가 고정
// Dynamic Array(동적 배열) : 프로그램 실행 중 할당/해제가 가능 (프로그램이 크면 주로 사용)
int main() {
  const int size = 3;
  int static_arr[size] = {10, 20, 30}; // Initialize Static Array

  int length;
  cout << "Enter the length: ";
  cin >> length;
  int* dynamic_arr = new int[length]; // Initialize Dynamic Array && Allocate Memory

  int* begin = dynamic_arr;
  int* end = dynamic_arr + length;

  get_data(begin, end);
  print(begin, end);

  delete[] dynamic_arr; // Deallocate Memory

  return 0;
}
*/

/*
// 3. 2-D Dynamic Array
void print(int** matrix, int n_row, int n_col) {
  for (int row = 0; row < n_row; row++) {
    for (int col = 0; col < n_col; col++)
      cout << setw(4) << matrix[row][col];
    cout << endl;
  }
}

int main() {
  int matrix[2][3]; // 2x3 Static 2D Array
  // vector< vector<int> > v(2, vector<int(3));

  int n_row = 2, n_col = 3;
  // int** -> (int*)*
  // 뒤에 있는 * : dynamic_matrix가 주소값을 저장하는 포인터 변수이다.
  // (int*) 이 포인터가 저장하는 주소값은 포인터형 변수에 대한 주소값을 저장한다.
  int** dynamic_matrix = new int*[n_row];
  
  for (int i = 0; i < n_row; i++)
    dynamic_matrix[i] = new int[n_col];
  // matrix2[0](타입은 int*) -> 0x10, matrix2[1] -> 0x20
  dynamic_matrix[0][0] = 1; dynamic_matrix[0][1] = 2; dynamic_matrix[0][2] = 3;
  dynamic_matrix[1][0] = 4; dynamic_matrix[1][1] = 5; dynamic_matrix[1][2] = 6;

  print(dynamic_matrix, n_row, n_col);

  for (int i = 0; i < n_row; i++)
    delete[] dynamic_matrix[i];
  delete[] dynamic_matrix;

  return 0;
}
*/

/*
// 4. String vs Array
//  String(문자열)은 char형 Array이다.
//  ※ String의 마지막에 NULL이 숨겨져 있다. NULL == '\0'

// (1). String을 Array로 다루는 4가지 방법
//  char s[4] = {'o', 'o', 'p', '\0'};
//  char s[] = {'o', 'o', 'p', '\0'};
//  char s[4] = "oop";
//  char s[] = "oop";

// (2). String을 Pointer로 다루는 방법
//  const char* s = "oop";

// (3). Array과 Pointer의 차이점
//  Array에 String을 한번 대입하면 다시 대입 불가
//  Pointer는 String을 여러 번 대입 가능(const 있으면 대입 불가)

bool find_char(const char* s, char ch) {
  while (*s != '\0') {
    if (*s == ch)
      return true;
    s++; // 문자열에서 다음 문자로 이동
  }
  return false;
}

int main() {
  const char* phrase = "this is a phrase";  // const char는 문법이니 그냥 암기하자
  cout << phrase << endl;
  
  // 'A': 65
  // 'a': 65 + 32
  for (char ch = 'a'; ch <= 'z'; ch++) {
    cout << ch << " is ";
    if (!find_char(phrase, ch))
      cout << "NOT ";
    cout << "in (" << phrase << ")" << endl;
  }

  return 0;
}
*/