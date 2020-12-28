#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  VV<int> hostile(n);
  rep(m) {
    ints(a, b);
    hostile[a - 1].push_back(b - 1);
  }
  strings(s);
  auto hostile_to = [&](const V<bool>& v) {
    V<bool> ret(n);
    rep(i, n) for (int h : hostile[i]) if (v[h]) ret[i] = true;
    return ret;
  };
  auto not_hostile_to = [&](const V<bool>& v) {
    int cnt = 0;
    rep(i, n) if (v[i])++ cnt;
    V<bool> ret(n);
    rep(i, n) {
      int cnt2 = 0;
      for (int h : hostile[i])
        if (v[h]) ++cnt2;
      if (cnt2 < cnt) ret[i] = true;
    }
    return ret;
  };
  V<bool> g = Fix([&](auto rec, int begin, int end) -> V<bool> {
    if (s[begin] == '"') {
      if (s[end - 1] == '"') {
        return not_hostile_to(rec(begin + 1, end - 1));
      } else {
        assert(s[end - 1] == 'w');
        assert(s[end - 2] == 'w');
        assert(s[end - 3] == '"');
        return hostile_to(rec(begin + 1, end - 3));
      }
    } else {
      assert(s[begin] == 'g');
      bool h = false;
      if (s[end - 1] == 'w') {
        h = true;
        --end;
      }
      int i = stoi(s.substr(begin + 5, end - (begin - 5)));
      V<bool> g(n);
      g[i - 1] = true;
      if (h) {
        return hostile_to(g);
      } else {
        return not_hostile_to(g);
      }
    }
  })(0, sz(s));

  int ans = 0;
  rep(i, n) if (g[i])++ ans;
  wt(ans);
}
