#include <bits/stdc++.h>

#include "disjointset.h"
#include "macros.h"

using namespace std;

int main() {
  ints(n, k, l);
  DisjointSet dsk(n);
  rep(k) {
    ints(p, q);
    dsk.Union(p - 1, q - 1);
  }
  DisjointSet dsl(n);
  rep(l) {
    ints(r, s);
    dsl.Union(r - 1, s - 1);
  }
  V<pair<int, int>> v;
  rep(i, n) v.emplace_back(dsk.Find(i), dsl.Find(i));
  map<pair<int, int>, int> m;
  for (auto& p : v) ++m[p];
  rep(i, n) {
    if (i) cout << " ";
    cout << m[v[i]];
  }
  cout << endl;
}
