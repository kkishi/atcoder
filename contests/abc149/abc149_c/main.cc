#include <bits/stdc++.h>

#include "macros.h"
#include "prime.h"

using namespace std;

int main() {
  ints(x);
  vector<bool> sieve = Sieve(200000);
  while (!sieve[x]) ++x;
  wt(x);
}
