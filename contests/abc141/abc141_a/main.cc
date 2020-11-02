#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  strings(s);
  vector<string> v = {"Sunny", "Cloudy", "Rainy"};
  rep(i, v.size()) if (v[i] == s) {
    wt(v[(i + 1) % 3]);
    break;
  }
}
