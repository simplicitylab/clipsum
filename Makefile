#
# Parameters
#
UNAME := $(shell uname)
CFLAGS= --std=c++11 -Os
EXECUTABLE=clipsum

#
# Compiling CLIpsum
#
all:
	g++ src/lorem.cpp src/stringutils.cpp src/nl.cpp src/en.cpp src/es.cpp src/de.cpp src/fr.cpp src/main.cpp $(CFLAGS) -o $(EXECUTABLE)

#
# Clean
#
clean:
	rm $(EXECUTABLE)

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
