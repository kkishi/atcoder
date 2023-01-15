#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "topological_sort.h"

void Main() {
  ints(n);
  V<string> s(n), t(n);
  rep(i, n) cin >> s[i] >> t[i];
  set<string> st;
  each(e, s) st.insert(e);
  each(e, t) st.insert(e);
  V<string> v(all(st));
  map<string, int> mp;
  rep(i, sz(v)) mp[v[i]] = i;
  int N = sz(mp);
  Graph g(N);
  rep(i, n) g[mp[s[i]]].eb(mp[t[i]]);
  wt(TopologicalSort(g).second);
}
