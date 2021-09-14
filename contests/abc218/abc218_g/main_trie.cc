#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_trie.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  VV<int> g(n);
  rep(n - 1) {
    ints(u, v);
    --u, --v;
    g[u].pb(v);
    g[v].pb(u);
  }
  BinaryTrie t;
  wt(Fix([&](auto rec, int node, int parent, int depth) -> int {
    t.Insert(a[node]);
    int ret = even(depth) ? -big : big;
    bool leaf = true;
    each(child, g[node]) {
      if (child == parent) continue;
      leaf = false;
      int r = rec(child, node, depth + 1);
      if (even(depth)) {
        chmax(ret, r);
      } else {
        chmin(ret, r);
      }
    }
    if (leaf) {
      int m = (t.Size() - 1) / 2;
      if (even(t.Size())) {
        ret = (t.FindByOrder(m) + t.FindByOrder(m + 1)) / 2;
      } else {
        ret = t.FindByOrder(m);
      }
    }
    t.Erase(a[node]);
    return ret;
  })(0, -1, 0));
}
