#include <bits/stdc++.h>

#include "atcoder.h"

string Solve() {
  strings(s);
  rep(i, 3) {
    string t = s.substr(i, 3);
    if (t == "ooo") return "o";
    if (t == "xxx") return "x";
  }
  return "draw";
}

void Main() { wt(Solve()); }
