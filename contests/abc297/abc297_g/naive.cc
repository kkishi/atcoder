#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, l, r);
  V<int> a(n);
  cin >> a;
  int G = 0;
  rep(i, n) {
    int N = a[i];
    V<int> g(N + 1);
    rep(i, N + 1) {
      set<int> st;
      rep(j, l, r + 1) {
        int k = i - j;
        if (k >= 0) st.insert(g[k]);
      }
      rep(j, N + 1) if (!st.count(j)) {
        g[i] = j;
        break;
      }
    }
    G ^= g[N];
    dbg(g[N], G, g);
  }
  dbg(G);
  if (G == 0) {
    wt("Second");
  } else {
    wt("First");
  }
}
