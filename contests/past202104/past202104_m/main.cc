#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  using T = tuple<int, int, int>;
  set<T> s;
  map<int, int> c;
  rep(i, n) {
    ints(a);
    s.insert({i, i + 1, a});
    ++c[a];
  }
  int ans = 0;
  auto f = [](int x) { return x * (x - 1) / 2; };
  each(_, v, c) ans += f(v);
  ints(q);
  rep(q) {
    ints(l, r, x);
    --l;
    dbg(l, r, x);
    dbg(s);
    auto it = s.lower_bound({l, 0, 0});
    auto b = [](const T& t) { return get<0>(t); };
    auto e = [](const T& t) { return get<1>(t); };
    auto a = [](const T& t) { return get<2>(t); };
    auto len = [&](const T& t) { return e(t) - b(t); };
    dbg(*it);
    if (it == s.end()) --it;
    auto lt = it;
    while (l < b(*lt)) --lt;
    dbg(*lt);
    auto rt = lt;
    while (e(*rt) < r) ++rt;
    dbg(*rt);
    map<int, int> ch;
    V<T> rem, add;
    if (b(*lt) < l) {
      T t = *lt;
      get<1>(t) = l;
      add.pb(t);
    }
    if (r < e(*rt)) {
      T t = *rt;
      get<0>(t) = r;
      add.pb(t);
    }
    add.eb(l, r, x);
    for (it = lt;; ++it) {
      rem.pb(*it);
      if (it == rt) break;
    }
    each(t, rem) {
      s.erase(t);
      int x = c[a(t)];
      int y = x - len(t);
      assert(y >= 0);
      c[a(t)] = y;
      ans -= f(x);
      ans += f(y);
      dbg(a(t), x, y);
    }
    each(t, add) {
      s.insert(t);
      int x = c[a(t)];
      int y = x + len(t);
      c[a(t)] = y;
      ans -= f(x);
      ans += f(y);
      dbg(a(t), x, y);
    }
    wt(ans);
  }
}
