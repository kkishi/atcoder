#include <bits/stdc++.h>

#include "disjointset.h"
#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  V<int> p(n);
  rep(i, n) cin >> p[i];
  DisjointSet ds(n);
  rep(i, m) {
    rd(int, x, y);
    ds.Union(x - 1, y - 1);
  }
  int ans = 0;
  rep(i, n) if (ds.Same(i, p[i] - 1))++ ans;
  wt(ans);
}
