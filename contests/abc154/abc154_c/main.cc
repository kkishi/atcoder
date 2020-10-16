#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(N);
  V<int> A(N);
  cin >> A;
  wt(sz(set<int>(all(A))) == N ? "YES" : "NO");
}
