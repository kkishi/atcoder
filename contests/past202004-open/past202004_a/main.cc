#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  auto f = [](const string& s) -> int {
    if (s[0] == 'B') return '1' - s[1];
    return s[0] - '0';
  };
  strings(s, t);
  wt(abs(f(s) - f(t)));
}
