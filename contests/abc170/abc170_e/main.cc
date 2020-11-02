#include <bits/stdc++.h>

#include "atcoder.h"

const int kMax = 200000;

template <typename Map>
void Erase(Map& m, int value) {
  m.erase(m.find(value));
}

void Main() {
  ints(n, q);
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<multiset<int, greater<int>>> kg(kMax + 1);
  rep(i, n) kg[b[i]].insert(a[i]);
  multiset<int> kgs;
  rep(i, kMax + 1) if (kg[i].size() > 0) { kgs.insert(*kg[i].begin()); }
  while (q--) {
    ints(c, d);
    --c;
    auto& before = kg[b[c]];
    Erase(kgs, *before.begin());
    Erase(before, a[c]);
    if (!before.empty()) {
      kgs.insert(*before.begin());
    }

    b[c] = d;

    auto& after = kg[b[c]];
    if (!after.empty()) {
      Erase(kgs, *after.begin());
    }
    after.insert(a[c]);
    kgs.insert(*after.begin());

    wt(*kgs.begin());
  }
}
