#include <bits/stdc++.h>

#include "atcoder.h"

int numSets(int n) {
  for (int i = 1;; ++i) {
    int j = i * (i - 1) / 2;
    if (j == n) return i;
    if (j > n) return 0;
  }
}

void Main() {
  ints(n);
  int ns = numSets(n);
  if (ns == 0) {
    wt("No");
    return;
  }
  wt("Yes");
  wt(ns);
  VV<int> s(ns);
  int x = 0;
  rep(i, ns - 1) rep(j, i + 1, ns) {
    ++x;
    s[i].push_back(x);
    s[j].push_back(x);
  }
  rep(i, ns) {
    cout << sz(s[i]);
    rep(j, sz(s[i])) cout << " " << s[i][j];
    cout << endl;
  }
}
