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

ll n, k;
ll a[2 * 100000];
const ll tens = 1e9;

template <typename T>
T BinarySearch(T lo, T hi, std::function<bool(T)> pred) {
  while (lo + 1 < hi) {
    T mid = (hi - lo) / 2 + lo;
    if (pred(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  return lo;
}

// Returns the number of pairs whose values are equal to or less than x.
ll count(ll x) {
  ll cnt = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] < 0) {
      if (a[i-1] * a[i] <= x) {
        if (a[0] * a[i] <= x) {
          cnt += i;
          continue;
        }
        int j = BinarySearch<int>(0, i, [&](int idx) { return a[i] * a[idx] > x; });
        cnt += i - (j + 1);
      }
    } else {
      if (a[0] * a[i] <= x) {
        int j = BinarySearch<int>(0, i, [&](int idx) { return a[i] * a[idx] <= x; });
        cnt += j + 1;
      }
    }
  }
  return cnt;
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> a[i];
  sort(a, a + n);

  ll x = BinarySearch<ll>(-tens * tens - 1, tens * tens + 1, [&](ll x) {
    return count(x) < k;
  });
  dbg(x, count(x - 1), count(x), count(x + 1));
  out(x + 1);
}
