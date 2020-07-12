#include <iostream>

using namespace std;

int r() {
  int x = rand() % 1000000001;
  // int x = rand() % 9999;
  return rand() % 2 == 0 ? x : -x;
}

int main() {
  int N = 1000;
  cout << N << " " << N << endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << r() << " ";
    }
    cout << endl;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << r() << " ";
    }
    cout << endl;
  }
}
