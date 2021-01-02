#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> v(n);
  cin >> v;
  set<string> s;
  each(vi, v) if (vi[0] == '!') s.insert(vi.substr(1));
  each(vi, v) if (vi[0] != '!' && s.count(vi)) {
    wt(vi);
    return;
  }
  wt("satisfiable");
}
