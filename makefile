CC = gcc
FLAGS = -Wall -g

all:makeBankLibary BankEXE

makeBankLibary:bankLibary.a

bankLibary.a:myBank.o myBank.h
	ar rcs bankLibary.a myBank.o myBank.h

myBank.o:myBank.c myBank.h
	$(CC) $(FLAGS) -fPIC -c myBank.c

main.o:main.c myBank.h
	$(CC) $(FLAGS) -c main.c

BankEXE:main.o bankLibary.a
	$(CC) $(FLAGS) -o BankEXE main.o bankLibary.a 

.PHONY:clean all

clean:
	rm -f *.o *.a *.so BankEXE
