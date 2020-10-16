#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(o, e);
  string ans{o + e};
  rep(i, sz(o)) ans[i * 2] = o[i];
  rep(i, sz(e)) ans[i * 2 + 1] = e[i];
  wt(ans);
}
