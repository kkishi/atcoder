#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  rep(i, s.size() - 1) if (s[i] == s[i + 1]) {
    wt("Bad");
    return;
  }
  wt("Good");
}
