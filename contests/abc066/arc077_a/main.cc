#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> head, tail;
  rep(i, n)((i & 1) ? head : tail).push_back(a[i]);
  reverse(all(head));
  for (int i : tail) head.push_back(i);
  if (n & 1) reverse(all(head));
  rep(i, sz(head)) {
    if (i) cout << " ";
    cout << head[i];
  }
  cout << endl;
}
