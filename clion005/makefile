CCC=\g++
CCFLAGS=-g -std=c++11 -pedantic -Wall -Wextra

game : main.o equipment.o game.o game_state.o goal.o gold.o level.o monster.o movable.o object.o player.o potion.o treasure.o wall.o
	$(CCC) $(CCFLAGS) main.o equipment.o game.o game_state.o goal.o gold.o level.o monster.o movable.o object.o player.o potion.o treasure.o wall.o -lsfml-window -lsfml-graphics -lsfml-system -o "game"

main.o : main.cpp
	$(CCC) $(CCFLAGS) -c main.cpp

equipment.o : equipment.cpp
	$(CCC) $(CCFLAGS) -c equipment.cpp

game.o : game.cpp
	$(CCC) $(CCFLAGS) -c game.cpp

game_state.o : game_state.cpp
	$(CCC) $(CCFLAGS) -c game_state.cpp

goal.o : goal.cpp
	$(CCC) $(CCFLAGS) -c goal.cpp

gold.o : gold.cpp
	$(CCC) $(CCFLAGS) -c gold.cpp

level.o : level.cpp
	$(CCC) $(CCFLAGS) -c level.cpp

monster.o : monster.cc
	$(CCC) $(CCFLAGS) -c monster.cc

movable.o : movable.cc
	$(CCC) $(CCFLAGS) -c movable.cc

object.o : object.cc
	$(CCC) $(CCFLAGS) -c object.cc

player.o : player.cc
	$(CCC) $(CCFLAGS) -c player.cc

potion.o : potion.cpp
	$(CCC) $(CCFLAGS) -c potion.cpp

treasure.o : treasure.cpp
	$(CCC) $(CCFLAGS) -c treasure.cpp

wall.o : wall.cpp
	$(CCC) $(CCFLAGS) -c wall.cpp