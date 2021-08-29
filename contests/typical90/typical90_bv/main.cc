#include <bits/stdc++.h>

#include "atcoder.h"
#include "pow.h"

void Main() {
  ints(n);
  strings(s);
  int ans = 0;
  rep(i, n) ans += Pow(2, i) * (s[i] - 'a');
  wt(ans);
}
