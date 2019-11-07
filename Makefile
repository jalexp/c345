
INCL=/Users/pagoda/cpp-workspace/boost_1_71_0
LIBDIR=/Users/pagoda/cpp-workspace/boost_1_71_0/stage/lib
LIBS=boost_filesystem

CCFLAGS=-c -I $(INCL) 
OBJFILES=gameengine.o gameenginedriver.o map.o mapparser.o cards.o player.o dice.o
SRCFILES=dice.cpp player.cpp map.cpp mapparser.cpp cards.cpp gameengine.cpp gameenginedriver.cpp

all: game

game: $(OBJFILES)
	g++ $(OBJFILES) -L $(LIBDIR) -l $(LIBS) -o gameengine

$(OBJFILES): $(SRCFILES)
	g++ $(CCFLAGS) $(SRCFILES)
