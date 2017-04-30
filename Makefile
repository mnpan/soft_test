GTEST_DIR = ~/1052Testing/googletest-master/googletest
GCOV_FLAG = -fprofile-arcs -ftest-coverage

all: gtest-all.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include -pthread main_test.cpp libgtest.a -o unittest

init:
	g++ -isystem ${GTEST_DIR}/include -I${GTEST_DIR} \
	    -pthread -c ${GTEST_DIR}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o

gcov: gtest-all.o libgtest.a
	g++ -isystem ${GTEST_DIR}/include -pthread $(GCOV_FLAG) main_test.cpp libgtest.a -o GCOV/coverage
