#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  V<int> A(N);
  cin >> A;

  bool ok = true;
  rep(i, N) if (A[i] % 2 == 0 && (A[i] % 3 != 0 && A[i] % 5 != 0)) ok = false;
  wt(ok ? "APPROVED" : "DENIED");
}
