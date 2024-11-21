# Make file.

OBJS	= opovMain.o TrainerImp.o GameImp.o  
CC		= g++
CCFLAGS	= -Wall -Wextra -pedantic -std=c++11 -g

DEPS	= Pokemon.h Trainer.h Game.h     

all: main

main: $(OBJS)
	$(CC) $(CCFLAGS) -o ast6Main $(OBJS)

main.o:	opovMain.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c opovMain.cpp

TrainerImp.o: TrainerImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c TrainerImp.cpp

GameImp.o: GameImp.cpp $(DEPS)
	$(CC) $(CCFLAGS) -c GameImp.cpp


# -----
# clean by removing object files.

clean:
	rm $(OBJS) ast6Main
	
