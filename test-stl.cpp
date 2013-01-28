#include <iostream>
#include <unordered_map>
using namespace std;

namespace std {
template<typename T1, typename T2>
struct hash<pair<T1, T2> >: public unary_function<pair<T1, T2>, size_t> {
  size_t operator()(const pair<T1, T2> &p) const {
    return hash<T1>()(p.first) + hash<T2>()(p.second);
  }
};
}

unordered_map<pair<unsigned long, int>, int> a;

int main() {
  pair<unsigned long, int> key(NULL, 0);
  a[key] = 1;
  return 0;
}
