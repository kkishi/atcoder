#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  V<string> s(n);
  cin >> s;
  using P = pair<int, int>;
  set<V<P>> seen;
  rep(i, n) rep(j, n) {
    if (s[i][j] == '.') {
      V<P> v = {{i, j}};
      seen.insert(v);
    }
  }
  rep(i, k - 1) {
    set<V<P>> nseen;
    each(v, seen) {
      each(r, c, v) {
        each(nr, nc, adjacent(r, c)) if (inside(nr, nc, n, n)) {
          if (s[nr][nc] == '#') continue;
          P p = {nr, nc};
          bool ok = true;
          each(q, v) if (q == p) ok = false;
          if (!ok) continue;
          V<P> nv = v;
          nv.pb(p);
          sort(all(nv));
          nseen.insert(nv);
        }
      }
    }
    swap(nseen, seen);
  }
  wt(sz(seen));
}
