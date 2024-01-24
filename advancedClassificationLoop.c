#include "NumClass.h"

#define true 1
#define false 0

int digitLengthLoop(int);
int powerLoop(int, int);


//finding out if a number is palindrome
int isPalindrome(int num){
    int originalNum = num;
    int reverseNum = 0;

    //Reverse the number
    while(num > 0){
        reverseNum = reverseNum + (num % 10);
        num = num / 10;
    }

    //If the reverses og the number is equals the original number then the number is palindrome
    if(originalNum == reverseNum){
        return true;
    }

    //The number is not palindrome
    return false;
}


//Checking if a number is a armstrong number
int isArmstrong(int num){

    int armstrong = 0;
    int originalNum = num;
    int len = digitLengthLoop(num); //The length of a number

    //While we did not finish
    while(num > 0) {
        armstrong = armstrong + powerLoop(num % 10, len);
        num = num / 10;
    }

    //If the numbers are equals then the number is an armstrong number
    if(armstrong == originalNum){
        return true;
    }

    //The number is not armstrong
    return false;
}

//Calculate the length of a number
int digitLengthLoop(int num){
    int count = 0;

    while (num != 0) {
        num = num / 10;
        count++;
    }

    return count;
}

//Calculate power
int powerLoop(int a, int b){
    int power = 1;
    for(int i = 0; i < b; i++){
        power = power * a;
    }

    return power;
}
