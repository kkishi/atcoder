#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<int> r;
  r.pb(1);
  int N = 12;
  rep(N - 1) r.push_back(r.back() * 10 + 1);
  set<int> st;
  rep(i, N) rep(j, N) rep(k, N) st.insert(r[i] + r[j] + r[k]);
  ints(n);
  wt(*next(st.begin(), n - 1));
}
