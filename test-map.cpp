#include <iostream>
#include <cassert>
#include <vector>
#include <map>

#include <boost/unordered_map.hpp>

using namespace std;
using namespace boost;

typedef vector<pair<void *, unsigned> > PointsToMapTy;
typedef unordered_map<pair<void *, unsigned>, vector<unsigned> > PointedByMapTy;

struct Interval {
  Interval(unsigned long S, unsigned long E): Start(S), End(E) {}
  bool operator<(const Interval &Second) const {
    return End <= Second.Start;
  }

  unsigned long Start;
  unsigned long End;
};
typedef map<Interval, unsigned> IntervalTree;

PointsToMapTy PointingTo;
PointedByMapTy BeingPointedBy;
IntervalTree AddressVersion;

int main(int argc, char *argv[]) {
  string op;
  int n_ops = 0;
  while (cin >> op) {
    n_ops++;
    if (op == "add") {
      unsigned vid, ver;
      void *addr;
      cin >> vid >> hex >> addr >> dec >> ver;
      if (vid >= PointingTo.size()) {
        PointingTo.resize(vid + 1);
      }
      PointingTo[vid].first = addr;
      PointingTo[vid].second = ver;
      BeingPointedBy[make_pair(addr, ver)].push_back(vid);
    } else if (op == "remove") {
      unsigned vid;
      cin >> vid;
      if (vid < PointingTo.size() && PointingTo[vid].first != NULL) {
        PointedByMapTy::iterator j = BeingPointedBy.find(PointingTo[vid]);
        assert(j != BeingPointedBy.end());
        vector<unsigned>::iterator k = find(j->second.begin(),
                                            j->second.end(),
                                            vid);
        assert(k != j->second.end());
        j->second.erase(k);
        PointingTo[vid].first = NULL;
        PointingTo[vid].second = -1;
      }
    } else if (op == "interval") {
      unsigned long start, end;
      unsigned ver;
      cin >> start >> end >> ver;
      Interval itv(start, end);
      pair<IntervalTree::iterator, IntervalTree::iterator> er;
      er = AddressVersion.equal_range(itv);
      AddressVersion.erase(er.first, er.second);
      AddressVersion.insert(make_pair(itv, ver));
    } else if (op == "lookup") {
      void *addr;
      cin >> hex >> addr >> dec;
      Interval itv((unsigned long)addr, (unsigned long)addr + 1);
      IntervalTree::iterator pos = AddressVersion.find(itv);
      if (pos != AddressVersion.end())
        assert(pos->second != -1);
    } else {
      assert(false);
    }
  }
  cout << "# of ops = " << n_ops << "\n";
  return 0;
}
