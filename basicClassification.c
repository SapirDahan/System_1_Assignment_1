#include "NumClass.h"

//Define true and false
#define true 1
#define false 0

//Help functions
int factorial(int);
int square(int);
int digitLength(int);

//Checking if the number is 1 or 2 then return true (in this assigment 1 is prime)
int isPrime(int num){
    if(num == 1 || num == 2){
        return true;
    }

    //Checking if the number is dividing from any of the numbers between 2 and the square of the numbers
    for(int i = 2; i <= square(num); i++){

        //If dividing return false
        if(num % i == 0){
            return false;
        }
    }

    //The number is prime
    return true;
}


int isStrong(int num){

    int strong = 0; //Initialize strong
    int originalNum = num; //Save the original number

    //For each digit in num calculate the factorial of it and add to strong
    int digitLen = digitLength(num);
    for(int i = 0; i < digitLen; i++){
        strong = strong + factorial(num % 10);
        num = num / 10;
    }

    //If strong equals to the original number the number is strong
    if(strong == originalNum){
        return true;
    }

    //The number is not strong
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

//Calculate the factorial of a number
int factorial(int num){

    int sum = 1;
    for(int i = 1; i <= num; i++){
        sum = sum * i;
    }

    return sum;
}

//Calculate lhe length of the number
int digitLength(int num){
    int count = 0;

    while (num != 0) {
        num = num / 10;
        count++;
    }

    return count;
}


