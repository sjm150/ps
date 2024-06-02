CC = g++
VERSION = -std=c++2a
FLAGS = -Wall -O2
TARGETS = a a1 a2 b b1 b2 c c1 c2 d d1 d2 e e1 e2 f f1 f2 g g1 g2 h h1 h2

.SECONDEXPANSION:
$(TARGETS): $$@.cpp
	$(CC) $(VERSION) $(FLAGS) $< -o $@

-PHONY: clean
clean:
	rm -rf $$(ls | grep -v .cpp | grep -v Makefile)

-PHONY: done
done: clean
	rm template.cpp Makefile
	git add *.cpp
