#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  s[0] = toupper(s[0]);
  rep(i, 1, sz(s)) s[i] = tolower(s[i]);
  wt(s);
}
