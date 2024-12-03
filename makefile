CXX = g++
CXXFLAGS = -std=c++0x -Wall -pedantic-errors -g

SRCS =  main.cpp 3December/first_solution.cpp 3December/second_solution.cpp
OBJS = ${SRCS:.cpp=.o}
HEADERS = 3December/first_solution.h 3December/second_solution.h

MAIN = output 

all: ${MAIN}

${MAIN}: ${OBJS}
		${CXX} ${CXXFLAGS} ${OBJS} -o ${MAIN}

.cpp.o:
	${CXX} ${CXXFLAGS} -c $< -o $@

clean:
	${RM} ${PROGS} ${OBJS} *.o *~.
