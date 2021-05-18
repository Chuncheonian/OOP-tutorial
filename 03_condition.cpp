/**
 * @file    03_condition.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   Bool Operator, if, switch
 * @date    2020-03-31
 */
#include <iostream>
#include <iomanip>  // setw(int): 출력 폭 지정
#include <cmath>
#include <locale>
using namespace std;

/*
// 1. Bool Operator
int main() {
  bool a = false;
  bool b = (10 <= 5);
  bool c = 0;

  cout << a << '\t' << b << '\t' << c << endl;
  
  return 0;
}
*/

/*
// 2. if condition
// if ~ if else ~ else : 순차적으로 조건을 탐색한 다음, true인 곳의 block을 실행
// 1. 처음에는 반드시 if문을 적어준다.
// 2. else는 반드시 마지막, 위에 있는 모든 조건이 거짓인 경우 default로 수행
// 3. block안 문장이 하나일 경우 중괄호 생략 가능
int main() {
  int score;
  char grade;
  cout << "Enter the score [0, 100]: ";
  cin >> score;

  if (score >= 0 && score <= 100) {
    if (score >= 90)
      grade = 'A';
    else if (score >= 80)
      grade = 'B';
    else if (score >= 70)
      grade = 'C';
    else
      grade = 'F';

    cout << "Grade is " << grade << endl;
  }
  else
    cout << "Invalid range" << endl;
  
  return 0;
}
*/

/*
// 3. switch
int main() {
  char input;
  cout << "Enter a key:";
  cin >> input;

  switch (input) {
    case 'P':
    case 'p':
      cout << "Pause" << endl;
      break;
    case 'Q':
    case 'q':
      cout << "Quit" << endl;
      break;
    default:
      cout << "Invalid key" << endl;
      break;  // 굳이 작성안해도 됨
  }

  return 0;
}
*/