#include <iostream>

using namespace std;

int main() {
  int N = 1000;
  cout << N << " " << N << endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << 1 << " " << 2 << " " << i - 500 << endl;
    }
    cout << endl;
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << i - 500 << " " << 1 << " " << 2 << endl;
    }
    cout << endl;
  }
}
