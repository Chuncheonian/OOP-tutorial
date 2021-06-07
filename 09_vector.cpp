/**
 * @file    09_vector.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   Vector, Vector Practice, two-dimensional Vector
 * @date    2020-04-21
 */
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// 1. Vector
// Vector : 개수를 알 수 없는 대량의 데이터를 관리하기 위한 동적 배열 자료구조
// &      : 객체는 pass by ref로 보내서 메모리 효율 증가. 즉, vector를 입력 파라미터로 사용시 & 쓰자
// const  : 함수 안에서 입력 객체의 data가 바뀌지 않음을 보증
void print(const vector<int>& vec) {
  for (unsigned int i = 0; i < vec.size(); i++) // size() Method는 unsigned int형을 반환해서 i의 타입을 unsigned int로 한다.
    cout << setw(4) << vec[i];
  cout << endl;
}

int sum(const vector<int>& vec) {
  int result = 0;
  for(int elem: vec)
    result += elem;

  return result;
}

// string과 vector는 기능이 같다. 그러나
// string은 char만 저장 가능하고, vector는 모든 타입형 저장 가능(하나의 vector에는 하나의 타입만 저장가능)

// vector: size(), at(), push_back(), pop_back() 4개의 Method 주로 사용
int main() {

  vector<int> vec = {10, 20, 30, 40};

  cout << vec.size() << endl; // size(): element의 개수를 반환
  print(vec);

  vec[0] = 100;
  vec.at(1) = 200; // vec[i] == vec.at[i]
  print(vec);

  vec.push_back(50); // push
  print(vec);

  vec.pop_back(); // pop
  print(vec);

  // 추천 X
    // for (int i = 0; i < vec.size(); i++)
    //   cin >> vec[i];

  // vector의 원소를 탐색할 때 주로 사용
    // int& elem = vec[0]; -> body(cin >> elem)
    // int& elem = vec[1]; -> body(cin >> elem)
    // int& elem = vec[2]; -> body(cin >> elem)
    // int& elem = vec[3]; -> body.....(마지막 element까지 size()-1)
  for (int& elem: vec) {
    cout << "input Number: ";
    cin >> elem;
  }
    // int elem = vec[0]; //body(cout << setw(4) << elem)
    // int elem = vec[1]; //body ....
    // .... 마지막 element까지
  for (int elem: vec) {
    cout << setw(4) << elem;
  }
  cout << endl;

  cout << sum(vec) << endl;

  return 0;
}

/*
// 2. vector practice 
void print(const vector<int>& vec) {
  for (int elem: vec)
    cout << setw(4)<< elem;
  cout << endl;
}

bool is_prime(int num) {
  if (num <= 1)
    return false;
  
  for (int i = 2; i < num; i++) {
    if (num % i == 0)
      return  false;
  }
  return true;
}

vector<int> primes(int low, int high) {
  vector<int> vec;
  for (int i = low; i <= high; i++) {
    if (is_prime(i))
      vec.push_back(i);
  }
  return vec;
}

int main() {
  int low, high;
  cin >> low >> high;
  vector<int> vec = primes(low, high);
  print(vec);
  
  return 0;
}
*/

/*
// 3. two-dimensional Vector
// auto: compiler가 data type을 명확히 알 수 있을 때 type을 자동적으로 치환
void print(const vector< vector<int> >& vec) {
  // 비추천
  // for (int row = 0; row < vec.size(); row++) {
  //   for (int col = 0; col < vec[row].size(); col++)
  //     cout << setw(4) << vec[row][col];
  //   cout << endl;
  // }
  
  // 추천
  for (const auto& row: vec) {  // auto = vector<int>, vector는 Object(무거움)이므로 reference(&)를 한다
    for (auto elem: row)        // auto = int, int는 무겁지 않아 reference(&)를 안한다.
      cout << setw(4) << elem;
    cout << endl;
  }
}

int main() {
  // vector<vector<int>> v(2, vector<int>(3)); // 2*3
  // v[0][0] = 1;    v[0][1] = 2;    v[0][2] = 3;
  // v[1][0] = 4;    v[1][1] = 5;    v[1][2] = 6;
  vector< vector<int> > v { {1, 2, 3}, {4, 5, 6} };
  print(v);

  return 0;
}
*/