CC       := g++
SRCDIR   := src
BUILDDIR := build
TARGET   := bin/racedetect
LIBS     := opencv

SRCEXT   := cpp
SOURCES  := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS   := -pipe -g -std=c++11
LFLAGS   := $(shell pkg-config $(LIBS) --libs)
IFLAGS   := -I include -I vendor $(shell pkg-config $(LIBS) --cflags)

$(TARGET) : $(OBJECTS)
	@echo " Linking ..."
	@echo "$(CC) $^ -o $(TARGET) $(LFLAGS)"; $(CC) $^ -o $(TARGET) $(LFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo " $(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<"; $(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

clean:
	@echo " Cleaning ..."
	@echo " $(RM) -r $(BUILDDIR)/* $(TARGET)"; $(RM) -r $(BUILDDIR)/* $(TARGET)
