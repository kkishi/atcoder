#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  s += "____";
  int ans = 0;
  rep(i, 12) if (s.substr(i, 4) == "ZONe")++ ans;
  wt(ans);
}
