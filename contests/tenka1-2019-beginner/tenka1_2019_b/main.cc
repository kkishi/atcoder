#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  ints(k);
  rep(i, n) if (s[i] != s[k - 1]) s[i] = '*';
  wt(s);
}
