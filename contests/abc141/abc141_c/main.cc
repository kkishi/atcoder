#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, n, k, q);
  vector<int> v(n);
  rep(i, q) {
    rd(int, a);
    ++v[a - 1];
  }
  rep(i, n) { wt(k - (q - v[i]) > 0 ? "Yes" : "No"); }
}
