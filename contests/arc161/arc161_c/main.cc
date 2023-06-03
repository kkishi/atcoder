// NOTE: This solution is WA.
#include <bits/stdc++.h>

#include "atcoder.h"
#include "graph.h"
#include "rand.h"

pair<bool, string> Solve(const Graph& g, const string& s, int root) {
  int n = sz(g);
  string ps(n, '?');
  bool ok = true;
  Fix([&](auto rec, int node, int parent) -> void {
    int cnt = 0;
    each(child, g[node]) if (child != parent) {
      rec(child, node);
      ++cnt;
    }
    if (cnt == 0) {
      if (parent != -1) {
        if (ps[parent] == '?') {
          ps[parent] = s[node];
        } else {
          if (ps[parent] != s[node]) {
            ok = false;
          }
        }
      }
    }
  })(root, -1);
  dbg(ok, ps);
  if (!ok) return {false, ""};
  Fix([&](auto rec, int node, int parent) -> void {
    each(child, g[node]) if (child != parent) {
      if (ps[child] == '?') ps[child] = s[node];
      rec(child, node);
    }
  })(root, -1);
  dbg(ps);

  auto check = [&](const string& ps) -> bool {
    rep(i, n) {
      int d = 0;
      each(e, g[i]) d += (ps[e] == 'B' ? -1 : +1);
      if (((d < 0) ? 'B' : 'W') != s[i]) return false;
    }
    return true;
  };
  if (ps[root] == '?') {
    ps[root] = 'B';
    if (check(ps)) return {true, ps};
    ps[root] = 'W';
    if (check(ps)) return {true, ps};
  } else {
    if (check(ps)) return {true, ps};
  }
  return {false, ""};
}

void Main() {
  ints(t);
  Rand r;
  rep(t) {
    ints(n);
    Graph g(n);
    g.Read();
    strings(s);
    rep(i, 60) {
      int root = r.Int(0, n - 1);
      auto [res, ans] = Solve(g, s, root);
      if (res) {
        dbg(root);
        wt(ans);
        goto next;
      }
    }
    wt(-1);
  next:
    continue;
  }
}
