#include <bits/stdc++.h>

#include "disjointset.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n, m);
  V<int> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  int ans = 0;
  rep(i, m) {
    DisjointSet ds(n);
    rep(j, m) if (j != i) ds.Union(a[j] - 1, b[j] - 1);
    if (ds.Size(0) < n) ++ans;
  }
  wt(ans);
}
