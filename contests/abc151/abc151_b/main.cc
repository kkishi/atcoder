#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, N, K, M);
  int sum = 0;
  rep(i, N - 1) {
    rd(int, A);
    sum += A;
  }
  int ans = max(0, M * N - sum);
  if (ans > K) ans = -1;
  wt(ans);
}
