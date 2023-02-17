CC = g++
VERSION = -std=c++11
CXXFLAGS = -Wall -O2
SRCS = *.cpp
OBJS = *.o
TARGETS = *.out

$(TARGETS):
	$(CC) $(VERSION) $(CXXFLACS) $(SRCS) -o $(TARGETS)

-PHONY: clean
clean:
	find . -type f -executable -exec rm '{}' \;

-PHONY: new
new:
	mkdir $(dir);
	cp template.cpp $(dir)/solution.cpp;