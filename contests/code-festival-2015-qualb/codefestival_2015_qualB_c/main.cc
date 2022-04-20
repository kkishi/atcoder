#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([] {
    ints(n, m);
    if (m > n) return false;
    V<int> a(n), b(m);
    cin >> a >> b;
    sort(a, greater{});
    sort(b, greater{});
    rep(i, m) if (a[i] < b[i]) return false;
    return true;
  }()
         ? "YES"
         : "NO");
}
