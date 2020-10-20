#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  int ans = 0;
  for (int i = 0; i < sz(s);) {
    int j = i + 1;
    while (j < sz(s) && s[j] != '+') j += 2;
    bool zero = false;
    for (int k = i; k < j; k += 2) {
      if (s[k] == '0') zero = true;
    }
    if (!zero) ++ans;
    i = j + 1;
  }
  wt(ans);
}
