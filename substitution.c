#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[]) {

if (argc == 1) {

    printf("Usage: ./substitution key\n");
}
else if (strlen(argv[1]) != 26) {
        printf("Key must contain 26 characters.\n");
    }
    else {
        string plaintext = get_string("plaintext: ");
    }
}


