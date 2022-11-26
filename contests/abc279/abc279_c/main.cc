#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(h, w);
  V<string> s(h), t(h);
  cin >> s >> t;
  V<string> S(w, string(h, ' ')), T(w, string(h, ' '));
  rep(i, h) rep(j, w) {
    S[j][i] = s[i][j];
    T[j][i] = t[i][j];
  }
  sort(S);
  sort(T);
  wt(S == T);
}
