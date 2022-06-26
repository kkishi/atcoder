#include <bits/stdc++.h>

#include "atcoder.h"
#include "rand.h"

void Main() {
  ints(n);
  V<int> a(n), b(n);
  cin >> a >> b;

  map<int, int> h;
  each(e, a) h[e] = 0;
  each(e, b) h[e] = 0;
  Rand r;  // Zobrist Hash
  each(_, k, h) k = r.Int(0, big);

  auto f = [&](const V<int>& v) {
    set<int> seen;
    V<int> s(n + 1);
    rep(i, n) {
      s[i + 1] = s[i];
      if (seen.insert(v[i]).second) s[i + 1] ^= h[v[i]];
    }
    return s;
  };
  V<int> A = f(a), B = f(b);
  ints(q);
  rep(q) {
    ints(x, y);
    wt(A[x] == B[y]);
  }
}
