#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() -> bool {
    strings(s);
    auto alpha = [](char c) { return 'A' <= c && c <= 'Z'; };
    auto digit = [](char c) { return '0' <= c && c <= '9'; };
    if (sz(s) != 8) return false;
    if (!alpha(s[0])) return false;
    if (!alpha(s[7])) return false;
    if (s[1] == '0') return false;
    rep(i, 6) if (!digit(s[i + 1])) return false;
    return true;
  }());
}
