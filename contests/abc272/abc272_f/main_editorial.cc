#include <bits/stdc++.h>

#include <atcoder/string>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s, t);

  string u = s + s + string(n, 'a') + t + t + string(n, 'z');

  int ans = 0;
  int cnt_t = n;
  each(e, atcoder::suffix_array(u)) {
    if (e < n) ans += cnt_t;
    if (3 * n <= e && e < 4 * n) --cnt_t;
  }
  wt(ans);
}
