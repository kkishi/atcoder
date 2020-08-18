#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(ll, N, A, B);
  wt(N / (A + B) * A + min(N % (A + B), A));
}
