all:
	g++ src/lorem.cpp src/stringutils.cpp src/nl.cpp src/en.cpp src/es.cpp src/de.cpp src/fr.cpp src/main.cpp --std=c++11 -Os -o clipsum
