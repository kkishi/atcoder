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
  in(int, q);
  multiset<ll> lo, hi;
  ll lo_sum = 0, hi_sum = 0;
  optional<ll> mid;
  ll bs = 0;
  while (q--) {
    in(int, t);
    if (t == 1) {
      in(ll, a, b);
      bs += b;
      if (!mid) {
        mid = a;
      } else if (a <= *mid) {
        lo.insert(a);
        lo_sum += *mid - a;
        while (lo.size() > hi.size()) {
          ll change = *mid - *lo.rbegin();

          hi.insert(*mid);
          hi_sum += change * hi.size();

          mid = *lo.rbegin();

          lo_sum -= change * lo.size();
          lo.erase(lo.find(*lo.rbegin()));
        }
      } else {
        hi.insert(a);
        hi_sum += a - *mid;
        while (lo.size() + 1 < hi.size()) {
          ll change = *hi.begin() - *mid;

          lo.insert(*mid);
          lo_sum += change * lo.size();

          mid = *hi.begin();

          hi_sum -= change * hi.size();
          hi.erase(hi.begin());
        }
      }
      dbg(lo.size(), hi.size());
      assert(lo.size() == hi.size() || lo.size() + 1 == hi.size());
      // dbg(*mid, lo_sum, hi_sum, lo.size(), hi.size());
    } else {
      out(*mid, lo_sum + hi_sum + bs);
    }
  }
}
