EXENAME = main
OBJS = main.o board.o ReflexAgent.o

CXX = clang++
CXXFLAGS = -std=c++14 -c -g -O0 -Wall -Wextra -pedantic
#CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
#LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lpthread -lm
LDFLAGS = -std=c++14 -lc++abi -lpthread -lm

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o : main.cpp board.h ReflexAgent.h evaluationAgent.h
	$(CXX) $(CXXFLAGS) main.cpp

board.o : board.cpp
	$(CXX) $(CXXFLAGS) board.cpp

ReflexAgent.o : ReflexAgent.cpp board.h
	$(CXX) $(CXXFLAGS) ReflexAgent.cpp

stateNode.o : stateNode.cpp board.h
	$(CXX) $(CXXFLAGS) stateNode.cpp

evaluationAgent.o : evaluationAgent.cpp stateNode.h board.h
	$(CXX) $(CXXFLAGS) evaluationAgent.cpp

clean :
	rm *o main.o