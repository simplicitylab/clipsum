UNAME := $(shell uname)
CFLAGS= --std=c++11 -Os
EXECUTABLE=clipsum

all:
	g++ src/lorem.cpp src/stringutils.cpp src/nl.cpp src/en.cpp src/es.cpp src/de.cpp src/fr.cpp src/main.cpp $(CFLAGS) -o $(EXECUTABLE)

clean:
	rm $(EXECUTABLE)

install:
ifeq ($(UNAME), Linux)

endif

ifeq ($(UNAME), Darwin)
	cp $(EXECUTABLE) /usr/local/bin/$(EXECUTABLE)
endif

uninstall:
ifeq ($(UNAME), Linux)

endif

ifeq ($(UNAME), Darwin)
	rm /usr/local/bin/$(EXECUTABLE)
endif
