CC        := g++
SRC_DIR   := ./src
BUILD_DIR := ./build
TEST_DIR  := ./test
GTEST_DIR := ./vendor/googletest

TARGET   := ./bin/racedetect
LIBS     := opencv

SRCEXT   := cpp
SOURCES  := $(shell find $(SRC_DIR) -type f -name *.$(SRCEXT))
OBJECTS  := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS   := -pipe -g -std=c++11 -pthread
LFLAGS   := $(shell pkg-config $(LIBS) --libs) -lboost_filesystem -lboost_system
IFLAGS   := -I . -I vendor $(shell pkg-config $(LIBS) --cflags) -isystem $(GTEST_DIR)/include

TEST_SRC_OBJS := $(BUILD_DIR)/algorithm.o
TEST_OBJS     := $(BUILD_DIR)/algorithm_unittest.o
GTEST_HEADERS := $(GTEST_DIR)/include/gtest/*.h $(GTEST_DIR)/include/gtest/internal/*.h
GTEST_SRCS_   := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $^ -o $(TARGET) $(LFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(SRCEXT)
	$(CC) $(CFLAGS) $(IFLAGS) -c -o $@ $<

tests: algorithm_unittest

clean:
	$(RM) -r $(BUILD_DIR)/* $(TARGET)

$(BUILD_DIR)/gtest-all.o : $(GTEST_SRCS_)
	$(CC) $(IFLAGS) -I$(GTEST_DIR) $(CFLAGS) -c \
		$(GTEST_DIR)/src/gtest-all.cc -o $@

$(BUILD_DIR)/gtest_main.o : $(GTEST_SRCS_)
	$(CC) $(IFLAGS) -I$(GTEST_DIR) $(CFLAGS) -c \
		$(GTEST_DIR)/src/gtest_main.cc -o $@

$(BUILD_DIR)/gtest.a : $(BUILD_DIR)/gtest-all.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/gtest_main.a : $(BUILD_DIR)/gtest-all.o $(BUILD_DIR)/gtest_main.o
	$(AR) $(ARFLAGS) $@ $^

$(BUILD_DIR)/algorithm_unittest.o : $(TEST_DIR)/algorithm_unittest.cpp \
	$(SRC_DIR)/algorithm.h $(GTEST_HEADERS)
	$(CXX) $(IFLAGS) $(CFLAGS) -c $(TEST_DIR)/algorithm_unittest.cpp \
		-o $@

algorithm_unittest : $(TEST_SRC_OBJS) $(TEST_OBJS) $(BUILD_DIR)/gtest_main.a
	$(CC) $^ $(LFLAGS) -o $(BUILD_DIR)/$@
