#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m, k);
  VV<int> g(n);
  V<int> in(n);
  rep(m) {
    ints(a, b);
    --a, --b;
    g[a].pb(b);
    ++in[b];
  }
  deque<int> que;
  rep(i, n) if (in[i] == 0) que.push_back(i);
  V<int> p;
  VV<int> ans;
  bool ok = true;
  Fix([&](auto rec) {
    if (sz(p) == n) {
      ans.pb(p);
      return;
    }
    int n = sz(que);
    if (n == 0) {
      ok = false;
    }
    rep(i, n) {
      swap(que[0], que[i]);
      int pi = que.front();
      que.pop_front();
      p.pb(pi + 1);
      each(c, g[pi]) {
        --in[c];
        if (in[c] == 0) {
          que.push_back(c);
        }
      }
      rec();
      if (sz(ans) == k) return;
      if (!ok) return;
      each(c, g[pi]) {
        if (in[c] == 0) {
          que.pop_back();
        }
        ++in[c];
      }
      p.pop_back();
      que.push_front(pi);
      swap(que[0], que[i]);
    }
  })();
  if (sz(ans) == k) {
    each(e, ans) wt(e);
  } else {
    wt(-1);
  }
}
