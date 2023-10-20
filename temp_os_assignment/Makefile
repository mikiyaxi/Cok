CPPFLAGS = -g -I.

libsrc = print_generation.cpp
libobj = $(libsrc:.cpp=.o)
headers = 

all: generations

generations: generations.o $(libobj) $(headers)
	$(CXX) -g -o $@ generations.o $(libobj) $(LDFLAGS)

print_generations.o : print_generation.cpp
	$(CXX) -c -g -o $@ print_generation.cpp

.PHONY: clean
clean:
	rm -f generations generations.o $(libobj)
