CC = g++
VERSION = -std=c++17
CXXFLAGS = -Wall -O2
SRCS = *.cpp
OBJS = *.o
TARGETS = *.out

$(TARGETS):
	$(CC) $(VERSION) $(CXXFLACS) $(SRCS) -o $(TARGETS)

-PHONY: clean
clean:
	find . -type f -executable -exec rm '{}' \;
