#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

const int kBits = 63;
using bs = bitset<kBits>;

bool check(vector<bs> v, bs x) {
  // rep(i, v.size()) dbg(v[i].to_string());
  int pivot = 0;
  rep(bit, kBits) {
    for (int i = pivot; i < v.size(); ++i) {
      if (!v[i][bit]) continue;
      swap(v[pivot], v[i]);
      for (int j = 0; j < v.size(); ++j) {
        if (j == pivot) continue;
        if (!v[j][bit]) continue;
        v[j] ^= v[pivot];
      }
      ++pivot;
    }
  }
  dbg(x.to_string());
  rep(i, v.size()) dbg(v[i].to_string());
  rep(i, kBits) if (x[i]) {
    bool ok = false;
    rep(j, v.size()) if (v[j][i]) { ok = true; }
    if (!ok) {
      return false;
    }
  }
  return true;
}

bool nonzero() {
  rd(int, n);
  vector<bs> a(n);
  rep(i, n) {
    rd(ll, ai);
    a[i] = ai;
  }
  rd(string, s);
  vector<bs> v;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      v.push_back(a[i]);
    } else {
      if (!check(v, a[i])) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  rd(int, t);
  while (t--) {
    wt(nonzero() ? 1 : 0);
  }
}
