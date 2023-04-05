#include <bits/stdc++.h>

#include "atcoder.h"
#include "int_geometry.h"

void Main() {
  ints(n);
  Polygon P(n);
  cin >> P;
  ints(q);
  rep(q) {
    Point p;
    cin >> p;
    V<string> s = {"OUT", "IN", "ON"};
    wt(s[ConvexHullPointPosition(P, p)]);
  }
}
