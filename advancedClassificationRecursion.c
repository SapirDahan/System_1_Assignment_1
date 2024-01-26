#include "NumClass.h"

#define true 1
#define false 0

int isArmstrongNum(int, int, int);
int isPalindromeChecker(int, int, int);
int digitAtLocation(int, int);
int digitLengthRec(int);
int powerRec(int, int);

//Checking if the number is palindrome
int isPalindrome(int num){
    return isPalindromeChecker(num, 0, digitLengthRec(num) - 1);
}

//Help to find if a function is a palindrome
int isPalindromeChecker(int num, int right, int left){

    //Checking if we finished
    if(left <= right){
        return true;
    }

    //Checking if the edges of the numbers are equals
    if(digitAtLocation(num, right) == digitAtLocation(num, left)){
        return isPalindromeChecker(num, right + 1, left - 1);
    }

    //The number is not a palindrome
    else{
        return false;
    }

}

//Finds the digit at a location in a number
int digitAtLocation(int num, int index){
    return (num / powerRec(10, index)) % 10;
}

//Checking if the number is an armstrong number
int isArmstrong(int num){

    int len = digitLengthRec(num); // The length of the number
    int result = isArmstrongNum(num, 0, len); //The result of the recursion

    //If the number is equals to the original number the number is an armstrong number
    if(num == result){
        return true;
    }

    //The number is not armstrong
    return false;
}

//The recursion the calculate if armstrong number
int isArmstrongNum(int num, int index, int len){

    //Checking if we finished
    if(index == len){
        return 0;
    }

    //Continue calculate if armstrong
    return isArmstrongNum(num/10, index + 1, len) + powerRec(num % 10, len);
}

//Calculate the number of digits of a number
int digitLengthRec(int num){
    int count = 0;

    while (num != 0) {
        num = num / 10;
        count++;
    }

    return count;
}

//Calculate power
int powerRec(int a, int b){
    int power = 1;
    for(int i = 0; i < b; i++){
        power = power * a;
    }

    return power;
}
