PREFIX = $(HOME)
LIB_DIR = $(PREFIX)/lib
INC_DIR = $(PREFIX)/include

LIB_SUFFIX = _20

OBJS = main.o MMDD_to_Doy.o input.o Gen_IRI.o combine_IRI.o f10_7.o
HEADERS = Gen_Ne.h

OPTS = -O3 -Wall

all: main

main: $(OBJS)
main: $(OBJS)
	g++ -o $@ $(OBJS) -Wl,-R$(LIB_DIR) -L$(LIB_DIR) -liri2016$(LIB_SUFFIX) -lsolardirection -lgfortran

%.o: %.cpp $(HEADERS)
	g++ -c $< $(OPTS) -I$(INC_DIR)

clean:
	rm -rf main *.o

.PHONY: all clean
