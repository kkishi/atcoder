#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  rd(string, T);
  rep(i, T.size()) if (T[i] == '?') T[i] = 'D';
  cout << T << endl;
}
