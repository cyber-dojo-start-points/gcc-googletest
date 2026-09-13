CXXFLAGS += -I.
CXXFLAGS += -std=c++2a
CXXFLAGS += -Wall -Wextra
CXXFLAGS += -fprofile-arcs -ftest-coverage

CFLAGS += -I.
CFLAGS += -std=c18
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -fprofile-arcs -ftest-coverage

GTEST_LIBS = -lgtest -lgtest_main -pthread

# Files are found at any depth, so a test you put in a sub-directory is
# compiled and run like any other. A shallow glob would leave it out of the
# build entirely, where neither its tests nor its mistakes could be seen.
# The leading ./ that find prints is dropped so a compiler message names
# your file the way you wrote it, as hiker.cpp rather than ./hiker.cpp.
HPP_FILES = $(patsubst ./%,%,$(shell find . -name '*.hpp'))
COMPILED_HPP_FILES = $(patsubst %.hpp,%.compiled_hpp,$(HPP_FILES))
CPP_FILES = $(patsubst ./%,%,$(shell find . -name '*.cpp'))
COMPILED_CPP_FILES = $(patsubst %.cpp,%.o,$(CPP_FILES))

H_FILES = $(patsubst ./%,%,$(shell find . -name '*.h'))
COMPILED_H_FILES = $(patsubst %.h,%.compiled_h,$(H_FILES))
C_FILES = $(patsubst ./%,%,$(shell find . -name '*.c'))
COMPILED_C_FILES = $(patsubst %.c,%.o,$(C_FILES))

.PHONY: test.output
test.output: test makefile
	@./$< --gtest_shuffle

test: $(COMPILED_CPP_FILES) $(COMPILED_C_FILES) $(COMPILED_HPP_FILES)
	@$(CXX) $(CXXFLAGS) -O $(COMPILED_CPP_FILES) $(COMPILED_C_FILES) $(GTEST_LIBS) -o $@

%.o: %.cpp
	@$(CXX) -c $(CXXFLAGS) -O $< -o $@

%.o: %.c
	@$(CC) -c $(CFLAGS) -O $< -o $@

# This rule ensures header files build in their own right.
# The quality of header files is important because header files
# are #included from other files and thus have a large span
# of influence (unlike .cpp files which are not #included)

%.compiled_hpp: %.hpp
	@$(CXX) -x c++ $(CXXFLAGS) -c -o $@ $<

%.compiled_h: %.h
	@$(C) -x c $(CFLAGS) -c -o $@ $<
