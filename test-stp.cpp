#include "stp/c_interface.h"
#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
using namespace std;

Expr vc_zero(VC vc) {
	return vc_bv32ConstExprFromInt(vc, 0);
}

Expr vc_one(VC vc) {
	return vc_bv32ConstExprFromInt(vc, 1);
}

Expr vc_uint_max(VC vc) {
	return vc_bv32ConstExprFromInt(vc, UINT_MAX);
}

Expr vc_int_max(VC vc) {
	return vc_bv32ConstExprFromInt(vc, INT_MAX);
}

Expr vc_int_min(VC vc) {
	return vc_bv32ConstExprFromInt(vc, INT_MIN);
}

void print_banner(const char *msg) {
	cout << "===== " << msg << " =====\n";
}

void test1() {
	print_banner("test1");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p'); // print counterexample
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr four = vc_bv32ConstExprFromInt(vc, 4);
	Expr b = vc_bv32PlusExpr(vc, a, four);
	Expr lt = vc_bvLtExpr(vc, a, b);
	Expr gt = vc_bvGtExpr(vc, a, b);
	Expr ne = vc_orExpr(vc, lt, gt);
	vc_assertFormula(vc, ne);
	// satisfiable? 
	cout << vc_query(vc, vc_falseExpr(vc)) << endl;
	vc_Destroy(vc);
}

void test2() {
	print_banner("test2");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	vc_assertFormula(vc, vc_orExpr(vc,
			vc_eqExpr(vc, a, zero),
			vc_eqExpr(vc, a, one)));
	vc_assertFormula(vc, vc_eqExpr(vc, b, one));
	vc_assertFormula(vc, vc_eqExpr(vc, a, b));
	cout << vc_query(vc, vc_falseExpr(vc)) << endl;
	vc_Destroy(vc);
}

void test3() {
	print_banner("test3");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	vc_assertFormula(vc, vc_orExpr(vc,
			vc_eqExpr(vc, a, zero),
			vc_eqExpr(vc, a, one)));
	vc_assertFormula(vc, vc_eqExpr(vc, b, one));
	vc_push(vc);
	cout << vc_query(vc, vc_eqExpr(vc, a, b)) << endl;
	vc_pop(vc);
	vc_push(vc);
	cout << vc_query(vc, vc_notExpr(vc, vc_eqExpr(vc, a, b))) << endl;
	vc_pop(vc);
	vc_Destroy(vc);
}

void test4() {
	print_banner("test4");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr i = vc_varExpr(vc, "i", int_type);
	Expr total = vc_varExpr(vc, "total", int_type);
	Expr nthreads = vc_varExpr(vc, "nthreads", int_type);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr s1 = vc_bv32MultExpr(vc, i, vc_bvDivExpr(vc, 32, total, nthreads));
	Expr s2 = vc_bv32MultExpr(
			vc, vc_bv32PlusExpr(vc, i, one), vc_bvDivExpr(vc, 32, total, nthreads));
	vc_push(vc);
	vc_assertFormula(vc, vc_bvLtExpr(vc, total, zero));
	vc_assertFormula(vc, vc_bvLtExpr(vc, nthreads, zero));
	vc_assertFormula(vc, vc_eqExpr(vc, s1, s2));
	cout << vc_query(vc, vc_falseExpr(vc)) << endl;
	vc_pop(vc);
	vc_Destroy(vc);
}

void test5() {
	print_banner("test5");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_bv32PlusExpr(vc, a, vc_bv32ConstExprFromInt(vc, 1));
	cout << vc_query(vc, vc_bvLtExpr(vc, a, b)) << endl;
	vc_Destroy(vc);
}

void test6() {
	print_banner("test6");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr b = vc_bv32PlusExpr(vc, a, one);
	Expr oo = vc_bv32ConstExprFromInt(vc, 0xffffffff);
	vc_assertFormula(vc, vc_bvLeExpr(vc, a, vc_bv32MinusExpr(vc, oo, one)));
	cout << vc_query(vc, vc_bvLtExpr(vc, a, b)) << endl;
	vc_Destroy(vc);
}

void test7() {
	print_banner("test7");
	VC vc = vc_createValidityChecker();
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a.bb14.i.i", int_type);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	cout << vc_query(vc, vc_eqExpr(vc, a, one)) << endl;
	vc_Destroy(vc);
}

void test8() {
	print_banner("test8");
	VC vc = vc_createValidityChecker();
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr minus_one = vc_bv32ConstExprFromInt(vc, -1);
	cout << vc_query(vc, vc_bvLeExpr(vc, minus_one, one)) << endl;
	vc_Destroy(vc);
}

void test9() {
#if 0
	print_banner("test9");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type long_type = vc_bvType(vc, 64);
	Expr zero = vc_bvConstExprFromLL(vc, 64, 0);
	Expr one = vc_bvConstExprFromLL(vc, 64, 1);
	Expr a = vc_varExpr(vc, "a", long_type);
	Expr b = vc_varExpr(vc, "b", long_type);
	vc_assertFormula(
			vc, vc_sbvLtExpr(vc, a, vc_bvConstExprFromLL(vc, 64, LLONG_MAX)));
	vc_assertFormula(vc, vc_sbvGtExpr(vc, b, zero));
	Expr a1 = vc_bvPlusExpr(vc, 64, a, one);
	Expr ab = vc_bvMultExpr(vc, 64, a, b);
	Expr a1b = vc_bvMultExpr(vc, 64, a1, b);
	Expr lll_ab = vc_bvMultExpr(
			vc, 128, vc_bvSignExtend(vc, a, 128), vc_bvSignExtend(vc, b, 128));
	Expr lll_a1b = vc_bvMultExpr(
			vc, 128, vc_bvSignExtend(vc, a1, 128), vc_bvSignExtend(vc, b, 128));
	vc_assertFormula(vc, vc_sbvLeExpr(
				vc, lll_ab, vc_bvSignExtend(
					vc, vc_bvConstExprFromLL(vc, 64, LLONG_MAX), 128)));
	vc_assertFormula(vc, vc_sbvGeExpr(
				vc, lll_ab, vc_bvSignExtend(
					vc, vc_bvConstExprFromLL(vc, 64, LLONG_MIN), 128)));
	vc_assertFormula(vc, vc_sbvLeExpr(
				vc, lll_a1b, vc_bvSignExtend(
					vc, vc_bvConstExprFromLL(vc, 64, LLONG_MAX), 128)));
	vc_assertFormula(vc, vc_sbvGeExpr(
				vc, lll_a1b, vc_bvSignExtend(
					vc, vc_bvConstExprFromLL(vc, 64, LLONG_MIN), 128)));
	cout << vc_query(vc, vc_sbvLtExpr(vc, ab, a1b)) << endl;
	vc_Destroy(vc);
#endif
}

void test10() {
	print_banner("test10");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
	vc_assertFormula(vc, vc_andExpr(vc,
				vc_sbvGtExpr(vc, a, zero),
				vc_eqExpr(vc, a, vc_sbvDivExpr(vc, 32, b, a))));
	cout << vc_query(vc, vc_falseExpr(vc)) << endl;
	vc_Destroy(vc);
}

void test11() {
	print_banner("test11");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr int_max = vc_bvConstExprFromInt(vc, 32, 0x7fffffff);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
#if 0
	vc_assertFormula(vc, vc_impliesExpr(vc,
				vc_eqExpr(vc, b, zero),
				vc_sbvLeExpr(vc, a, vc_bvDivExpr(vc, 32, int_max, b))));
#else
	vc_assertFormula(vc, vc_sbvGtExpr(vc, b, zero));
	vc_assertFormula(vc, vc_sbvLeExpr(vc, a, vc_sbvModExpr(vc, 32, int_max, b)));
#endif
	cout << vc_query(vc, vc_falseExpr(vc)) << endl;
	vc_Destroy(vc);
}

void test12() {
	print_banner("test12");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
	vc_assertFormula(vc, vc_eqExpr(vc, b, vc_bv32LeftShiftExpr(vc, 34, a)));
	// vc_assertFormula(vc, vc_eqExpr(vc, a, vc_bv32ConstExprFromInt(vc, 1)));
	cout << vc_query(vc, vc_eqExpr(vc, b, vc_bv32ConstExprFromInt(vc, 0))) << endl;
	vc_Destroy(vc);
}

void test13() {
	print_banner("test13");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);
	Type long_type = vc_bvType(vc, 64);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", long_type);
	vc_assertFormula(vc, vc_eqExpr(
				vc, a, vc_bv32ConstExprFromInt(vc, 0x82345678)));
	vc_assertFormula(vc, vc_eqExpr(vc, b, vc_bvConcatExpr(vc, vc_zero(vc), a)));
	// vc_assertFormula(vc, vc_eqExpr(vc, b, vc_bvSignExtend(vc, a, 64)));
	// vc_assertFormula(vc, vc_eqExpr(vc, b, vc_bvExtract(vc, a, 63, 0)));
	cout << vc_query(vc, vc_falseExpr(vc)) << endl;
	vc_Destroy(vc);
}

void test14() {
	print_banner("test14");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr a = vc_varExpr(vc, "a", int_type);
	vc_assertFormula(vc, vc_eqExpr(vc, a, one));

	Expr simple = vc_simplify(vc, vc_eqExpr(vc, a, a));
	vc_printExpr(vc, simple); cout << endl;

	simple = vc_simplify(vc, vc_eqExpr(vc, a, one));
	vc_printExpr(vc, simple); cout << endl;

	simple = vc_simplify(vc, vc_eqExpr(vc, one, vc_bv32PlusExpr(vc, zero, one)));
	vc_printExpr(vc, simple); cout << endl;
	vc_Destroy(vc);
}

void test15() {
	print_banner("test15");

	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr a = vc_varExpr(vc, "a", int_type);
	vc_assertFormula(vc, vc_eqExpr(vc, a, one));

	Expr simple = vc_simplify(vc, vc_eqExpr(vc, a, a));
	vc_printExpr(vc, simple); cout << endl;

	simple = vc_simplify(vc, vc_eqExpr(vc, a, one));
	vc_printExpr(vc, simple); cout << endl;

	simple = vc_simplify(vc, vc_eqExpr(vc, one, vc_bv32PlusExpr(vc, zero, one)));
	vc_printExpr(vc, simple); cout << endl;
	vc_Destroy(vc);
}

void test16() {
	print_banner("test16");

	VC vc = vc_createValidityChecker();
	vc_setInterfaceFlags(vc, EXPRDELETE, 0);

	vc_push(vc);
	vc_setFlags(vc, 'p');
	vc_pop(vc);

	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr a_eq_0  = vc_eqExpr(vc, a, zero);
	
	vc_assertFormula(vc, a_eq_0);

#if 0
	vc_DeleteExpr(int_type);
	vc_DeleteExpr(zero);
	vc_DeleteExpr(a);
	vc_DeleteExpr(a_eq_0);
#endif
	
	Expr f = vc_falseExpr(vc);
	cout << vc_query(vc, f) << endl;
	vc_DeleteExpr(f);

#if 0
	f = vc_falseExpr(vc);
	cout << vc_query(vc, f) << endl;
	vc_DeleteExpr(f);
#endif

	vc_Destroy(vc);
}

void test17() {
	print_banner("test17");

	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bv32Type(vc);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr three = vc_bv32ConstExprFromInt(vc, 3);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
	Expr c = vc_varExpr(vc, "c", int_type);
	vc_assertFormula(vc, vc_eqExpr(vc, c, three));
	vc_assertFormula(vc, vc_sbvGeExpr(vc, a, one));
	vc_assertFormula(vc, vc_eqExpr(vc, b, vc_bvVar32LeftShiftExpr(vc, c, a)));
	vc_assertFormula(vc, vc_sbvLeExpr(vc, a, vc_bvVar32RightShiftExpr(
					vc, c, vc_int_max(vc))));

	// cout << vc_query(vc, vc_sbvGtExpr(vc, b, zero)) << endl;
	cout << vc_query(vc, vc_notExpr(vc, vc_eqExpr(vc, b, zero))) << endl;

	vc_Destroy(vc);
}

void test18() {
	print_banner("test18");

	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);

	Expr a = vc_varExpr(vc, "a", int_type);

	vc_assertFormula(vc, vc_eqExpr(vc, a, one));
	vc_assertFormula(vc, vc_eqExpr(vc, a, zero));

	cout << vc_query(vc, vc_falseExpr(vc)) << endl;

	vc_Destroy(vc);
}

void test20() {
	print_banner("test20");
	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bvType(vc, 32);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr c4096 = vc_bv32ConstExprFromInt(vc, 4096);
	Expr c524288 = vc_bv32ConstExprFromInt(vc, 524288);
	Expr word_size = vc_bv32ConstExprFromInt(vc, 32);
	
	Expr radix = vc_varExpr(vc, "radix", int_type);
	Expr radix_minus_one = vc_bv32MinusExpr(vc, radix, one);
	Expr log2 = vc_varExpr(vc, "log2", int_type);
	Expr max_key = vc_varExpr(vc, "max_key", int_type);
	Expr max_num_digits = vc_varExpr(vc, "max_num_digits", int_type);
	Expr loopnum = vc_varExpr(vc, "loopnum", int_type);
	// shiftnum = loopnum * log2
	Expr shiftnum = vc_bv32MultExpr(vc, loopnum, log2);
	// bb = (radix - 1) << shiftnum
	Expr bb = vc_bvVar32LeftShiftExpr(vc, shiftnum, radix_minus_one);

	// 1 <= radix <= 4096
	vc_assertFormula(vc, vc_sbvLeExpr(vc, radix, c4096));
	vc_assertFormula(vc, vc_sbvGeExpr(vc, radix, one));
	// radix = (1 << log2)
	vc_assertFormula(vc, vc_eqExpr(vc, radix,
				vc_bvVar32LeftShiftExpr(vc, log2, one)));
#if 0
	// 0 < log2 < word_size
	vc_assertFormula(vc, vc_sbvGtExpr(vc, log2, zero));
	vc_assertFormula(vc, vc_sbvLtExpr(vc, log2, word_size));
#endif
	// 1 <= max_key <= 524288
	vc_assertFormula(vc, vc_sbvLeExpr(vc, max_key, c524288));
	vc_assertFormula(vc, vc_sbvGeExpr(vc, max_key, one));
	// 0 < max_num_digits < word_size
	vc_assertFormula(vc, vc_sbvGtExpr(vc, max_num_digits, zero));
	vc_assertFormula(vc, vc_sbvLtExpr(vc, max_num_digits, word_size));
	// radix ^ (max_num_digit - 1) <= max_key < radix ^ max_num_digit 
	// tmp = log2 * (max_num_digit - 1)
	Expr tmp = vc_bv32MultExpr(
			vc, log2, vc_bv32MinusExpr(vc, max_num_digits, one));
	Expr rem = vc_bvVar32RightShiftExpr(vc, tmp, max_key);
	vc_assertFormula(vc, vc_sbvGeExpr(vc, rem, one));
	vc_assertFormula(vc, vc_sbvLeExpr(vc, rem, radix_minus_one));
	// 0 <= loopnum < max_num_digits
	vc_assertFormula(vc, vc_sbvGeExpr(vc, loopnum, zero));
	vc_assertFormula(vc, vc_sbvLtExpr(vc, loopnum, max_num_digits));

	cout << vc_query(vc, vc_sbvGeExpr(vc, bb, zero)) << endl;
	// cout << vc_query(vc, vc_falseExpr(vc)) << endl;

	vc_Destroy(vc);
}

void test21() {
	print_banner("test21");

	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bv32Type(vc);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr three = vc_bv32ConstExprFromInt(vc, 3);
	Expr a = vc_varExpr(vc, "a", int_type);
	Expr b = vc_varExpr(vc, "b", int_type);
	Expr c = vc_varExpr(vc, "c", int_type);

	vc_assertFormula(vc, vc_eqExpr(vc, c, three));
	vc_assertFormula(vc, vc_sbvGeExpr(vc, a, one));
	vc_assertFormula(vc, vc_eqExpr(vc, b, vc_bvVar32LeftShiftExpr(vc, c, a)));
	vc_assertFormula(vc, vc_sbvLeExpr(vc, a, vc_bvVar32RightShiftExpr(
					vc, c, vc_int_max(vc))));

	// cout << vc_query(vc, vc_sbvGtExpr(vc, b, zero)) << endl;
	cout << vc_query(vc, vc_notExpr(vc, vc_eqExpr(vc, b, zero))) << endl;

	vc_Destroy(vc);
}

void test22() {
	print_banner("test22");

	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');

	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr one = vc_bv32ConstExprFromInt(vc, 1);
	Expr two = vc_bv32ConstExprFromInt(vc, 2);
	Expr eight = vc_bv32ConstExprFromInt(vc, 8);

	Expr ub = vc_varExpr(vc, "ub", int_type);
	Expr i = vc_varExpr(vc, "i", int_type);
	Expr i1 = vc_varExpr(vc, "i1", int_type);
	Expr i11 = vc_varExpr(vc, "i11", int_type);

	vc_assertFormula(vc, vc_sbvGeExpr(vc, i, zero));
	vc_assertFormula(vc, vc_sbvLeExpr(vc, i, ub));
	vc_assertFormula(vc, vc_eqExpr(vc, i1, vc_bv32PlusExpr(vc, i, one)));
	vc_assertFormula(vc, vc_eqExpr(vc, i11, vc_bv32PlusExpr(vc, i, two)));
	vc_assertFormula(vc, vc_xorExpr(vc,
				vc_sbvLtExpr(vc, i, ub),
				vc_sbvGeExpr(vc, i11, eight)));

	cout << vc_query(vc, vc_falseExpr(vc)) << endl;

	vc_Destroy(vc);
}

void test23() {
	print_banner("test23");

	VC vc = vc_createValidityChecker();

	Type int_type = vc_bv32Type(vc);
	Expr zero = vc_bv32ConstExprFromInt(vc, 0);
	Expr a = vc_varExpr(vc, "a", int_type);

	vc_assertFormula(vc, vc_sbvGeExpr(vc, a, zero));

	cout << vc_query(vc, vc_falseExpr(vc)) << endl;

	Expr b = vc_varExpr(vc, "b", int_type);
	Expr ce_a = vc_getCounterExample(vc, a);
	Expr ce_b = vc_getCounterExample(vc, b);
	cout << "ce_a = " << getBVUnsigned(ce_a) << endl;
	cout << "ce_b = " << getBVUnsigned(ce_b) << endl;

	vc_Destroy(vc);
}

void test24() {
	print_banner("test24");

	VC vc = vc_createValidityChecker();
	vc_setFlags(vc, 'p');
	Type int_type = vc_bv32Type(vc);

	Expr e = vc_parseExpr(vc,
			"/home/jingyue/Research/slicer/tools/stp-queries/0-unique.stp");
	assert(e != NULL);

	vc_printExpr(vc, e);

	vc_Destroy(vc);
}

int main(int argc, char *argv[]) {
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
	test11();
	test12();
	test13();
	test14();
	test15();
	test16();
	test17();
	test18();
	test20();
	test21();
	test22();
	test23();
	// test24();
	return 0;
}
