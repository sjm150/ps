CC = g++
VERSION = -std=c++2a
FLAGS = -Wall -O2
TARGETS = solution

.SECONDEXPANSION:
$(TARGETS): $$@.cpp
	$(CC) $(VERSION) $(FLAGS) $< -o $@

-PHONY: clean
clean:
	rm -r $$(ls | grep -v .cpp | grep -v Makefile)

-PHONY: done
done: clean
	rm Makefile
	git add *.cpp
