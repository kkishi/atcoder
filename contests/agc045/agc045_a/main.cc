#include <bits/stdc++.h>

#include "atcoder.h"

bool Check(int a, V<int> b) {
  const int bits = 60;
  VV<int> m;
  rep(i, bits) {
    V<int> v;
    rep(j, sz(b)) v.pb(hasbit(b[j], i));
    v.pb(hasbit(a, i));
    m.pb(v);
  }
  int n = sz(b) + 1;

  int r = 0;
  rep(i, n - 1) {
    rep(j, r, bits) if (m[j][i]) {
      swap(m[r], m[j]);
      rep(k, bits) if (k != r && m[k][i]) rep(l, n) m[k][l] ^= m[r][l];
      ++r;
      break;
    }
  }

  // dbg(a, b);
  // rep(i, bits) dbg(m[i]);

  rep(i, bits) if (m[i].back()) {
    bool ok = false;
    rep(j, n - 1) if (m[i][j]) ok = true;
    if (!ok) return false;
  }
  return true;
}

int Solve() {
  ints(n);
  V<int> a(n);
  cin >> a;
  strings(s);

  rep(i, n) if (s[i] == '1') {
    V<int> b;
    rep(j, i + 1, n) if (s[j] == '0') b.pb(a[j]);
    if (!Check(a[i], b)) return 1;
  }
  return 0;
}

void Main() {
  ints(t);
  rep(t) wt(Solve());
}
