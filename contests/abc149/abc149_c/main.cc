#include <bits/stdc++.h>

#include "atcoder.h"
#include "prime.h"

void Main() {
  ints(x);
  vector<bool> sieve = Sieve(200000);
  while (!sieve[x]) ++x;
  wt(x);
}
