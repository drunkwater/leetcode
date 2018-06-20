#------------------------------------------------------------------------------
# Top Makefile
# Tue Jan 16 12:51:33 HKT 2018
# drunk water
#------------------------------------------------------------------------------

CPP=g++
CPPFLAGS=-Wall
LDFLAGS :=
LIBS := -lm


PRG=app_elf
OBJ=00_leetcode_0346.o

$(PRG):$(OBJ)
	$(CPP) -o $@ $(OBJ) $(INC) $(LIB)

.SUFFIXES: .c .o .cpp
.cpp.o:
	$(CPP) $(CPPFLAGS) -c $*.cpp -o $*.o $(LDFLAGS) $(LIBS)

.PRONY:clean
clean:
	@echo "start to make clean"
	rm -f $(OBJ) $(PRG)
