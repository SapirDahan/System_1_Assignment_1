Num = NumClass.h
CFLAGS = -Wall -fPIC
CC = gcc

.PHONY: all clean
all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a
recursives: libclassrec.a
recursived: libclassrec.so
loopd: libclassloops.so

basicClassification.o: basicClassification.c $(Num)
	$(CC) $(CFLAGS) -c basicClassification.c -o basicClassification.o

advancedClassificationLoop.o: advancedClassificationLoop.c $(Num)
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -o advancedClassificationLoop.o

advancedClassificationRecursion.o: advancedClassificationRecursion.c $(Num)
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion.o

libclassloops.a: basicClassification.o advancedClassificationLoop.o
	ar -rcs libclassloops.a basicClassification.o advancedClassificationLoop.o

libclassrec.a: basicClassification.o advancedClassificationRecursion.o
	ar -rcs libclassrec.a basicClassification.o advancedClassificationRecursion.o

libclassrec.so: basicClassification.o advancedClassificationRecursion.o
	$(CC) -shared -fPIC -o libclassrec.so basicClassification.o advancedClassificationRecursion.o

libclassloops.so: basicClassification.o advancedClassificationLoop.o
	$(CC) -shared -fPIC -o libclassloops.so basicClassification.o advancedClassificationLoop.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a

maindloop: main.o libclassloops.so
	$(CC) $(CFLAGS) -o maindloop main.o -lclassloops -L. -Wl,-rpath=$(shell pwd)

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o -lclassrec -L. -Wl,-rpath=$(shell pwd)

clean:
	rm -f mains maindloop maindrec *.o *.a *.so