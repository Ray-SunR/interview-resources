CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = main
OBJECTS = main.o bullet.o dragon.o enemy.o sword.o turtle.o weapon.o
DEPENDS = ${OBJECTS:.o=.d}
${EXEC}:${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${EXEC} ${DEPENDS} ${OBJECTS}
