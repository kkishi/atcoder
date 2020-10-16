#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  int ans = 0;
  Fix([&](auto rec, string s, bool three, bool five, bool seven) {
    if (s.size() >= 10) return;
    if (three && five && seven && stoll(s) <= n) ++ans;
    rec(s + '3', true, five, seven);
    rec(s + '5', three, true, seven);
    rec(s + '7', three, five, true);
  })("", false, false, false);
  wt(ans);
}
