#include <stdio.h>
#include <stdlib.h>

int bitshifter(int *dataPoints) {
    int i;
    *dataPoints = 0;
    for (i = 0; i < 8; i++) {

       *dataPoints = *dataPoints | 1;
    }
    return 0;
}

int bitshifterSelf(int *dataPoints) {
    int i;
    for (i = 0; i < 8; i++) {
       dataPoints[i] = 1;
    }
    return 0;
}

int main(int argc, char** argv) {
    printf("Hello world!");
    int result[8] = {0};
    bitshifterSelf(result);

    return (0);
}