#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s, t);
  V<string> cand;
  for (int i = 0; i + t.size() <= s.size(); ++i) {
    bool ok = true;
    rep(j, t.size()) if (s[i + j] != '?' && s[i + j] != t[j]) ok = false;
    if (ok) {
      string ts = s;
      rep(j, t.size()) ts[i + j] = t[j];
      rep(i, ts.size()) if (ts[i] == '?') ts[i] = 'a';
      cand.push_back(ts);
    }
  }
  if (cand.empty()) {
    wt("UNRESTORABLE");
  } else {
    sort(all(cand));
    wt(cand[0]);
  }
}
