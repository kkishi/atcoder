#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(K);
  strings(S);

  if (S.size() <= K) {
    wt(S);
  } else {
    wt(S.substr(0, K) + "...");
  }
}
