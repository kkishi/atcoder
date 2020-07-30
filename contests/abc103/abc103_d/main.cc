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
using P = std::pair<int, int>;

using namespace std;

int main() {
  in(int, n, m);
  set<P> s;
  rep(i, m) {
    in(int, a, b);
    auto intersection = [](P a, P b) -> optional<P> {
      if (a.second <= b.first || b.second <= a.first) {
        return nullopt;
      }
      return {{max(a.first, b.first), min(a.second, b.second)}};
    };
    auto it = s.insert({a, b}).first;
    if (it != s.begin()) {
      auto jt = prev(it);
      auto i = intersection(*it, *jt);
      if (i) {
        assert(i->first < i->second);
        s.erase(it);
        s.erase(jt);
        s.insert(*i);
        continue;
      }
    }
    if (auto jt = next(it); jt != s.end()) {
      auto i = intersection(*it, *jt);
      if (i) {
        assert(i->first < i->second);
        s.erase(it);
        s.erase(jt);
        s.insert(*i);
        continue;
      }
    }
  }
  out(s.size());
}
