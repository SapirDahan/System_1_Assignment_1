#include <stdio.h>
#include "NumClass.h"

int main() {

    //Get 2 positive numbers from the user
    int num1, num2;

    //Request 2 numbers from the user 2 positive numbers
    //printf("Enter two positive integers: ");
    scanf("%d %d", &num1, &num2);

    //If the two numbers are negatives
    if(num1 <= 0 && num2 <= 0){
        printf("The Armstrong numbers are:\n");
        printf("The Palindromes are:\n");
        printf("The Prime numbers are:\n");
        printf("The Strong numbers are:\n");
        return 0;
    }

    //If 1 of the numbers is negative
    if(num1 <= 0){
        num1 = 1;
    }

    if(num2 <= 0){
        num2 = 1;
    }


    //Make sure that num2 is not bigger then num1
    if(num1 > num2){
        int tmp = num1;
        num1 = num2;
        num2 = tmp;
    }

    //Find all Armstrong numbers in the range
    printf("The Armstrong numbers are:");
    int armstrong;
    for(int i = num1; i <= num2; i++){
        armstrong = isArmstrong(i);
        if(armstrong){
            printf(" %d", i);
        }
    }
    printf("\n");


    //Find all Palindrome numbers in the range
    printf("The Palindromes are:");
    int palindrome;
    for(int i = num1; i <= num2; i++){
        palindrome = isPalindrome(i);
        if(palindrome){
            printf(" %d", i);
        }
    }
    printf("\n");


    //Find all Prime numbers in the range
    printf("The Prime numbers are:");
    int prime;
    for(int i = num1; i <= num2; i++){
        prime = isPrime(i);
        if(prime){
            printf(" %d", i);
        }
    }
    printf("\n");


    //Find all Strong numbers in the range
    printf("The Strong numbers are:");
    int strong;
    for(int i = num1; i <= num2; i++){
        strong = isStrong(i);
        if(strong){
            printf(" %d", i);
        }
    }
    printf("\n");

    return 0;

}
