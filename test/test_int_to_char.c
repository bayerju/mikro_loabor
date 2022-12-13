#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// convert int with multiple digits to char array and write to char array c
int intToChar(int num, char *c) {
    int i = 0;
    int j = 0;
    int temp = num;
    int length = 0;
    while (temp != 0) {
        temp = temp / 10;
        length++;
    }
    for (i = length - 1; i >= 0; i--) {
        c[i] = num % 10 + '0';
        num = num / 10;
    }
    return 0;
}

// concat char array to char array
int concatChar(char *c1, char *c2, char *c3) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (c1[i] != '\0') {
        c3[k] = c1[i];
        i++;
        k++;
    }
    while (c2[j] != '\0') {
        c3[k] = c2[j];
        j++;
        k++;
    }
    return 0;
}



int main(int argc, char** argv) {
    int digit = 8;
    int multiDigits = 215;
    char c [4] = {0};
    intToChar(multiDigits, c);

    char text [4] = "abc";
    char tempText[10] = {0} ;

    concatChar(text, c, tempText);
    return 0;
}