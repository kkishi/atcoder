#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<int> a(n);
  cin >> a;
  V<int> head, tail;
  rep(i, n)((i & 1) ? head : tail).pb(a[i]);
  reverse(all(head));
  for (int i : tail) head.pb(i);
  if (n & 1) reverse(all(head));
  wt(head);
}
