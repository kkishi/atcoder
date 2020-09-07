#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(h, w);
  V<int> a(h), b(h);
  rep(i, h) {
    cin >> a[i] >> b[i];
    --a[i];  // [a, b)
  }

  map<int, int> m;
  multiset<int> ms;
  rep(i, w) {
    m[i] = i;
    ms.insert(0);
  }

  rep(i, h) {
    auto it = m.lower_bound(a[i]);
    auto jt = m.lower_bound(b[i] + 1);
    int maxi = -1;
    for (auto kt = it; kt != jt; ++kt) {
      chmax(maxi, kt->second);
      ms.erase(ms.find(kt->first - kt->second));
    }
    m.erase(it, jt);
    if (maxi != -1 && b[i] < w) {
      m[b[i]] = maxi;
      ms.insert(b[i] - maxi);
    }
    if (ms.empty()) {
      wt(-1);
    } else {
      wt(*ms.begin() + i + 1);
    }
  }
}
