#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  strings(s);
  rep(i, sz(s)) if (!even(i) && s[i] != '0') return false;
  return true;
}
