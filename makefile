CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  main.cpp $(wildcard *December/solution.cpp)
OBJS = ${SRCS:.cpp=.o}
HEADERS = $(wildcard *December/solution.h)

MAIN = output 

all: ${MAIN}

${MAIN}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.
