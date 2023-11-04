#include <bits/stdc++.h>

#include "atcoder_yn.h"

bool Main() {
  ints(n);
  strings(s);
  rep(i, n - 1) {
    if (set{s[i], s[i + 1]} == set{'a', 'b'}) return true;
  }
  return false;
}
