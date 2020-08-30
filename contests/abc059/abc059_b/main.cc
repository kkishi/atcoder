#include <bits/stdc++.h>

#include "bignum.h"
#include "macros.h"

using namespace std;

int main() {
  rd(bigint, a, b);
  wt(a == b ? "EQUAL" : a < b ? "LESS" : "GREATER");
}
