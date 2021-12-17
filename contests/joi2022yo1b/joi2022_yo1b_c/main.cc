#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  rep(i, n - 1) {
    if (s[i + 1] == 'J') wt(s[i]);
  }
}
