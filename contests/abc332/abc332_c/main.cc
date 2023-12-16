#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, m);
  strings(s);
  s += '0';
  int ans = 0;
  int used_n = 0;
  int used_l = 0;
  each(e, s) {
    if (e == '0') {
      chmax(ans, used_l);
      used_n = 0;
      used_l = 0;
    } else if (e == '1') {
      if (used_n < m) {
        ++used_n;
      } else {
        ++used_l;
      }
    } else {
      ++used_l;
    }
  }
  wt(ans);
}
