#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, s);
  vector<int> ans(s.size());
  int re = 0;
  int ro = 0;
  rep(i, s.size() - 1) {
    if (s[i] == 'R') {
      swap(re, ro);
      ++re;
    }
    if (s[i + 1] == 'L') {
      ans[i] += re;
      ans[i + 1] += ro;
      re = ro = 0;
    }
  }
  int le = 0;
  int lo = 0;
  rrep(i, s.size() - 1) {
    if (s[i + 1] == 'L') {
      swap(le, lo);
      ++le;
    }
    if (s[i] == 'R') {
      ans[i + 1] += le;
      ans[i] += lo;
      le = lo = 0;
    }
  }
  rep(i, s.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
