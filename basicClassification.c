#include "NumClass.h"

#define true 1
#define false 0

int factorial(int);
int square(int);
static int digitLength(int);

int isPrime(int num){
    if(num == 1){
        return true;
    }

    for(int i = 2; i <= square(num); i++){
        if(num % i == 0){
            return false;
        }
    }
    return true;
}


int isStrong(int num){

    int strong = 0;
    int originalNum = num;

    for(int i = 0; i < digitLength(num); i++){
        strong = strong + factorial(num % 10);
        num = num / 10;
    }

    if(strong == originalNum){
        return true;
    }

    return false;
}

//Gives the square of a number or the natural number above the closest to the square
int square(int num) {
    int i;
    for (i = 1; i <= num; i++) {
        if (i * i >= num) {
            return i;
        }
    }

    //Will not happen because if num is positive then a number that equals or move the original number exist
    return 0;
}


int factorial(int num){

    int sum = 1;
    for(int i = 1; i <= num; i++){
        sum = sum * i;
    }

    return sum;
}

static int digitLength(int num){
    int count = 0;

    while (num != 0) {
        num = num / 10;
        count++;
    }

    return count;
}


