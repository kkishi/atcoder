#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, s.size()) s[i] = (s[i] - 'A' + n) % 26 + 'A';
  wt(s);
}
