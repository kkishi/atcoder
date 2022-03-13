#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  ints(n, k);
  vector<int> a(n), f(n);
  cin >> a >> f;
  sort(a);
  sort(all(f), greater());
  auto check = [&](int x) {
    int training = 0;
    rep(i, n) {
      if (a[i] * f[i] > x) {
        training += a[i] - x / f[i];
      }
    }
    return training > k;
  };
  int x = BinarySearch<int>(0, 1e12L + 1, check);
  if (!check(x)) {
    wt(x);
  } else {
    wt(x + 1);
  }
}
