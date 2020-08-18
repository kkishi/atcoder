#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(H1, M1, H2, M2, K);
  cout << ((H2 * 60 + M2) - (H1 * 60 + M1) - K) << endl;
}
