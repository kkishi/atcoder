#include <bits/stdc++.h>

template <typename T>
void debug(T value) {
  std::cerr << value;
}

template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}

#define ALL(x) (x).begin(), (x).end()
#define DBG(...)                \
  cerr << #__VA_ARGS__ << ": "; \
  debug(__VA_ARGS__);           \
  cerr << " (L" << __LINE__ << ")" << endl
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int main() {
}
