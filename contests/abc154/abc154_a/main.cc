#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(string, S, T);
  rd(int, A, B);
  rd(string, U);
  (U == S ? A : B)--;
  wt(A, B);
}
