#include <bits/stdc++.h>

#include "macros.h"
#include "mo.h"

using namespace std;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  rd(int, n, q);
  DS ds(n);
  rep(i, n) cin >> ds.c[i];

  Mo<int, DS> mo(ds);
  rep(i, q) {
    rd(int, l, r);
    mo.AddQuery(l - 1, r);
  }

  for (int ans : mo.ProcessQueries()) {
    wt(ans);
  }
}
