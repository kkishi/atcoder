#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  string t = "0000";
  rep(i, 3) t[i + 1] = s[i];
  wt(t);
}
