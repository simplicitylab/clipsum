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
	$(COMPILER) src/text/lorem.cpp  src/text/nl.cpp src/text/en.cpp src/text/es.cpp src/text/pt.cpp src/text/de.cpp src/text/fr.cpp src/text/it.cpp src/text/se.cpp  src/text/ru.cpp src/text/no.cpp src/text/fi.cpp src/text/dk.cpp src/stringutils.cpp src/main.cpp $(CFLAGS) -o $(CLIPSUM_EXECUTABLE)

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
	cp $(CLIPSUM_EXECUTABLE) /usr/local/bin/$(CLIPSUM_EXECUTABLE)
endif

ifeq ($(UNAME), Darwin)
	cp $(CLIPSUM_EXECUTABLE) /usr/local/bin/$(CLIPSUM_EXECUTABLE)
endif

#
# Uninstall CLIpsum
#
uninstall:
ifeq ($(UNAME), Linux)
	rm /usr/local/bin/$(CLIPSUM_EXECUTABLE)
endif

ifeq ($(UNAME), Darwin)
	rm /usr/local/bin/$(CLIPSUM_EXECUTABLE)
endif

#
# Unit test
#
test:
	$(COMPILER) $(CFLAGS) src/stringutils.cpp tests/test.cpp -o test
	./test
