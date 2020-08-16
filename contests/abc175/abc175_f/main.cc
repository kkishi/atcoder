#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  rd(int, n);
  V<string> s(n);
  V<int> c(n);
  rep(i, n) cin >> s[i] >> c[i];
  using P = pair<string, string>;
  low_priority_queue<pair<int, P>> q;
  q.push({0, {"", ""}});
  map<P, int> seen;
  auto empty = [](const P& p) { return p == P{}; };
  while (!q.empty()) {
    auto [cost, h] = q.top();
    q.pop();
    if (cost != 0 && empty(h)) {
      wt(cost);
      return 0;
    }
    rep(i, n) {
      P t(h);
      auto prefixMatch = [](const string& a, const string& b) {
        rep(i, min(a.size(), b.size())) if (a[i] != b[i]) return false;
        return true;
      };
      if (empty(t)) {
        t.first = s[i];
      } else if (t.first.empty()) {
        if (!prefixMatch(t.second, s[i])) continue;
        t.first = s[i];
      } else {
        assert(t.second.empty());
        string rs = s[i];
        reverse(all(rs));
        if (!prefixMatch(t.first, rs)) continue;
        t.second = rs;
      }
      int pl = min(t.first.size(), t.second.size());
      t.first = t.first.substr(pl);
      t.second = t.second.substr(pl);
      auto palin = [](const string& s) {
        rep(i, s.size() / 2) if (s[i] != s[s.size() - 1 - i]) return false;
        return true;
      };
      if (palin(t.first)) t.first = "";
      if (palin(t.second)) t.second = "";
      int nc = cost + c[i];
      auto [it, ok] = seen.insert({t, nc});
      if (!empty(t) && !ok && it->second <= nc) continue;
      it->second = nc;
      q.push({nc, t});
    }
  }
  wt(-1);
#undef int
}
