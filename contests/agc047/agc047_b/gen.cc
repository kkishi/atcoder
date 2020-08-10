#include <iostream>

using namespace std;

int main() {
  int N = 100;
  cout << N << endl;
  for (int i = 1; i <= N / 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      for (int k = 0; k < j; ++k) {
        cout << (char)('a' + (rand() % 3));
      }
      cout << endl;
    }
  }
}
