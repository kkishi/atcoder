#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  int n;
  scanf("%ld", &n);
  V<int> s(n), e(n);
  rep(i, n) scanf("%ld-%ld", &s[i], &e[i]);

  V<pair<int, int>> se(n);
  rep(i, n) se[i] = {s[i], e[i]};
  sort(se);
  rep(i, n) tie(s[i], e[i]) = se[i];

  V<int> sh(n), sm(n), eh(n), em(n);
  rep(i, n) {
    sh[i] = s[i] / 100;
    sm[i] = s[i] % 100;
    sm[i] -= sm[i] % 5;
    eh[i] = e[i] / 100;
    em[i] = e[i] % 100;
    if (int r = em[i] % 5; r) {
      em[i] += 5 - r;
      if (em[i] == 60) {
        ++eh[i];
        em[i] = 0;
      }
    }
  }

  int i = 0;
  while (i < n) {
    int j = i + 1;
    int h = eh[i], m = em[i];
    auto f = [](int h, int m) { return h * 60 + m; };
    while (j < n && f(h, m) >= f(sh[j], sm[j])) {
      if (f(eh[j], em[j]) > f(h, m)) h = eh[j], m = em[j];
      ++j;
    }
    printf("%02ld%02ld-%02ld%02ld\n", sh[i], sm[i], h, m);
    i = j;
  }
}
