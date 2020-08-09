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
  for (int i = s.size() - 1; i >= 1; --i) {
    if (s[i] == 'L') {
      swap(le, lo);
      ++le;
    }
    if (s[i - 1] == 'R') {
      ans[i] += le;
      ans[i - 1] += lo;
      le = lo = 0;
    }
  }
  rep(i, s.size()) {
    if (i) cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
