#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  V<string> v{"a"};
  rep(n - 1) {
    V<string> nv;
    for (const string& s : v) {
      char mc = 'a';
      for (char c : s) chmax(mc, c);
      for (char c = 'a'; c <= mc + 1; ++c) {
        nv.push_back(s + c);
      }
    }
    swap(v, nv);
  }
  for (const string& s : v) wt(s);
}
