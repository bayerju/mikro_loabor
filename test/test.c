#include <stdio.h>
#include <stdlib.h>

int set_bit(int num, int position)
{
	int mask = 1 << position;
	return num | mask;
}


int main(int argc, char** argv) {
    
int checksum = 0;
int data[40] = {0};
int i = 0;
while(1) {
    checksum = set_bit(checksum, i);
    i++;
}

    return (0);
}