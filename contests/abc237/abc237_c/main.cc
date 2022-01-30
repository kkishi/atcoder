#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  wt([]() {
    strings(s);
    int n = sz(s);
    int i = 0;
    while (i < n && s[i] == 'a') ++i;
    if (i == n) return true;
    int j = n - 1;
    while (j >= 0 && s[j] == 'a') --j;
    bool ok = true;
    int I = i, J = j;
    while (I < J) {
      if (s[I] != s[J]) ok = false;
      ++I, --J;
    }
    return ok && i <= (n - 1 - j);
  }());
}
