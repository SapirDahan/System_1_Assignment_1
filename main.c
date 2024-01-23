#include <stdio.h>
#include "NumClass.h"

int main() {
    //Get 2 positive numbers from the user
    int num1, num2;

    do {
        printf("Enter two positive integers: ");
        scanf("%d %d", &num1, &num2);
        printf("/n scanf passed");

    } while (num1 <= 0 || num2 <= 0);

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
            printf(" %d", armstrong);
        }
    }
    printf("/n");


    //Find all Palindrome numbers in the range
    printf("The Palindrome numbers are:");
    int palindrome;
    for(int i = num1; i <= num2; i++){
        palindrome = isPalindrome(i);
        if(palindrome){
            printf(" %d", palindrome);
        }
    }
    printf("/n");


    //Find all Prime numbers in the range
    printf("The Prime numbers are:");
    int prime;
    for(int i = num1; i <= num2; i++){
        prime = isPrime(i);
        if(prime){
            printf(" %d", prime);
        }
    }
    printf("/n");


    //Find all Strong numbers in the range
    printf("The Strong numbers are:");
    int strong;
    for(int i = num1; i <= num2; i++){
        strong = isStrong(i);
        if(strong){
            printf(" %d", strong);
        }
    }
    printf("/n");

}
