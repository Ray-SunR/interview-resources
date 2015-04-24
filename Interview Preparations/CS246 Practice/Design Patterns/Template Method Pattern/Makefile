CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o abstractpeople.o blackpeople.o whitepeople.o yellowpeople.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}
