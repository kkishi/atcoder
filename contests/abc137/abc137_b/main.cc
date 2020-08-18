#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(k, x);
  int maxi = min(1000000, x + (k - 1));
  int mini = max(-1000000, x - (k - 1));
  for (int i = mini; i <= maxi; ++i) {
    cout << i << " ";
  }
  cout << endl;
}
