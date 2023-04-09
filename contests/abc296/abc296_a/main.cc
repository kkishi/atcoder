#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n);
  strings(s);
  rep(i, n - 1) if (s[i] == s[i + 1]) return false;
  return true;
}
