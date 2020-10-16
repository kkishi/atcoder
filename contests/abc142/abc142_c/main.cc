#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  vector<pair<int, int>> v(n);
  rep(i, n) {
    cin >> v[i].first;
    v[i].second = i;
  }
  sort(all(v));
  rep(i, n) {
    if (i) cout << " ";
    cout << v[i].second + 1;
  }
  cout << endl;
}
