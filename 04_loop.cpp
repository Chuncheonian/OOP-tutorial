/**
 * @file    04_loop.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   for, nested for loop, while, do while, continue & break
 * @date    2020-04-02
 */
#include <iostream>
#include <iomanip>
using namespace std;

// 1. for
int main() {
  int sum = 0;
  // i는 1부터 100까지, 매 반복마다 i를 1증가시키면서 body 수행
  for (int i = 1; i <= 100; i++) {  // 초기값; 반복조건; modification
    sum += i;
  }
  
  // int i = 1; // initialization(초기값)
  // while (i <= 100) { // condition(반복조건)
  //   sum += i; // body
  //   i++; // modification (매 loop마다 update되는 값)
  // }
  
  cout << sum << endl;

  return 0;
}

/*
// 2. Nested for loop
int main() {
  for (int row = 1; row <= 5; row++) {
    for (int col = 1; col <= 5; col++) {
      int val = row * col;
      cout << setw(4) << val;
    }
    cout << endl;
  }
  
  return 0;
}
*/

/*
// 3. while condition
// while(조건): 참이면 block 수행, 그렇지 않으면 탈출
// block을 수행한 다음, while()로 다시 이동
int main() {
  int sum = 0;
  int i = 1;
  cout.imbue(locale(""));
  
  while (i <= 100) {
    sum = sum + i;
    cout << setw(4) << i << setw(10) << sum << endl;
    i++;
  }
  return 0;
}
*/

/*
// 4. while practice
int main() {
  int row = 1, col = 1;
  
  while (row <= 5) {
    col = 1;
    while (col <= 5) {
      // int val = row * col;
      // int val = (row > col ? row : col);
      int val = 0;

      if (row == col)
        val = 1;
      cout << setw(4) << val;
      col++;
    }
    return 0;
  }
}
*/

/*
// 5. do ~ while
// while(): 조건식 -> body -> 조건식
// do ~ while(): body -> 조건식 -> body
int main() {
  int input;

  do {
    cout << "Enter a number [0, 100]: ";
    cin >> input;
  } while (!(input >= 0 && input <= 100));  // do ~ while 끝에는 반드시 세미콜론

  cout << "output: " << input << endl;

  return 0;
}
*/

/*
// 6. continue & break
// continue: 반복처리를 건너 뛴 다음, 블록의 시작 위치로 돌아가서 다음 작업 진행
// break: 처리의 흐름을 강제로 종료시키고, 그 블록에서 탈출
int main () {
  int sum = 0;
  int input;

  while (true) {
    cout << "Enter a number: ";
    cin >> input;
    if (input < 0)
      continue; // 아랫 부분은 실행하지 않고 while문의 첫째줄로 jump
      // break; // 반복문 탈출
    
    sum += input; // sum = sum + input
    cout << "sum: " << sum << endl;
  }
  return 0;
}
*/