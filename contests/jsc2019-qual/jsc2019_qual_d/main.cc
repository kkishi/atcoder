#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector a(n, vector(n, -1));
  Fix([&](auto rec, int depth, int begin, int end) {
    int n = end - begin;
    if (n == 1) return;
    int mid = (begin + end) / 2;
    rep(i, begin, mid) rep(j, mid, end) a[i][j] = a[j][i] = depth;
    rec(depth + 1, begin, mid);
    rec(depth + 1, mid, end);
  })(0, 0, n);
  rep(i, n - 1) {
    rep(j, i + 1, n) {
      if (j > i + 1) cout << " ";
      cout << (a[i][j] + 1);
    }
    cout << endl;
  }
}
