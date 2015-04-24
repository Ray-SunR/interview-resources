CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o observer.o subject.o horserace.o bettor.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

.PHONY: clean
