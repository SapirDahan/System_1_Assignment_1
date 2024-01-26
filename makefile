Num = NumClass.h
CFLAGS = -Wall
gcc = CC

all: loops recursives recursived loopd mains maindloop maindrec
.PHONY: all clean

basicClassification_static.o: basicClassification.c $(Num)
	$(CC) $(CFLAGS) -c basicClassification.c -o basicClassification_static.o

advancedClassificationLoop_static.o: advancedClassificationLoop.c $(Num)
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -o advancedClassificationLoop_static.o

advancedClassificationRecursion_static.o: advancedClassificationRecursion.c $(Num)
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion_static.o

loops: basicClassification_static.o advancedClassificationLoop_static.o
	ar rcs libclassloops.a basicClassification_static.o advancedClassificationLoop_static.o

recursives: basicClassification_static.o advancedClassificationRecursion_static.o
	ar rcs libclassrec.a basicClassification_static.o advancedClassificationRecursion_static.o

basicClassification_dynamic.o: basicClassification.c $(Num)
	$(CC) -fPIC $(CFLAGS) -c basicClassification.c -o basicClassification_dynamic.o

advancedClassificationRecursion_dynamic.o: advancedClassificationRecursion.c $(Num)
	$(CC) -fPIC $(CFLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion_dynamic.o

advancedClassificationLoop_dynamic.o: advancedClassificationLoop.c $(Num)
	$(CC) -fPIC $(CFLAGS) -c advancedClassificationLoop.c -o advancedClassificationLoop_dynamic.o

recursived: basicClassification_dynamic.o advancedClassificationRecursion_dynamic.o
	$(CC) -shared -fPIC -o libclassrec.so basicClassification_dynamic.o advancedClassificationRecursion_dynamic.o

loopd: basicClassification_dynamic.o advancedClassificationLoop_dynamic.o
	$(CC) -shared -fPIC -o libclassloops.so basicClassification_dynamic.o advancedClassificationLoop_dynamic.o

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