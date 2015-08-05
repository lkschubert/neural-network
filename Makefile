#Default Makefile

COMPILER = g++

TARGET = neural-network
SRCDIR = ./source
BUILDDIR = ./build

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRC))

all : $(OBJ)
	$(COMPILER) -o $(TARGET) $^


$(BUILDDIR)/%.o : $(SRCDIR)/%.cpp
	$(COMPILER) -c -o $@ $<

clean: 
	rm build/* $(TARGET)

