#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k);
  int sum = 0;
  VV<int> v(n);
  rep(i, 1, n) {
    v[i].push_back(0);
    sum += i - 1;
    int excess = max(0, sum - k);
    sum -= excess;
    rep(j, excess) v[i].push_back(j + 1);
  }
  if (sum < k) {
    wt(-1);
    return 0;
  }
  int m = 0;
  for (const auto& vi : v) m += sz(vi);
  wt(m);
  rep(i, n) for (int vi : v[i]) wt(i + 1, vi + 1);
}
