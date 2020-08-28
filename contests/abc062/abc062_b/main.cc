#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(h, w);
  V<string> a(h);
  cin >> a;
  wt(string(w + 2, '#'));
  rep(i, h) wt('#' + a[i] + '#');
  wt(string(w + 2, '#'));
}
