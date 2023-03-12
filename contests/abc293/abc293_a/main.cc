#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  rep(i, sz(s) / 2) swap(s[i * 2], s[i * 2 + 1]);
  wt(s);
}
