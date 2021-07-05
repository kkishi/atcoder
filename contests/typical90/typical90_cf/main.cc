#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int i = 0;
  int ans = n * (n - 1) / 2;
  while (i < n) {
    int j = i;
    while (j < n && s[j] == s[i]) ++j;
    int x = j - i;
    ans -= x * (x - 1) / 2;
    i = j;
  }
  wt(ans);
}
