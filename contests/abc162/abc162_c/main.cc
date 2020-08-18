#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(K);
  int sum = 0;
  rep(a, K) rep(b, K) rep(c, K) sum += gcd(a + 1, gcd(b + 1, c + 1));
  wt(sum);
}
