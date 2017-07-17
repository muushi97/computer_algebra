CXX  = g++
CXXFLAGS    = -std=c++14 -static
INCLUDE   = -I./header
TARGETS   = run.exe
TARGETDIR = ./
SRCDIR   = ./source
OBJDIRS   = ./object
SOURCES   = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS   = $(subst $(SRCDIR),$(OBJDIRS), $(SOURCES:.cpp=.o))

$(TARGETS): $(OBJECTS)
	$(CXX) -o $(TARGETDIR)$@ $^ $(CXXFLAGS)

$(OBJDIRS)/%.o: $(SRCDIR)/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) $(INCLUDE)

$(OBJDIRS)/%.o: $(INCLUDE)/%.hpp

run: $(TARGETS)
	$(TARGETDIR)$(TARGETS)

all: clear $(TARGETS)

clear:
	rm $(TARGETDIR)$(TARGETS)
	rm $(OBJDIRS)/*.o
