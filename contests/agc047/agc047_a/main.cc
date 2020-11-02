#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  map<pair<int, int>, int> m;
  rep(i, n) {
    strings(s);
    string l = s;
    int two = 0, five = 0;
    rep(j, s.size()) if (s[j] == '.') {
      string r = s.substr(j + 1);
      l = s.substr(0, j) += r;
      two -= r.size();
      five -= r.size();
    }
    {
      int x = atoll(l.c_str());
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
  int ans = 0;
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
