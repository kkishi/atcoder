#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int main() {
  rd(string, l);
  vector<mint> dp_eq(l.size() + 1), dp_lo(l.size() + 1);
  dp_eq[0] = 1;
  rep(i, l.size()) {
    if (l[i] == '0') {
      dp_eq[i + 1] = dp_eq[i];
      dp_lo[i + 1] = dp_lo[i] * 3;
    } else {
      dp_eq[i + 1] = dp_eq[i] * 2;
      dp_lo[i + 1] = dp_lo[i] * 3 + dp_eq[i];
    }
  }
  wt(dp_eq[l.size()] + dp_lo[l.size()]);
}
