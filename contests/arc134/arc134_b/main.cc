#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  int l = 0, r = n - 1;
  char c = 'a';
  while (l < r) {
    if (s[l] == c) {
      ++l;
      continue;
    }
    assert(s[l] > c);
    while (c < s[l]) {
      int k = r;
      while (k > l) {
        if (s[k] == c) {
          swap(s[l], s[k]);
          ++l;
          r = k - 1;
          goto next;
        }
        --k;
      }
      ++c;
    }
    ++l;
  next:
    continue;
  }
  wt(s);
}
