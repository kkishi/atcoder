#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, x, y, z);
  V<int> a(n), b(n);
  cin >> a >> b;
  V<int> idx;
  rep(i, n) idx.eb(i);
  V<bool> ok(n);

  sort(all(idx), [&](int i, int j) {
    if (a[i] != a[j]) return a[i] > a[j];
    return i < j;
  });
  each(i, idx) if (x > 0 && !ok[i]) {
    --x;
    ok[i] = true;
  }

  sort(all(idx), [&](int i, int j) {
    if (b[i] != b[j]) return b[i] > b[j];
    return i < j;
  });
  each(i, idx) if (y > 0 && !ok[i]) {
    --y;
    ok[i] = true;
  }

  sort(all(idx), [&](int i, int j) {
    int ci = a[i] + b[i];
    int cj = a[j] + b[j];
    if (ci != cj) return ci > cj;
    return i < j;
  });
  each(i, idx) if (z > 0 && !ok[i]) {
    --z;
    ok[i] = true;
  }

  rep(i, n) if (ok[i]) wt(i + 1);
}
