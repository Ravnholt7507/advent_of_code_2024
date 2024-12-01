CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  main.cpp 1December/first_solution.cpp 1December/second_solution.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = 1December/first_solution.h 1December/second_solution.h

MAIN = output 

all: ${MAIN}

${MAIN}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.
