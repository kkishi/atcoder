#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

int main() {
  rd(ll, a, b);
  wt(Factorize(gcd(a, b)).size() + 1);
}
