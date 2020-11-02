#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  V<int> v(6);
  for (char c : s) v[c - 'A']++;
  rep(i, 6) {
    if (i) cout << " ";
    cout << v[i];
  }
  cout << endl;
}
