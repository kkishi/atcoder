#include <bits/stdc++.h>

#include <boost/hana/functional/fix.hpp>

template <typename T, typename = void>
struct is_dereferenceable : std::false_type {};
template <typename T>
struct is_dereferenceable<T, std::void_t<decltype(*std::declval<T>())>>
    : std::true_type {};

template <typename T, typename = void>
struct is_iterable : std::false_type {};
template <typename T>
struct is_iterable<T, std::void_t<decltype(std::begin(std::declval<T>())),
                                  decltype(std::end(std::declval<T>()))>>
    : std::true_type {};

template <typename T, typename = void>
struct is_applicable : std::false_type {};
template <typename T>
struct is_applicable<T, std::void_t<decltype(std::tuple_size<T>::value)>>
    : std::true_type {};

template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args);
template <typename T>
void debug(const T& v) {
  if constexpr (is_dereferenceable<T>::value) {
    std::cerr << "{";
    if (v) {
      debug(*v);
    } else {
      std::cerr << "nil";
    }
    std::cerr << "}";
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    std::cerr << "{";
    for (auto it = std::begin(v); it != std::end(v); ++it) {
      if (it != std::begin(v)) std::cerr << ", ";
      debug(*it);
    }
    std::cerr << "}";
  } else if constexpr (is_applicable<T>::value) {
    std::cerr << "{";
    std::apply([](const auto&... args) { debug(args...); }, v);
    std::cerr << "}";
  } else {
    std::cerr << v;
  }
}
template <typename T, typename... Ts>
void debug(const T& value, const Ts&... args) {
  debug(value);
  std::cerr << ", ";
  debug(args...);
}
#if DEBUG
#define dbg(...)                        \
  do {                                  \
    cerr << #__VA_ARGS__ << ": ";       \
    debug(__VA_ARGS__);                 \
    cerr << " (L" << __LINE__ << ")\n"; \
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
#define rd(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);
#define ints(...) rd(int, __VA_ARGS__);
#define strings(...) rd(string, __VA_ARGS__);

// Strings used for yes/no questions. Defined as variables so that it can be
// adjusted for each contest site.
const char *yes_str = "Yes", *no_str = "No";

template <typename T>
void write_to_cout(const T& value) {
  if constexpr (std::is_same<T, bool>::value) {
    std::cout << (value ? yes_str : no_str);
  } else if constexpr (is_iterable<T>::value &&
                       !std::is_same<T, std::string>::value) {
    for (auto it = std::begin(value); it != std::end(value); ++it) {
      if (it != std::begin(value)) std::cout << " ";
      std::cout << *it;
    }
  } else {
    std::cout << value;
  }
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  write_to_cout(value);
  std::cout << ' ';
  write_to_cout(args...);
}
#define wt(...)                 \
  do {                          \
    write_to_cout(__VA_ARGS__); \
    cout << '\n';               \
  } while (0)

#define all(x) (x).begin(), (x).end()
#define eb(...) emplace_back(__VA_ARGS__)
#define pb(...) push_back(__VA_ARGS__)

#define dispatch(_1, _2, _3, name, ...) name

#define as_i64(x)                                                          \
  (                                                                        \
      [] {                                                                 \
        static_assert(                                                     \
            std::is_integral<                                              \
                typename std::remove_reference<decltype(x)>::type>::value, \
            "rep macro supports std integral types only");                 \
      },                                                                   \
      static_cast<int64_t>(x))

#define rep3(i, a, b) for (int64_t i = as_i64(a); i < as_i64(b); ++i)
#define rep2(i, n) rep3(i, 0, n)
#define rep1(n) rep2(_loop_variable_, n)
#define rep(...) dispatch(__VA_ARGS__, rep3, rep2, rep1)(__VA_ARGS__)

#define rrep3(i, a, b) for (int64_t i = as_i64(b) - 1; i >= as_i64(a); --i)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep1(n) rrep2(_loop_variable_, n)
#define rrep(...) dispatch(__VA_ARGS__, rrep3, rrep2, rrep1)(__VA_ARGS__)

#define each3(k, v, c) for (auto&& [k, v] : c)
#define each2(e, c) for (auto&& e : c)
#define each(...) dispatch(__VA_ARGS__, each3, each2)(__VA_ARGS__)

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& v) {
  for (T& vi : v) is >> vi;
  return is;
}

template <typename T, typename U>
std::istream& operator>>(std::istream& is, std::pair<T, U>& p) {
  is >> p.first >> p.second;
  return is;
}

template <typename T, typename U>
bool chmax(T& a, U b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
bool chmin(T& a, U b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <typename T, typename U>
auto max(T a, U b) {
  return a > b ? a : b;
}

template <typename T, typename U>
auto min(T a, U b) {
  return a < b ? a : b;
}

template <typename T>
int64_t sz(const T& v) {
  return std::size(v);
}

template <typename T>
int64_t popcount(T i) {
  return std::bitset<std::numeric_limits<T>::digits>(i).count();
}

template <typename T>
bool hasbit(T s, int i) {
  return std::bitset<std::numeric_limits<T>::digits>(s)[i];
}

template <typename T, typename U>
auto div_floor(T n, U d) {
  if (d < 0) {
    n = -n;
    d = -d;
  }
  if (n < 0) {
    return -((-n + d - 1) / d);
  }
  return n / d;
};

template <typename T, typename U>
auto div_ceil(T n, U d) {
  if (d < 0) {
    n = -n;
    d = -d;
  }
  if (n < 0) {
    return -(-n / d);
  }
  return (n + d - 1) / d;
}

template <typename T>
bool even(T x) {
  return x % 2 == 0;
}

std::array<std::pair<int64_t, int64_t>, 4> adjacent(int64_t i, int64_t j) {
  return {{{i + 1, j}, {i, j + 1}, {i - 1, j}, {i, j - 1}}};
}

bool inside(int64_t i, int64_t j, int64_t I, int64_t J) {
  return 0 <= i && i < I && 0 <= j && j < J;
}

const int64_t big = std::numeric_limits<int64_t>::max() / 4;

using i64 = int64_t;
using i32 = int32_t;

template <typename T>
using low_priority_queue =
    std::priority_queue<T, std::vector<T>, std::greater<T>>;

template <typename T>
using V = std::vector<T>;
template <typename T>
using VV = V<V<T>>;

void Main();

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout << std::fixed << std::setprecision(20);
  Main();
  return 0;
}

const auto& Fix = boost::hana::fix;

using namespace std;

#define int i64

void Main() {
  ints(n);
  using T = tuple<int, int, int>;
  set<T> s;
  map<int, int> c;
  rep(i, n) {
    ints(a);
    s.insert({i, i + 1, a});
    ++c[a];
  }
  int ans = 0;
  auto f = [](int x) { return x * (x - 1) / 2; };
  each(_, v, c) ans += f(v);
  ints(q);
  rep(q) {
    ints(l, r, x);
    --l;
    dbg(l, r, x);
    dbg(s);
    auto it = s.lower_bound({l, 0, 0});
    auto b = [](const T& t) { return get<0>(t); };
    auto e = [](const T& t) { return get<1>(t); };
    auto a = [](const T& t) { return get<2>(t); };
    auto len = [&](const T& t) { return e(t) - b(t); };
    dbg(*it);
    if (it == s.end()) --it;
    auto lt = it;
    while (l < b(*lt)) --lt;
    dbg(*lt);
    auto rt = lt;
    while (e(*rt) < r) ++rt;
    dbg(*rt);
    map<int, int> ch;
    V<T> rem, add;
    if (b(*lt) < l) {
      T t = *lt;
      get<1>(t) = l;
      add.pb(t);
    }
    if (r < e(*rt)) {
      T t = *rt;
      get<0>(t) = r;
      add.pb(t);
    }
    add.eb(l, r, x);
    for (it = lt;; ++it) {
      rem.pb(*it);
      if (it == rt) break;
    }
    each(t, rem) {
      s.erase(t);
      int x = c[a(t)];
      int y = x - len(t);
      assert(y >= 0);
      c[a(t)] = y;
      ans -= f(x);
      ans += f(y);
      dbg(a(t), x, y);
    }
    each(t, add) {
      s.insert(t);
      int x = c[a(t)];
      int y = x + len(t);
      c[a(t)] = y;
      ans -= f(x);
      ans += f(y);
      dbg(a(t), x, y);
    }
    wt(ans);
  }
}
