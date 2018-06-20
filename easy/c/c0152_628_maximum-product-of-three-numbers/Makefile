#------------------------------------------------------------------------------
# Top Makefile
# Tue Jan 16 12:51:33 HKT 2018
# drunk water
#------------------------------------------------------------------------------

CC=gcc
CFLAGS=-Wall
LDFLAGS :=
LIBS := -lm -lpthread


PRG=app_elf
OBJ=00_leetcode_0152.o

$(PRG):$(OBJ)
	$(CC) -o $@ $(OBJ) $(INC) $(LIB)

.SUFFIXES: .c .o .cpp
.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp -o $*.o $(LDFLAGS) $(LIBS)

.PRONY:clean
clean:
	@echo "start to make clean"
	rm -f $(OBJ) $(PRG)