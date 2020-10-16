#include <bits/stdc++.h>

#include "atcoder.h"

int N;
int A[100000];
int kMax = 1000000000000000000;

void Main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  if (find(A, A + N, 0) != A + N) {
    cout << "0" << endl;
    return;
  }
  int ans = 1;
  rep(i, N) {
    if (__builtin_mul_overflow(ans, A[i], &ans) || ans > kMax) {
      cout << -1 << endl;
      return;
    }
  }
  cout << ans << endl;
}
