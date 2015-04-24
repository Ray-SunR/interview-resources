CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o abstractpeople.o people.o decorator.o fatbody.o redhair.o thinbody.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${EXEC} ${DEPENDS} ${OBJECTS}
