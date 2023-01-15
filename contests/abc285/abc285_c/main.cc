#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  strings(s);
  int ans = 0;
  rep(i, 1, sz(s)) ans += Pow(26, i);
  int x = 0;
  each(e, s) {
    x *= 26;
    x += e - 'A';
  }
  wt(ans + x + 1);
}
