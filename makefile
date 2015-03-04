CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g
#CXXFLAGS += -03
LDFLAGS = -lboost_date_time

OBJS = assignment.o Fight.o Creature.o Barbarian.o BlueM.o Goblin.o Reptile.o Shadow.o
SRCS = assignment.cpp Fight.cpp Creature.cpp Barbarian.cpp BlueM.cpp Goblin.cpp Reptile.cpp Shadow.cpp
HEADERS = Creature.h Barbarian.h BlueM.h Goblin.h Reptile.h Shadow.h

prog: ${OBJS} ${HEADERS}
	${CXX} ${LDFLAGS} ${OBJS} -o prog

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm -rf *.o prog

