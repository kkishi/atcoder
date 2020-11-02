#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  set<char> ss(all(s));
  rep(i, 26) if (char c = 'a' + i; !ss.count(c)) {
    wt(c);
    return;
  }
  wt("None");
}
