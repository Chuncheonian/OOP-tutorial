/**
 * @file    06_largeDataProcessing-2.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   cout & cin Method, File Stream Practice
 * @date    2020-04-09
 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// 1. cout method
int main() {
  double a = 12.345678;  // 부동 소수점 숫자를 출력할 때 std::cout의 기본 정밀도는 6
  cout << a << endl;
  
  cout.width(15);     // width()는 cout의 method | setw(15)는 그냥 함수
  cout.precision(4);  // 4자릿수만 출력
  cout.fill('-');     // 공백에 문자를 채움

  cout << a << endl;

  return 0;
}

/*
// 2. cin method
// setf(서식 플래그): 서식 상태 플래그 설정
// unsetf(서식 플래그): 서식 상태 플래그 해제
int main() {
  char ch;

  cin.unsetf(ios::skipws);  // 공백은 문자로 취급안하는데 그걸 해주게 해줌
  cin >> ch;
  cout << '(' << ch << ')' << endl;

  cin.setf(ios::skipws);  // 원상복구
  cin >> ch;
  cout << '(' << ch << ')' << endl;

  return 0;
}
*/

/*
// 3. File Stream Practice
bool readStd(ifstream& fin, int& id, int& score1, int& score2, int& score3) {
  fin >> id >> score1 >> score2 >> score3;
  if (!fin)
    return false;
  else
    return true;
}

void calcGrade(int& score1, int& score2, int& score3, int& avg, char& grade) {
  avg = (score1 + score2 + score3) / 3;

  if (avg >= 90)
    grade = 'A';
  else if (avg >= 80)
    grade = 'B';
  else if (avg >= 70)
    grade = 'C';
  else if (avg >= 60)
    grade = 'D';
  else
    grade = 'F';
}

void writeStd(ofstream& fout, int id, int avg, char grade) {
  fout.width(4);
  fout.fill('0');
  fout << id;
  fout.width(3);
  fout.fill(' ');
  fout << avg;
  fout.width(2);
  fout << grade << endl;
}

// 1) ch7STUFL.DAT 파일로부터 학생정보를 1줄씩 읽는다. (id, sc1, sc2, sc3)
// 2) sc1, sc2, sc3를 평균내고 평균값(avg)으로 grade를 구한다.
// 3) grade.txt에 id, avg, grade를 저장한다.
int main() {
  ifstream fin("ch7STUFL.DAT");
  ofstream fout("grade.txt");
  int id, score1, score2, score3, avg;
  char grade;

  if (!fin | !fout) {
    cout << "file open error" << endl;
    exit(100);
  }

  while (readStd(fin, id, score1, score2, score3)) {
    calcGrade(score1, score2, score3, avg, grade);
    writeStd(fout, id, avg, grade);
  }

  cout << "Finish" << endl;

  fin.close();
  fout.close();
  
  return 0;
}
*/