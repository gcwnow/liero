CXX := /opt/gcw0-toolchain/usr/bin/mipsel-linux-g++
MACHINE := $(shell $(CXX) -dumpmachine)
SYSROOT := $(shell $(CXX) -print-sysroot)
CXXFLAGS := -ffunction-sections -ffast-math -fsingle-precision-constant
CXXFLAGS += $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)
LIBS := $(shell $(SYSROOT)/usr/bin/sdl-config --libs) -lSDL_mixer

OUTDIR := output/$(MACHINE)

ifneq ($(filter mipsel-gcw0-%,$(MACHINE)),)
CXXFLAGS += -mips32 -mtune=mips32 -mbranch-likely -G0
endif

CXXFLAGS += -Wextra -Wall
ifdef DEBUG
	CXXFLAGS += -ggdb3
	OUTDIR := $(OUTDIR)-debug
else
	CXXFLAGS += -O2 -fomit-frame-pointer
	LDFLAGS += -s
endif

CXXFLAGS += -DHOME_DIR

BINDIR := $(OUTDIR)/bin
OBJDIR := $(OUTDIR)/obj

SRC := $(wildcard *.cpp)
OBJ := $(SRC:%.cpp=$(OBJDIR)/%.o)
EXE := $(BINDIR)/liero

.PHONY: all clean

all : $(SRC) $(EXE)

$(EXE): $(OBJ) | $(BINDIR)
	$(CXX) $(LDFLAGS) $(OBJ) $(LIBS) -o $@

$(OBJ): $(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(BINDIR) $(OBJDIR):
	mkdir -p $@

clean:
	rm -rf output
