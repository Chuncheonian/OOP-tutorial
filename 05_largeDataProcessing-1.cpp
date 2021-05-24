/**
 * @file    05_largeDataProcessing-1.cpp
 * @author  Dongyoung Kwon (ehddud2468@gmail.com)
 * @brief   string, file stream
 * @date    2020-04-07
 */
#include <iostream>
#include <fstream>  // ofstream, ifstream Class 사용
#include <string>
using namespace std;

// 1. string
int main() {
  // string: string class or string object
  // s: Object or Instance
  string s = "fred";  // string class로부터 s라는 instance(객체) 생성
  cout << "s: " << s << endl;
  cout << s.size() << endl << endl; // s라는 객체는 size() method를 가지고 있다. [s.length() == s.size()]

  cout << "s: " << s << endl;
  cout << s.empty() << endl;  // 문자열이 차 있으면 false
  s.clear();  // s= "";
  cout << "s: " << s << endl;
  cout << s.empty() << endl << endl;  // 문자열이 비어 있으면 true

  s = "Good";
  s += "-bye";
  cout << "s: " << s << endl;
  cout << s[4] << ", " << s.at(4) << endl << endl;  // s[i]가 구동속도가 빠름, s.at은 at함수를 꺼내써야되서 느림, 그러나 안전상 s.at를 주로 씀

  cout << s.substr(5, 2) << endl; // (시작 index, 추출할 문자열의 길이)
  cout << s.substr(5, 3) << endl << endl;

  cout << s.find("od") << endl;
  cout << s.find("od", 5) << ", " << string::npos << endl;  // 5자리수부터 찾기 시작
  // 찾는 문자열이 없는 경우 string::npos를 반환한다.
  // if (s.find("od", 5) == string::npos) { "od가 없는 경우..."}

  s += "-od";
  // Good-bye-od
  string key = "od";
  cout << "s: " << s << endl;
  int idx = s.find(key);
  cout << idx << endl;
  cout << s.find("od", idx+key.size()) << endl;
  cout << (s == "Good-bye-od") << endl;

  return 0;
}

/*
// 2. file stream - getline()
int main() {
  ofstream fout;  // fout은 ofstream의 인스턴스이다. 다른 이름으로 해도 된다. e.g. ofstream tmp;
  fout.open("example.txt");  // 덮어쓰기
  // fout.open("example.txt", ios::app);  // 이어쓰기

  string s = "Object Oriented Programming";

  fout << s << endl;
  fout << "Linear Algebra" << endl;
  fout << "Random Process" << endl;
  fout.close();

  ifstream fin;
  fin.open("example.txt");

  if (!fin) {  // fin: 파일을 제대로 열지 못했거나 EOF를 읽으면 false
    cout << "File Open Error" << endl;
    exit(100);  // 강제 프로그램 종료
  }
  
  // getline(ifstream instance, string instance): 한줄씩 읽는다.
  // 한줄: 줄바꿈 문자로 문자열을 구분
  while (getline(fin, s)) {
    cout << s << endl;
  }
  fin.close();

  return 0;
}
*/

// "한 문자"(문자열 x)를 쓰기:  fout.put()
// "한 문자"(문자열 x)를 읽기: fin.get()

//                        |   ifstream    |   ofstream
// ----------------------| ------------- | ------------
//        char          |   fin.get(ch) |  fout.put(ch)
//  word(공백, 줄바꿈) |   fin >> s    |  fout << s
//    line(줄바꿈)    | getline(fin,s)|  fout << s

// 중요 1) fout/fin 사용시 반드시 시작 open(), 끝 close()
//     2) ifstream fin에서, 파일 open 실패, EOF까지 읽으면, fin == false (!fin == true)

/*
// 3. file stream - get(), put()
int main() {
  char ch;
  ofstream fout("char.txt");  // fout.open() 생략
  while (true) {
    cin >> ch;
    if (ch == 'q')
      break;
    fout.put(ch);  // 문자를 파일에 쓰기
  }
  fout.close();

  ifstream fin("char.txt");
  cout << endl << endl;
  
  while (true) {
    fin.get(ch);
    if (!fin)
      break;
    cout << ch << endl;
  }
  fin.close();

  return 0;
}
*/