#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(q);
  int curr = 0;
  map<int, pair<int, int>> cell;
  cell[0] = {0, -1};
  map<int, int> note;
  V<int> ans;
  rep(i, q) {
    strings(op);
    if (op == "ADD") {
      ints(x);
      cell[i + 1] = {curr, x};
      curr = i + 1;
    } else if (op == "DELETE") {
      curr = cell[curr].first;
    } else if (op == "SAVE") {
      ints(y);
      note[y] = curr;
    } else {
      assert(op == "LOAD");
      ints(z);
      curr = note[z];
    }
    ans.eb(cell[curr].second);
  }
  wt(ans);
}
