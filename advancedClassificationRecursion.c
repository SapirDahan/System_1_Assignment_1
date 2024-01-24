#include "NumClass.h"

#define true 1
#define false 0

int isArmstrongNum(int num, int index, int len);
int digitLengthRec(int);
int powerRec(int, int);

int isPalindrome(int num){

    //If num is 0 we finish successfully the recursion
    if(num == 0){
        return true;
    }

    int len = digitLengthRec(num); // The length of the number
    int mostSignificantDigit = num / powerRec(10, len - 1);
    int lessSignificantDigit = num % 10;

    //The number is the same in its edges of the number
    if(mostSignificantDigit == lessSignificantDigit){
         return isPalindrome((num - mostSignificantDigit * powerRec(10, len - 1))/10);
    }

    //The number is not palindrome
    else{
        return false;
    }
}

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
