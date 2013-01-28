#include "test-tmpl.h"

template <typename T1, typename T2>
bool equal(const T1 &a1, const T2 &a2) {
	return a1 == a2;
}

template bool equal(const A &, const A &);
template bool equal(const A &, const B &);
template bool equal(const B &, const A &);
template bool equal(const B &, const B &);
