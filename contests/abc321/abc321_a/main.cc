#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  strings(n);
  rep(i, sz(n) - 1) if (n[i] <= n[i + 1]) return false;
  return true;
}
