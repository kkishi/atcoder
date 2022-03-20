#include <bits/stdc++.h>

#include <iomanip>

#include "macros.h"

void Main();

int main() {
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}

using namespace std;

#define int i64

#define wt_flush(...) \
  do {                \
    wt(__VA_ARGS__);  \
    cout.flush();     \
  } while (0)

void Main() {
  ints(n);
  set<int> st;
  rep(i, 1, 2 * n + 2) st.insert(i);
  while (true) {
    auto it = st.begin();
    wt(*it);
    st.erase(it);
    ints(x);
    if (x == 0) break;
    st.erase(x);
  }
}
