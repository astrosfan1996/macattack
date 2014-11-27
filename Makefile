CROSS =
CXX   = $(CROSS)g++
RM    = rm -f

test_sha1: test_sha1.cpp sha1.cpp sha1.hpp
	$(CXX) -std=c++11 -o $@ test_sha1.cpp sha1.cpp

clean:
	$(RM) test_sha1