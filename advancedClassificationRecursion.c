#include "NumClass.h"

#define true 1
#define false 0

int isArmstrongNum(int num, int index, int len);
int digitLengthRec(int);
int powerRec(int, int);

int isPalindrome(int num){

    int len = digitLengthRec(num);
    int mostSignificantDigit = num / powerRec(10, len - 1);
    int lessSignificantDigit = num % 10;
    if(mostSignificantDigit == lessSignificantDigit){
        isPalindrome(num - mostSignificantDigit * powerRec(10, len - 1) - lessSignificantDigit);
    }
    return false;
}

int isArmstrong(int num){

    int len = digitLengthRec(num);
    int result = isArmstrongNum(num, 0, len);

    if(num == result){
        return true;
    }

    return false;
}

int isArmstrongNum(int num, int index, int len){
    if(index == len){
        return 0;
    }
    return isArmstrongNum(num/10, index + 1, len) + powerRec(num % 10, len);
}

int digitLengthRec(int num){
    int count = 0;

    while (num != 0) {
        num = num / 10;
        count++;
    }

    return count;
}

int powerRec(int a, int b){
    int power = 1;
    for(int i = 0; i < b; i++){
        power = power * a;
    }

    return power;
}
