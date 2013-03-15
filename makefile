test-xed: test-xed.cpp
	$(CXX) -o $@ $^ -I$(PIN_HOME)/extras/xed2-intel64/include -L$(PIN_HOME)/extras/xed2-intel64/lib -lxed

test-gmp: test-gmp.cpp
	$(CXX) -o $@ $^ -lgmpxx -lgmp
