#include <bits/stdc++.h>

#include "atcoder.h"

int N;
int A[100000];
int kMax = 1000000000000000000;

void Main() {
  cin >> N;
  rep(i, N) {
    cin >> A[i];
    if (A[i] == 0) {
      cout << "0" << endl;
      return;
    }
  }
  int ans = 1;
  rep(i, N) {
    if (A[i] > kMax / ans) {
      cout << -1 << endl;
      return;
    }
    ans *= A[i];
  }
  cout << ans << endl;
}
