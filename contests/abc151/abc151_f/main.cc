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
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define CIN(type, ...) \
  type __VA_ARGS__;    \
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
#define COUT(...) write_to_cout(__VA_ARGS__);

#define ALL(x) (x).begin(), (x).end()
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

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
    if (l >= radius + c.radius || (l + radius) <= c.radius ||
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

using Vec = Vector<double>;
Vec vec[50];

int main() {
  CIN(int, N);
  REP(i, N) cin >> vec[i].x >> vec[i].y;
  double lo = 0, hi = 10000000000;
  REP(iter, 100) {
    double mid = (hi + lo) / 2;
    bool ok = false;
    REP(i, N) for (int j = i + 1; j < N; ++j) {
      vector<Vec> vs = (Circle<double>{vec[i], mid}).Intersections({vec[j], mid});
      for (const Vec& v : vs) {
        bool ok2 = true;
        REP(k, N) if ((vec[k] - v).Norm() > mid + 1e-9) {
          ok2 = false;
        }
        if (ok2) {
          ok = true;
        }
      }
    }
    if (ok) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  cout << setprecision(10);
  COUT(lo);
}
