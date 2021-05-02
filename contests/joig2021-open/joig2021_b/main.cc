#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n, k);
  strings(t);
  rep(i, n) if (i + 1 >= k) {
    if (isupper(t[i])) {
      t[i] = tolower(t[i]);
    } else {
      t[i] = toupper(t[i]);
    }
  }
  wt(t);
}
