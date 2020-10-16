#include <bits/stdc++.h>

#include "atcoder.h"
#include "fast_io.h"
#include "mo.h"

struct DS {
  DS(int n) : c(n), kinds(n), unique_kinds(0) {}
  void Add(int i) {
    if (kinds[c[i] - 1]++ == 0) {
      ++unique_kinds;
    }
  }
  void Del(int i) {
    if (--kinds[c[i] - 1] == 0) {
      --unique_kinds;
    }
  }
  int Get() const { return unique_kinds; }
  V<int> c;
  V<int> kinds;
  int unique_kinds;
};

void Main() {
  ints(n, q);
  DS ds(n);
  cin >> ds.c;

  Mo<int, DS> mo(ds);
  rep(i, q) {
    ints(l, r);
    mo.AddQuery(l - 1, r);
  }

  for (int ans : mo.ProcessQueries()) {
    wt(ans);
  }
}
