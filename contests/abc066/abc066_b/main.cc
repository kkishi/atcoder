#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s);
  auto check = [&s](int l) {
    rep(i, l) if (s[i] != s[i + l]) return false;
    return true;
  };
  rrep(l, sz(s) / 2) if (check(l)) {
    wt(l * 2);
    return 0;
  }
}
