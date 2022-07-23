#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  map<string, int> mp;
  each(e, s) {
    int x = mp[e]++;
    cout << e;
    if (x) cout << "(" << x << ")";
    cout << endl;
  }
}
