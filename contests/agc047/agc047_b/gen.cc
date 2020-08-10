#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int N = 1000;
  cout << N << endl;
  rep(i, N) {
    rep(j, 1000) cout << (char)('a' + (rand() % 26));
    cout << endl;
  }
}
