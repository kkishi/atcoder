#include <bits/stdc++.h>

#include "modint.h"

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  mint minimum = 0;
  mint maximum = 0;
  rep(i, K) {
    minimum += i;
    maximum += N - i;
  }

  mint ans = 0;
  for (int i = K; i <= N + 1; ++i) {
    ans += maximum - minimum + 1;
    minimum += i;
    maximum += N - i;
  }
  cout << ans << endl;
}
