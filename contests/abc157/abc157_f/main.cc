#include <bits/stdc++.h>

template <typename T>
struct Vector {
  T x, y;
  T Norm() const { return std::sqrt(x * x + y * y); }
  Vector& operator+=(const Vector& v) {
    (*this).x += v.x;
    (*this).y += v.y;
    return *this;
  }
  Vector operator+(const Vector& v) const { return Vector(*this) += v; }
  Vector& operator-=(const Vector& v) {
    (*this).x -= v.x;
    (*this).y -= v.y;
    return *this;
  }
  Vector operator-(const Vector& v) const { return Vector(*this) -= v; }
  Vector& operator*=(T t) {
    (*this).x *= t;
    (*this).y *= t;
    return *this;
  }
  Vector operator*(T t) const { return Vector(*this) *= t; }
  Vector Rot90() const { return {-y, x}; }
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

template <typename T>
struct Circle {
  using V = Vector<T>;
  V center;
  double radius;

  std::vector<V> Intersections(const Circle& c) const {
    // TODO: Handle cases where there is no intersection and there is only one
    // intersection.
    auto sq = [](T x) -> T { return x * x; };
    V v = c.center - center;
    T l = v.Norm();
    if (l >= radius + c.radius ||
        (l + radius) <= c.radius ||
        (l + c.radius) <= radius) {
      return {};
    }
    T x = (sq(radius) - sq(c.radius) + sq(l)) / (2 * l);
    T a = std::sqrt(sq(radius) - sq(x));
    V perpendicular_foot = v * (x / l);
    V perpendicular = v.Rot90() * (a / l);
    return {center + perpendicular_foot + perpendicular,
            center + perpendicular_foot - perpendicular};
  }
};

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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using Vec = Vector<double>;
using Circ = Circle<double>;
using ll = long long;

using namespace std;

int N, K;
Vec p[60];
double c[60];

bool Ok(double t) {
  DBG(t);
  vector<Vec> vs(p, p + N);
  auto Rad = [t](int i) { return t / c[i]; };
  REP(i, N) REP(j, i) {
    Circ ci = {p[i], Rad(i)}, cj = {p[j], Rad(j)};
    DBG(ci.center, ci.radius, cj.center, cj.radius);
    FOR(v, ci.Intersections(cj)) {
      DBG(v);
      vs.push_back(v);
    }
  }
  // DBG(t, vs.size());
  REP(i, vs.size()) {
    int contains = 0;
    REP(j, N) {
      // This 1e-10 was important.
      if (Rad(j) + 1e-10 > (vs[i] - p[j]).Norm()) ++contains;
    }
    DBG(t, i, vs[i], contains);
    if (contains >= K) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> N >> K;
  REP(i, N) cin >> p[i].x >> p[i].y >> c[i];

  // Initially lo was 0.1 for some reason, which resulted WA.
  double lo = 0, hi = 10000000;
  const double EPS = 1e-8;
  while (hi - lo > EPS) {
    double mid = (hi + lo) / 2;
    (Ok(mid) ? hi : lo) = mid;
  }
  cout << setprecision(20) << lo << endl;
}
