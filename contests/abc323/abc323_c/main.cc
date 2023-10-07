#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  V<int> a(m);
  cin >> a;
  V<string> s(n);
  cin >> s;
  V<int> base(n);
  rep(i, n) rep(j, m) if (s[i][j] == 'o') base[i] += a[j];
  rep(i, n) base[i] += i + 1;
  multiset<int> st(all(base));
  V<int> ans(n);
  rep(i, n) {
    st.erase(st.find(base[i]));
    V<int> v;
    rep(j, m) if (s[i][j] == 'x') v.eb(a[j]);
    sort(v);
    v.eb(0);
    int sum = 0;
    rrep(j, sz(v)) {
      sum += v[j];
      if (base[i] + sum > *prev(st.end())) {
        ans[i] = sz(v) - 1 - j;
        break;
      }
    }
    st.insert(base[i]);
    assert(sz(st) == n);
  }
  each(e, ans) wt(e);
}
