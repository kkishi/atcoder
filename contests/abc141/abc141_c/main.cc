#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n, k, q);
  vector<int> v(n);
  rep(i, q) {
    ints(a);
    ++v[a - 1];
  }
  rep(i, n) wt(k > q - v[i]);
}
