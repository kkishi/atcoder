#include <bits/stdc++.h>

#include "disjointset.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, n, m);
  vector<ll> a(m), b(m);
  rep(i, m) cin >> a[i] >> b[i];
  vector<ll> ans(m);
  DisjointSet ds(n + 1);
  ll sum = n * (n - 1) / 2;
  rrep(i, m) {
    ans[i] = sum;
    if (!ds.Same(a[i], b[i])) {
      dbg(ds.Size(a[i]), ds.Size(b[i]));
      sum -= ds.Size(a[i]) * ds.Size(b[i]);
      ds.Union(a[i], b[i]);
    }
  }
  rep(i, m) wt(ans[i]);
}
