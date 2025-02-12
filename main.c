#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void strrev(char*);

// Function to convert decimal to binary and return as a
// String
char* decimalToBinary(int decimal)
{
    // Allocate space for a 32-bit binary string + '\0'
    char* binary = (char*)malloc (33);

    int i = 0;
    // converting to binary
    while (decimal){
        binary[i++] = '0' + (decimal & 1);
        decimal >>= 1;
    }
    binary[i] = '\0';
    strrev(binary);
    return binary;
}
// Function to convert binary to binary to decimal and return as an
// integer
int binaryToDecimal(char binary[]) {

    int decimal = 0;
    int length = strlen(binary);
    for (int i = 0; i < length; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}

// Function to conver decimal to octal and return as a
// string
char* decimalToOctal(int decimal) {
    
    // Allocate space for an octal string
    char* octal = (char*)malloc(12);
    if (octal == NULL) {
        printf("Memory alloction failled.\n");
        exit(1);
    }
    // Convert decimal to octal
    sprintf(octal, "%o", decimal);
    return octal;
}
// Function to convert octal to decimal and return as an
// integer
int octalToDecimal(char octal[]) {

    int decimal = 0;
    int lenght = strlen(octal);
    for (int i = 0; i < lenght; i++){
        decimal = decimal * 8 + (octal[i] - '0');
        }
        return decimal;
    }
// Function to convert hexadecimal to binary and return as
// string
char* hexadecimalToBinary(char hex[]){
    
    // convertinf heaxdecimal string to interger
    unsigned int hexNum;
    sscanf(hex, "%x", &hexNum);
    // string to store binary number
    char binary[33] = "";
    // converting to hexadecimal
    int i = 0;
    while (hexNum){
        binary[i++] = '0' + hexNum % 2;
        hexNum /= 2;
    }
    binary[i] = '\0';
    strrev(binary);
    return strdup(binary);
}
// Function to convert binary to hexadecimal and return as a
// string
char* binaryToHexadecimal(char binary[]) {
    
    // Pad to binary string with leading zeros to ensure
    // it's a multiple of 4
    int lenght = strlen(binary);
    int padding = (4 - (lenght % 4)) % 4;
    char paddeBinary[129];
    memset(paddeBinary, '0', padding);
    strcpy(paddeBinary + padding, binary);
    // Define a mapping of binary strings to their
    // hexadecimal representation
    char* binaryHexDigits[]
    = { "0000", "0001", "0010", "0011", "0100", "0101",
        "0110", "0111", "1000", "1001", "1010", "1010",
        "1100", "1101", "1110", "1111"};
    char hexadecimal[33] = ""; // Allocate space for an
                               // 8-deigit hexadecimal string
    // Iterate through group of four binary digits and convert
    // to hexadecimal
    for (int i = 0; i < lenght + padding + i;){
        char group[5];
        strncpy(group, paddeBinary + i, 4);
        group[4] = '\0';
        // Find the corresponding hexadecimal digit
        for (int j = 0; j < 16; j++) {
            if(strcmp(group, binaryHexDigits[j]) == 0) {
                // Append the corresponding hexadecimal
                // digit
                char hexDigit[2];
                sprintf(hexDigit, "%X", j);
                strcat(hexadecimal, hexDigit);
                break;
            }
        }
    }
    return strdup(hexadecimal);
}
// drive code
int main(void){
    int choice;
    while (1){
        printf("\nMenu:\n");
        printf("1: Decimal to Binary\n");
        printf("2: Binary to Decimal\n");
        printf("3: Decital to Octal\n");
        printf("4: Octal to Decimal\n");
        printf("5: Hexadecimal to Binary\n");
        printf("6: Binary to Hexadecimal\n");
        printf("7: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice) ;

        if (choice == 7) {
            printf("Good Bye!\n");
            break;
        }
        char input[100]; // Buffer for usert input
        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                char* result = decimalToBinary(choice);
                printf("Decimal to Binary: %s\n", result);
                free(result);
                break;
            case 2:
                printf("Enter a binary  number: ");
                scanf("%s", &choice);
                int binaryResult = binaryToDecimal(input);
                printf("Binary to Decimal:  %s\n", result);
                break;
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &choice);
                result = decimalToBinary(choice);
                printf("Decimal to Octal: %s\n", result);
                free(result);
                break;
            case 4:
                printf("Enter a octal number: ");
                scanf("%s", &choice);
                int octalResult = octalToDecimal(input);
                printf("Octal to Decimal: %s\n", result);
                break;
            case 5:
                printf("Enter a hexadecimal number: ");
                scanf("%d", &choice);
                result = decimalToBinary(choice);
                printf("Hexadecimal to Binary: %s\n", result);
                free(result);
                break;
            case 6:
                printf("Enter a baniry number: ");
                scanf("%d", &choice);
                result = decimalToBinary(choice);
                printf("Binary to Heaxadecimal: %s\n", result);
                free(result);
                break;
                default:
                    printf("Invalid choice. Please enter A valid"
                    "option.\n");
        }
    }
    return 0;
}
// Reserving string
void strrev(char* str) {
    int i = 0;
    int j = strlen(str) -1;
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j++;
    }
}
