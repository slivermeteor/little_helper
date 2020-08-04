ROOT_DIR :=$(shell dirname $(realpath $(lastword $(MAKEFILE_LIST))))
CXXFLAGS += -std=c++17 -Wall -Werror -g
CPPLFAGS += -I$(ROOT_DIR)/../ -I$(ROOT_DIR)/../include/ -I$(ROOT_DIR)/../src/

all : encoding_test

encoding_test : encoding_test.o encoding.o
	g++ encoding_test.o encoding.o -o encoding_test.run $(CXXFLAGS) $(CPPLFAGS) -lstdc++fs
	-rm *.o
encoding_test.o :
	g++ -c encoding_test.cpp  $(CXXFLAGS) $(CPPLFAGS)
encoding_clean :
	-rm *.o
encoding.o :
	g++ -c ../src/encoding/encoding.cpp $(CXXFLAGS) $(CPPLFAGS)
