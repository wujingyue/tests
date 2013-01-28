#include <set>
using namespace std;

struct compare {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second <= b.first;
  }
};

typedef set<pair<int, int>, compare> SetType;
SetType s;

int main() {
  s.insert(make_pair(0, 2));
  s.insert(make_pair(3, 5));
  s.insert(make_pair(6, 8));
  s.insert(make_pair(9, 11));
  s.insert(make_pair(12, 14));
  s.insert(make_pair(15, 17));
  s.insert(make_pair(18, 20));
  pair<SetType::iterator, SetType::iterator> ret;
  ret = s.equal_range(make_pair(4, 13));
  printf("[%d, %d), [%d, %d)\n",
         ret.first->first, ret.first->second,
         ret.second->first, ret.second->second);
  return 0;
}
