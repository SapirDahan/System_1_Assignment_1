#include "NumClass.h"

#define true 1
#define false 0

int digitLengthLoop(int);
int powerLoop(int, int);

int isPalindrome(int num){
    int originalNum = num;
    int reverseNum = 0;

    while(num > 0){
        reverseNum = reverseNum + (num % 10);
        num = num / 10;
    }

    if(originalNum == reverseNum){
        return true;
    }

    return false;
}

int isArmstrong(int num){

    int armstrong = 0;
    int originalNum = num;
    int len = digitLengthLoop(num);

    while(num >=0) {
        armstrong = armstrong + powerLoop(num % 10, len);
        num = num / 10;
    }

    if(armstrong == originalNum){
        return true;
    }

    return false;
}

int digitLengthLoop(int num){
    int count = 0;

    while (num != 0) {
        num = num / 10;
        count++;
    }

    return count;
}

int powerLoop(int a, int b){
    int power = 1;
    for(int i = 0; i < b; i++){
        power = power * a;
    }

    return power;
}
