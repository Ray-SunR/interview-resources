CXX=g++
CXXFLAG=-Wall -MMD
EXEC=main
OBJECT=main.o subject.o observer.o bettor.o horserace.o
DEPENDS=${OBJECT:.o=.d}
${EXEC}:${OBJECT}
	${CXX} ${CXXFLAG} ${OBJECT} -o ${EXEC}
-include ${DEPENDS}

clean:
	rm ${EXEC} ${OBJECT} ${DEPENDS}
