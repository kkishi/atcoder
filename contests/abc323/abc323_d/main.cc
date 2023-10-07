#include <bits/stdc++.h>

#include "atcoder.h"
#include "factors.h"

void Main() {
  ints(n);
  map<int, map<int, int>> mp;
  rep(n) {
    ints(s, c);
    int two = 0;
    while (s % 2 == 0) {
      ++two;
      s /= 2;
    }
    mp[s][two] += c;
  }
  int ans = 0;
  each(_, mp, mp) {
    int x = 0;
    rep(i, 100) {
      x += mp[i];
      ans += x % 2;
      x /= 2;
    }
  }
  wt(ans);
}
