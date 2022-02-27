#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(s);
  V<string> v;
  int i = 0;
  rep(j, n) {
    if (s[j] == 'C') {
      v.pb(s.substr(i, j - i));
      v.pb("C");
      i = j + 1;
    }
  }
  if (i < n) v.pb(s.substr(i, n - i));
  string ans;
  each(e, v) {
    if (e != "C" && sz(e) > 1) {
      while (true) {
        sort(all(e));
        string E;
        rep(i, sz(e)) {
          if (e[i] == 'B' && e[i + 1] == 'B') {
            ++i;
            E += 'A';
          } else {
            E += e[i];
          }
        }
        if (e == E) break;
        swap(e, E);
      }
    }
    ans += e;
  }
  wt(ans);
}
