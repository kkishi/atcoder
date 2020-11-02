#include <bits/stdc++.h>

#include "atcoder.h"

struct R {
  string city;
  int point;
  int index;
  bool operator<(const R& r) const {
    return make_pair(city, -point) < make_pair(r.city, -r.point);
  }
};

void Main() {
  ints(n);
  vector<R> v(n);
  rep(i, n) {
    cin >> v[i].city >> v[i].point;
    v[i].index = i;
  }
  sort(all(v));
  rep(i, n) wt(v[i].index + 1);
}
