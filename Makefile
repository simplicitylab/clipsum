#
# Parameters
#
UNAME := $(shell uname)
COMPILER=g++
CFLAGS=--std=c++11 -Os
CLIPSUM_EXECUTABLE=clipsum
TEST_EXECUTABLE=test

#
# Compiling CLIpsum
#
all:
	$(COMPILER) src/lorem.cpp src/stringutils.cpp src/nl.cpp src/en.cpp src/es.cpp src/pt.cpp src/de.cpp src/fr.cpp src/it.cpp src/ru.cpp src/main.cpp $(CFLAGS) -o $(CLIPSUM_EXECUTABLE)

#
# Clean
#
clean:
	rm -f $(CLIPSUM_EXECUTABLE) $(TEST_EXECUTABLE)

#
# Install CLIpsum
#
install:
ifeq ($(UNAME), Linux)
	cp $(EXECUTABLE) /usr/local/bin/$(EXECUTABLE)
endif

ifeq ($(UNAME), Darwin)
	cp $(EXECUTABLE) /usr/local/bin/$(EXECUTABLE)
endif

#
# Uninstall CLIpsum
#
uninstall:
ifeq ($(UNAME), Linux)
	rm /usr/local/bin/$(EXECUTABLE)
endif

ifeq ($(UNAME), Darwin)
	rm /usr/local/bin/$(EXECUTABLE)
endif

#
# Unit test
#
test:
	$(COMPILER) $(CFLAGS) src/stringutils.cpp tests/test.cpp -o test
	./test
