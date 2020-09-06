#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  strings(s);
  VV<bool> l(n, V<bool>(10)), r{l};
  rep(i, n) {
    if (i - 1 >= 0) l[i] = l[i - 1];
    l[i][s[i] - '0'] = true;
  }
  rrep(i, n) {
    if (i + 1 < n) r[i] = r[i + 1];
    r[i][s[i] - '0'] = true;
  }
  set<int> st;
  rep(i, 1, n - 1) {
    rep(j, 10) rep(k, 10) if (l[i - 1][j] && r[i + 1][k]) {
      st.insert(j * 100 + (s[i] - '0') * 10 + k);
    }
  }
  wt(sz(st));
}
