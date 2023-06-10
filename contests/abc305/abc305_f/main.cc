#include <bits/stdc++.h>

#include "atcoder_interactive.h"

void Main() {
  ints(n, m);
  V<bool> seen(n);
  Fix([&](auto rec, int node, int parent) -> void {
    seen[node] = true;
    dbg(node, seen);
    ints(k);
    if (k == -1) {
      exit(0);
    }
    V<int> v(k);
    cin >> v;
    each(e, v)-- e;
    sort(v);
    dbg(v);
    each(c, v) {
      if (c == parent) continue;
      if (seen[c]) continue;
      wt_flush(c + 1);
      dbg("enter", c, "from", node);
      if (c == n - 1) {
        strings(res);
        assert(res == "OK");
        exit(0);
      }
      rec(c, node);
      dbg("exit", c, "to", node);
      wt_flush(node + 1);
      ints(k);
      V<int> v(k);
      cin >> v;
    }
  })(0, -1);
}
