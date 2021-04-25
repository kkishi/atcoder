#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  bool ok = true;
  if (s[3] != '-') ok = false;
  rep(i, 8) if (i != 3 && !isdigit(s[i])) ok = false;
  wt(ok);
}
