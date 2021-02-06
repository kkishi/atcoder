#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  struct S {
    string s, t;
  };
  V<S> v;
  rep(n) {
    strings(s);
    string t(find_if(all(s), [](char c) { return c != '0'; }), s.end());
    v.pb({s, t});
  }
  V<int> idx(n);
  iota(all(idx), 0);
  sort(all(idx), [&](int i, int j) {
    const auto& a = v[i];
    const auto& b = v[j];
    if (sz(a.t) != sz(b.t)) return sz(a.t) < sz(b.t);
    if (a.t != b.t) return a.t < b.t;
    return sz(a.s) > sz(b.s);
  });
  each(i, idx) wt(v[i].s);
}
