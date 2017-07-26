CXX = g++-5
CXXFLAGS = -std=c++14 -Wall -Werror=vla -MMD
EXEC = a4q2b
OBJECTS = main.o textdisplay.o subject.o cell.o grid.o graphicsDisplay.o window.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC} -lX11

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}

