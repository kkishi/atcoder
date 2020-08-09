#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

struct N {
  int two, five;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rd(ll, n);
  map<pair<ll, ll>, ll> m;
  // vector<pair<string, pair<ll, ll>>> v;
  rep(i, n) {
    rd(string, s);
    string l = s;
    ll two = 0, five = 0;
    rep(j, s.size()) if (s[j] == '.') {
      l = s.substr(0, j);
      string r = s.substr(j + 1);
      if (r.back() == '0') {
        int k = r.size() - 1;
      }
      while (r.back() == '0') r = r.substr(0, r.size() - 1);
      l += r;
      two -= r.size();
      five -= r.size();
    }
    // dbg(l);
    {
      stringstream ss;
      ss << l;
      ll x;
      ss >> x;
      // map<ll, int> fs = Factorize(x);
      while (x % 2 == 0) {
        ++two;
        x /= 2;
      }
      while (x % 5 == 0) {
        ++five;
        x /= 5;
      }
      // five += fs[5];
    }
    // a[i] = {two, five};
    ++m[{two, five}];
    // dbg(s, two, five);
    // v.push_back({s, {two, five}});
  }
  /*
  rep(i, v.size()) rep(j, i) {
    auto [a, b] = v[i].second;
    auto [c, d] = v[j].second;
    if (a + c >= 0 && b + d >= 0) {
      dbg("ok");
      // dbg(v[i].first, v[j].second);
    }
  }
  */
  dbg(m.size());
  ll ans = 0;
  for (auto [a, b] : m) {
    for (auto [c, d] : m) {
      auto [e, f] = a;
      auto [g, h] = c;
      if (e + g >= 0 && f + h >= 0) {
        dbg(e, f, ".", g, h, "|", b, d);
        if (a == c) {
          ans += b * (b - 1) / 2;
        } else {
          ans += b * d;
        }
      }
      if (a == c) break;
    }
  }
  wt(ans);
}
