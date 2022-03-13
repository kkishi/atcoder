#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  V<string> s(3);
  cin >> s;
  set<char> st;
  each(si, s) each(e, si) st.insert(e);
  const string NG = "UNSOLVABLE";
  if (sz(st) > 10) {
    wt(NG);
    return;
  }
  V<char> v(all(st));
  while (sz(v) < 10) v.pb('A');
  sort(v);
  do {
    map<char, int> m;
    rep(i, sz(v)) m[v[i]] = i;
    V<int> n(3);
    bool ok = true;
    rep(i, 3) {
      string t(s[i]);
      rep(j, sz(t)) t[j] = '0' + m[s[i][j]];
      n[i] = stoll(t);
      if (t[0] == '0') ok = false;
    }
    if (!ok) continue;
    if (n[0] + n[1] == n[2]) {
      each(e, n) wt(e);
      return;
    }
  } while (next_permutation(all(v)));
  wt(NG);
}
