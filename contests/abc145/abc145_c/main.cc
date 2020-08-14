#include <bits/stdc++.h>

#include "geometry.h"
#include "macros.h"

using namespace std;

using Vec = Vector<double>;

int main() {
  rd(int, n);
  vector<Vec> v(n);
  cin >> v;
  sort(all(v));
  double sum = 0;
  int cnt = 0;
  do {
    rep(i, n - 1) sum += (v[i + 1] - v[i]).Norm();
    ++cnt;
  } while (next_permutation(all(v)));
  cout << setprecision(20);
  wt(sum / cnt);
}
