#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  vector<int> cost = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  in(int, n, m);

  vector<int> a(m);
  rep(i, m) cin >> a[i];
  sort(all(a), greater());

  int cheapest_digit = 0;
  int cheapest_cost = 10;
  rep(i, a.size()) if (cost[a[i]] < cheapest_cost) {
    cheapest_digit = a[i];
    cheapest_cost = cost[a[i]];
  }
  dbg(cheapest_digit, cheapest_cost);

  int digits = n / cheapest_cost;
  int rem = n - cheapest_cost * digits;
  dbg(digits, rem);

  rep(i, digits) {
    bool changed = false;
    if (rem > 0) {
      rep(j, a.size()) if (int diff = cost[a[j]] - cheapest_cost; diff <= rem) {
        rem -= diff;
        cout << a[j];
        changed = true;
        break;
      }
    }
    if (!changed) {
      cout << cheapest_digit;
    }
  }
  cout << endl;
}
