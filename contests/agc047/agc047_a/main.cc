#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  rd(int, n);
  map<pair<ll, ll>, ll> m;
  rep(i, n) {
    rd(string, s);
    string l = s;
    ll two = 0, five = 0;
    rep(j, s.size()) if (s[j] == '.') {
      string r = s.substr(j + 1);
      l = s.substr(0, j) += r;
      two -= r.size();
      five -= r.size();
    }
    {
      ll x = atoll(l.c_str());
      while (x % 2 == 0) {
        ++two;
        x /= 2;
      }
      while (x % 5 == 0) {
        ++five;
        x /= 5;
      }
    }
    ++m[{two, five}];
  }
  ll ans = 0;
  for (auto [a, b] : m) {
    for (auto [c, d] : m) {
      auto [e, f] = a;
      auto [g, h] = c;
      if (e + g >= 0 && f + h >= 0) {
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
