#include <iostream>

using namespace std;

int main() {
  int N = 200000;
  cout << N << endl;
  for (int i = 1; i <= N; ++i) {
    cout << (10000 - i) << "." << (10000000000 - i) << endl;
  }
}
