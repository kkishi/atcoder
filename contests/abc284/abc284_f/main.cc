#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"
#include "rolling_hash.h"

void Main() {
  ints(n);
  strings(t);
  RollingHash sl, sr, rs;
  rep(i, n) {
    sr.PushBack(t[n + i]);
    rs.PushBack(t[n - 1 - i]);
  }
  int i = 0;
  while (true) {
    uint64_t s = (__uint128_t(sl.hash()) *
                      Pow(RollingHash::base(), n - i, RollingHash::mod()) +
                  sr.hash()) %
                 RollingHash::mod();
    if (s == rs.hash()) {
      wt(t.substr(0, i) + t.substr(i + n));
      wt(i);
      return;
    }
    if (i == n) break;
    sl.PushBack(t[i]);
    sr.PopFront();
    rs.PopBack();
    rs.PushFront(t[n + i]);
    ++i;
  }
  wt(-1);
}
