EXENAME = mp2
OBJS = mp2.o main.o board.o ReflexAgent.o

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lpthread -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp board.h ReflexAgent.h
	$(CXX) $(CXXFLAGS) main.cpp

board.o : board.cpp
	$(CXX) $(CXXFLAGS) main.cpp

ReflexAgent.o : ReflexAgent.cpp board.h
	$(CXX) $(CXXFLAGS) main.cpp

clean :
	rm *o main.o