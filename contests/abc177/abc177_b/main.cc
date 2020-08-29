#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  strings(s, t);
  int ans = t.size();
  rep(i, s.size() - t.size() + 1) {
    int sum = 0;
    rep(j, t.size()) if (s[i + j] != t[j])++ sum;
    chmin(ans, sum);
  }
  wt(ans);
}
