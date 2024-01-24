Num = NumClass.h
CFLAGS = -Wall
gcc = CC

all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so mains mainloops maindrec
.PHONY: all clean

basicClassification_static.o: basicClassification.c $(Num)
	$(CC) $(CFLAGS) -c basicClassification.c -o basicClassification_static.o

advancedClassificationLoop_static.o: advancedClassificationLoop.c $(Num)
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c -o advancedClassificationLoop_static.o

advancedClassificationRecursion_static.o: advancedClassificationRecursion.c $(Num)
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion_static.o

libclassloops.a: basicClassification_static.o advancedClassificationLoop_static.o
	ar rcs libclassloops.a basicClassification_static.o advancedClassificationLoop_static.o

libclassrec.a: basicClassification_static.o advancedClassificationRecursion_static.o
	ar rcs libclassrec.a basicClassification_static.o advancedClassificationRecursion_static.o

basicClassification_dynamic.o: basicClassification.c $(Num)
	$(CC) -fPIC $(CFLAGS) -c basicClassification.c -o basicClassification_dynamic.o

advancedClassificationRecursion_dynamic.o: advancedClassificationRecursion.c $(Num)
	$(CC) -fPIC $(CFLAGS) -c advancedClassificationRecursion.c -o advancedClassificationRecursion_dynamic.o

advancedClassificationLoop_dynamic.o: advancedClassificationLoop.c $(Num)
	$(CC) -fPIC $(CFLAGS) -c advancedClassificationLoop.c -o advancedClassificationLoop_dynamic.o

libclassrec.so: basicClassification_dynamic.o advancedClassificationRecursion_dynamic.o
	$(CC) -shared -o libclassrec.so basicClassification_dynamic.o advancedClassificationRecursion_dynamic.o

libclassloops.so: basicClassification_dynamic.o advancedClassificationLoop_dynamic.o
	$(CC) -shared -o libclassloops.so basicClassification_dynamic.o advancedClassificationLoop_dynamic.o

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

mains: main.o libclassrec.a
	$(CC) $(CFLAGS) -o mains main.o libclassrec.a

mainloops: main.o libclassloops.so
	$(CC) $(CFLAGS) -o mainloops main.o -lclassloops -L. -Wl,-rpath=$(shell pwd)

maindrec: main.o libclassrec.so
	$(CC) $(CFLAGS) -o maindrec main.o -lclassrec -L. -Wl,-rpath=$(shell pwd)

clean:
	rm -f mains mainloops maindrec *.o *.a *.so