#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, n);
  --n;
  ll x = 26;
  int l = 1;
  while (n >= x) {
    n -= x;
    x *= 26;
    ++l;
  }
  string s;
  rep(i, l) {
    s += 'a' + (n % 26);
    n /= 26;
  }
  reverse(all(s));
  wt(s);
}
