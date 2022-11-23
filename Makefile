c=gcc
op=-Wall -Wextra -lpthread

all : exe

exe : tube.o exemple.c
	@$(c) -o exemple.o -c exemple.c $(op)
	@$(c) -o exe tube.o exemple.o $(op)

tube.o : tube.c lib.h
	@$(c) -o tube.o -c tube.c $(op)
	
clean :
	@rm -f exe
	rm -f tube.o exemple.o exe
