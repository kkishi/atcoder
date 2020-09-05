#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(n);
  V<string> s(n);
  cin >> s;
  rep(i, 26) {
    int cnt = numeric_limits<int>::max();
    char c = (char)('a' + i);
    rep(j, n) chmin(cnt, count(all(s[j]), c));
    cout << string(cnt, c);
  }
  cout << endl;
}
