#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main (int argc, string argv[]) {

if (argc != 2) {

    printf("Usage: ./substitution key\n");
}
else if (strlen(argv[1]) != 26) {
        printf("Key must contain 26 characters.\n");
    }
    else {
        string plaintext = get_string("plaintext: ");
    }
    string key = argv[1];
    printf("%s" , encrypt(plaintext , key));
}

string encrypt (string text , string key) {

    

}


