#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  set<char> ss(all(s));
  wt(sz(s) == sz(ss) ? "yes" : "no");
}
