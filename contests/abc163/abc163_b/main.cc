#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N, M);
  V<int> A(M);
  cin >> A;
  int sum = accumulate(all(A), 0);
  wt(sum > N ? -1 : (N - sum));
}
