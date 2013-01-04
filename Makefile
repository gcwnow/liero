TOOLCHAIN = /opt/gcw0-toolchain
CXX = $(TOOLCHAIN)/usr/bin/mipsel-linux-g++
STRIP = $(TOOLCHAIN)/usr/bin/mipsel-linux-strip
CXXFLAGS = -mips32 -mtune=mips32 -G0 -fomit-frame-pointer -ffunction-sections -ffast-math -fsingle-precision-constant -mbranch-likely
INCLUDE = -I$(TOOLCHAIN)/usr/mipsel-gcw0-linux-uclibc/sysroot/usr/include/ -I$(TOOLCHAIN)/usr/mipsel-gcw0-linux-uclibc/sysroot/usr/include/SDL
LIB = -lSDL_mixer -lSDL -lpthread

ifdef DEBUG
	CXXFLAGS += -Wextra -Wall -ggdb3 -c
else
	CXXFLAGS += -c -O2
endif

SRC = 	blit.cpp	\
	bobject.cpp	\
	bonus.cpp	\
	console.cpp	\
	constants.cpp	\
	filesystem.cpp	\
	font.cpp	\
	game.cpp	\
	gfx.cpp		\
	keys.cpp	\
	level.cpp	\
	main.cpp	\
	math.cpp	\
	menu.cpp	\
	ninjarope.cpp	\
	nobject.cpp	\
	rand.cpp	\
	reader.cpp	\
	sdlmain.cpp	\
	settings.cpp	\
	sfx.cpp		\
	sobject.cpp	\
	sys.cpp		\
	text.cpp	\
	viewport.cpp	\
	weapon.cpp	\
	weapsel.cpp	\
	worm.cpp
OBJ = $(SRC:.cpp=.o)
EXE = liero.elf

all : $(SRC) $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(LDFLAGS) $(OBJ) $(LIB) -o $@
ifndef DEBUG
	$(STRIP) $(EXE)
endif

.cpp.o:
	$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -rf *.o $(EXE)
