#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  V<int> v;
  each(e, s) v.eb(e - '0');
  int ans = 0;
  V<int> cnt(1 << 10);
  cnt[0] = 1;
  int bits = 0;
  each(e, v) {
    bits ^= 1 << e;
    ans += cnt[bits];
    ++cnt[bits];
  }
  wt(ans);
}
