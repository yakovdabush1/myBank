CC = gcc
FLAGS = -Wall -g

all:makeBankLibary BankEXE

makeBankLibary:bankLibary.a

bankLibary.a:Bank.o Bank.h
	ar rcs bankLibary.a Bank.o Bank.h

Bank.o:Bank.c Bank.h
	$(CC) $(FLAGS) -fPIC -c Bank.c

main.o:main.c Bank.h
	$(CC) $(FLAGS) -c main.c

BankEXE:main.o bankLibary.a
	$(CC) $(FLAGS) -o BankEXE main.o bankLibary.a 

.PHONY:clean all

clean:
	rm -f *.o *.a *.so BankEXE