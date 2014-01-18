#Makefile for monte carlo
CC = gcc
LIBS = -lm
EXE = estpi
OBJS = estpi.o
SRC = calcurate_pi.c
SAMPLENUM = 10000
$(EXE):	$(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(EXE)
$(OBJS): $(SRC)
	$(CC) $(LIBS) -c $(SRC) -o $(OBJS)
clean:
	rm -rf \#* \~* $(OBJS) $(EXE)
run:
	./$(EXE) $(SAMPLENUM)
