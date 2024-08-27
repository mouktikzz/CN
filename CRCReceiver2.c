#include <stdio.h>
#include <string.h>

int xor(int, int);

int main() {
    int remainder[10], data[20], divisor[10];
    int dataLength, divisorLength, i, j;
    
    printf("Enter the length of the received codeword (data + CRC bits): ");
    scanf("%d", &dataLength);
    
    printf("Enter the received codeword: ");
    for (i = 0; i < dataLength; i++) {
        scanf("%d", &data[i]);
    }
    
    printf("Enter the length of the generator key: ");
    scanf("%d", &divisorLength);
    
    printf("Enter the generator key: ");
    for (j = 0; j < divisorLength; j++) {
        scanf("%d", &divisor[j]);
        remainder[j] = data[j];
    }
    
    for (i = divisorLength; i < dataLength + 1; i++) {
        for (j = 0; j < divisorLength - 1; j++) {
            remainder[j] = xor(remainder[j + 1], divisor[j + 1] * remainder[0]);
        }
        if (i < dataLength) {
            remainder[j] = data[i];
        }
    }
    
    // Check if the remainder is all zeros
    int errorDetected = 0;
    for (j = 0; j < (divisorLength - 1); j++) {
        if (remainder[j] != 0) {
            errorDetected = 1;
            break;
        }
    }
    
    if (errorDetected) {
        printf("Error detected in the received data.\n");
    } else {
        printf("No error detected in the received data.\n");
    }
    
    return 0;
}

int xor(int a, int b) {
    return a == b ? 0 : 1;
}
