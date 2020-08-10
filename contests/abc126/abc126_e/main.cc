#include <bits/stdc++.h>

#include "disjointset.h"
#include "macros.h"

using namespace std;

int main() {
  rd(int, n, m);
  DisjointSet ds(n);
  rep(i, m) {
    rd(int, x, y, z);
    ds.Union(x - 1, y - 1);
  }
  set<int> s;
  rep(i, n) s.insert(ds.Find(i));
  wt(s.size());
}
