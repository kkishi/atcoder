#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n);
  strings(s, t);
  rep(i, n) {
    char x = s[i];
    char y = t[i];
    if (x == y) continue;
    if (x == '1' && y == 'l') continue;
    if (y == '1' && x == 'l') continue;
    if (x == '0' && y == 'o') continue;
    if (y == '0' && x == 'o') continue;
    return false;
  }
  return true;
}
