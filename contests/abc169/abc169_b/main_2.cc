#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int N;
ll A[100000];
ll kMax = 1000000000000000000;

int main() {
  cin >> N;
  rep(i, N) cin >> A[i];
  if (find(A, A + N, 0) != A + N) {
    cout << "0" << endl;
    return 0;
  }
  ll ans = 1;
  rep(i, N) {
    if (__builtin_mul_overflow(ans, A[i], &ans) || ans > kMax) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}
