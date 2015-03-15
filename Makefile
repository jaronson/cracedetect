CC        := g++
SRC_DIR   := src
BUILD_DIR := build

TEST_DIR  := test
GTEST_DIR := vendor/googletest

TARGET   := bin/racedetect
LIBS     := opencv

SRCEXT   := cpp
SOURCES  := $(shell find $(SRC_DIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS   := -pipe -g -std=c++11 -pthread
LFLAGS   := $(shell pkg-config $(LIBS) --libs) -lboost_filesystem -lboost_system
IFLAGS   := -I . -I vendor $(shell pkg-config $(LIBS) --cflags) -isystem $(GTEST_DIR)/include

TEST_SRCS     := $(SRC_DIR)/algorithm.h
TEST_SRC_OBJS := $(BUILD_DIR)/algorithm.o
TEST_OBJS     := $(patsubst $(TEST_DIR)/%,$(BUILD_DIR)/%,$(TESTS:.cpp=.o))
GTEST_SRCS_   := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

$(TARGET) : $(OBJECTS)
	@echo " Linking ..."
	@echo "$(CC) $^ -o $(TARGET) $(LFLAGS)"; $(CC) $^ -o $(TARGET) $(LFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRCEXT)
	@echo " $(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<"; $(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

tests: algorithm_unittest

clean:
	@echo " Cleaning ..."
	@echo " $(RM) -r $(BUILD_DIR)/* $(TARGET) $(TESTS)"; $(RM) -r $(BUILD_DIR)/* $(TARGET)

$(BUILD_DIR)/gtest-all.o : $(GTEST_SRCS_)
	$(CC) $(IFLAGS) -I$(GTEST_DIR) $(CFLAGS) -c $(GTEST_DIR)/src/gtest-all.cc -o $@

$(BUILD_DIR)/gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(IFLAGS) -I$(GTEST_DIR) $(CFLAGS) -c $(GTEST_DIR)/src/gtest_main.cc -o $@

$(BUILD_DIR)/gtest.a : $(BUILD_DIR)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/gtest_main.a : $(BUILD_DIR)/gtest-all.o $(BUILD_DIR)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(TEST_OBJS) : $(TEST_SRCS) $(TEST_SRC_OBJS) $(GTEST_HEADERS)
	$(CC) $(IFLAGS) $(CFLAGS) -c $@ $<

algorithm_unittest : $(TEST_SRC_OBJS) $(TEST_OBJS) $(BUILD_DIR)/gtest_main.a
	$(CC) $^ $(LFLAGS) -o $(BUILD_DIR)/$@
