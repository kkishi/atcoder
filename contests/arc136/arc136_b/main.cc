#include <bits/stdc++.h>

#include "atcoder.h"

bool Solve(V<int> a, V<int> b, map<int, int>& A, bool take_second) {
  int n = sz(a);
  rep(i, n) {
    if (i == n - 3) {
      bool ok = false;
      rep(3) {
        if (a == b) {
          ok = true;
          break;
        }
        int x = a[i + 0];
        int y = a[i + 1];
        int z = a[i + 2];
        a[i + 0] = z;
        a[i + 1] = x;
        a[i + 2] = y;
      }
      if (ok) return true;
    }
    bool ok = false;
    rep(j, i, n) if (a[j] == b[i]) {
      if (A[b[i]] >= 2 && take_second) {
        take_second = false;
        continue;
      }
      ok = true;
      int k = j;
      while (k >= i + 2) {
        int x = a[k - 2];
        int y = a[k - 1];
        int z = a[k - 0];
        a[k - 2] = z;
        a[k - 1] = x;
        a[k - 0] = y;
        k -= 2;
      }
      if (k > i) {
        if (k + 1 >= n) return false;
        int x = a[k - 1];
        int y = a[k - 0];
        int z = a[k + 1];
        a[k - 1] = y;
        a[k - 0] = z;
        a[k + 1] = x;
      }
      break;
    }
    dbg(a);
    if (!ok) return false;
  }
  assert(a == b);
  return true;
}

void Main() {
  wt([] {
    ints(n);
    V<int> a(n), b(n);
    cin >> a >> b;
    map<int, int> A;
    each(e, a)++ A[e];
    return Solve(a, b, A, false) || Solve(a, b, A, true);
  }());
}
