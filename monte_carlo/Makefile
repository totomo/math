#Makefile for monte carlo
CC = gcc
LIBS = -lm
EXE = estpi
OBJS = estpi.o
SRC = calcurate_pi.c
$(EXE):	$(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(EXE)
$(OBJS): $(SRC)
	$(CC) $(LIBS) -c $(SRC) -o $(OBJS)
clean:
	rm -rf \#* \~* $(OBJS) $(EXE)
