#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(H, N);
  V<int> A(N);
  cin >> A;
  wt(accumulate(all(A), 0) >= H);
}
