#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int ans = 0;
  rep(i, n + 1) {
    set<char> a, b;
    rep(j, n)(j < i ? a : b).insert(s[j]);
    int cnt = 0;
    for (char c : a)
      if (b.count(c)) ++cnt;
    chmax(ans, cnt);
  }
  wt(ans);
}
