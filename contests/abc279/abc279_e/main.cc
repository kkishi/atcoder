#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(m);
  cin >> a;
  each(e, a)-- e;

  V<int> one;
  int cur = 0;
  rep(i, m) {
    one.pb(cur);
    if (a[i] == cur) {
      ++cur;
    } else if (a[i] + 1 == cur) {
      --cur;
    }
  }
  V<int> s(m);
  V<int> A(n);
  rep(i, n) A[i] = i;
  rrep(i, m) {
    s[i] = A[one[i]];
    swap(A[a[i]], A[a[i] + 1]);
  }
  each(e, s) wt(e + 1);
}
