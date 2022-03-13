#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(k);
  string ans;
  while (k) {
    ans += (char)((k & 1) ? '2' : '0');
    k /= 2;
  }
  reverse(ans);
  wt(ans);
}
