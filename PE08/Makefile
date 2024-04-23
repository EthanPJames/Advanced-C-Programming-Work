##
## Makefile 
##

## Define compiler

CC	= gcc

## Define flags

CFLAGS	= -std=c99 -Wall -Wshadow -Werror -Wvla -g -pedantic -fstack-protector-strong --param ssp-buffer-size=1

## if you want to compile with the -O3 flag, comment the preceding CFLAGS and 
## uncomment the following CFLAGS

# CFLAGS	= -std=c99 -Wall -Wshadow -Werror -Wvla -O3 -pedantic -fstack-protector-strong --param ssp-buffer-size=1

## Build rule to build executable, by default, pe01 is build since it 
## is the label of the first rule

pe09: pe09.o answer09.o 
	$(CC) $(CFLAGS) pe09.c answer09.c -o pe09

## rule to test with argument option 0


## rule to test with argument option 1



##memory: pe09
##	valgrind --log-file=log0.txt ./pe099 0 inputfile
##	valgrind --log-file=log1.txt ./pe01 1 inputfile

## rule to clean up object files and executable so that you can rebuild

clean:	
	rm -f pe09.o answer09.o pe09

## rule to compile .c to .o

%.o: %.c
	$(CC) $(CFLAGS) -c $< 
