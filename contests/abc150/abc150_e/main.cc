#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using namespace std;

int n;
int c[200000];

int main() {
  cin >> n;
  rep(i, n) cin >> c[i];
  sort(c, c + n);

  mint ans = 0;
  mint sum = 0;
  rep(i, n) {
    ans = ans * 2 + mint(c[i]) * mint(2).Pow(i) + sum;
    sum = sum * 2 + mint(c[i]) * mint(2).Pow(i);
    dbg(ans, sum);
  }
  wt(ans * mint(2).Pow(n));
}
