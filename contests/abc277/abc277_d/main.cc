#include <bits/stdc++.h>

#include "atcoder.h"
#include "compressor.h"
#include "disjoint_set.h"

void Main() {
  ints(n, m);
  V<int> a(n);
  cin >> a;
  map<int, int> mp;
  each(e, a)++ mp[e];
  V<pair<int, int>> A;
  each(a, b, mp) A.eb(a, b);
  int N = sz(A);
  DisjointSet ds(N);
  rep(i, N) {
    int j = (i + 1) % N;
    int I = A[i].first;
    int J = A[j].first;
    if ((I + 1) % m == J) {
      ds.Union(i, j);
    }
  }
  map<int, int> sum;
  rep(i, N) sum[ds.Find(i)] += A[i].first * A[i].second;
  int tot = 0;
  int ma = 0;
  each(_, e, sum) {
    tot += e;
    chmax(ma, e);
  }
  wt(tot - ma);
}
