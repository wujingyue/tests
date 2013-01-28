#include <boost/unordered_set.hpp>
#include <boost/tuple/tuple.hpp>
using namespace boost;

unordered_set<tuple<unsigned long, unsigned long> > addrs;

int main(int argc, char *argv[]) {
  for (int i = 0; i < argc; ++i)
    addrs.insert(make_tuple((unsigned long)argv[i], (unsigned long)argv[i]));
  return 0;
}
