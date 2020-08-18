#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int kMax = 200000;

template <typename Map>
void Erase(Map& m, int v) {
  auto it = m.find(v);
  if (it->second > 1) {
    --it->second;
  } else {
    m.erase(it);
  }
}

int main() {
  ints(n, q);
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i] >> b[i];
  vector<map<int, int, greater<int>>> kg(kMax + 1);
  rep(i, n) kg[b[i]][a[i]]++;
  map<int, int> kgs;
  rep(i, kMax + 1) if (kg[i].size() > 0) { kgs[kg[i].begin()->first]++; }
  while (q--) {
    ints(c, d);
    --c;
    auto& before = kg[b[c]];
    Erase(kgs, before.begin()->first);
    Erase(before, a[c]);
    if (!before.empty()) {
      kgs[before.begin()->first]++;
    }

    b[c] = d;

    auto& after = kg[b[c]];
    if (!after.empty()) {
      Erase(kgs, after.begin()->first);
    }
    after[a[c]]++;
    kgs[after.begin()->first]++;

    wt(kgs.begin()->first);
  }
}
