#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  strings(s);
  V<string> v;
  VV<char> sep(k + 1);
  bool ok = Fix([&](auto rec, int l, int r, bool rev, int depth) {
    int len = r - l;
    if (depth == k) {
      if (len == 1) return false;
      string t = s.substr(l, r - l);
      if (rev) reverse(all(t));
      v.eb(t);
      return true;
    }
    if (len == 0) return false;
    if (even(len)) {
      int m = l + len / 2;
      if (!rec(l, m, false, depth + 1)) return false;
      if (!rec(m, r, true, depth + 1)) return false;
      return true;
    } else {
      int m = l + len / 2;
      if (!rec(l, m, false, depth + 1)) return false;
      if (!rec(m + 1, r, true, depth + 1)) return false;
      sep[depth].pb(s[m]);
      return true;
    }
  })(0, sz(s), false, 0);
  if (!ok) {
    wt("impossible");
    return;
  }
  int ans = 0;
  dbg(sep);
  dbg(v);
  each(e, sep) {
    if (e.empty()) continue;
    map<char, int> m;
    each(c, e)++ m[c];
    int maxi = -big;
    each(_, v, m) chmax(maxi, v);
    ans += sz(e) - maxi;
  }
  dbg(ans);
  V<int> second;
  string t;
  rep(i, sz(v[0])) {
    map<char, int> m;
    each(e, v) {
      assert(sz(e) == sz(v[0]));
      ++m[e[i]];
    }
    V<pair<int, char>> w;
    each(k, v, m) w.eb(v, k);
    sort(all(w), greater{});
    int best = sz(v) - w[0].first;
    t += w[0].second;
    ans += best;
    if (sz(w) > 1) {
      int second_best = sz(v) - w[1].first;
      assert(second_best >= best);
      second.pb(second_best - best);
    } else {
      second.pb(sz(v));
    }
  }
  string rt = t;
  reverse(all(rt));
  if (!t.empty() && rt == t) {
    int mini = big;
    rep(i, sz(second)) {
      if (!even(sz(t)) && i == sz(t) / 2) continue;
      chmin(mini, second[i]);
    }
    ans += mini;
  }
  wt(ans);
}
