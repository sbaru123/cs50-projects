#include <cs50.h>
#include <stdio.h>

int main(void)
{

int getLastDigit(long int number);
int getLastDigitNew(long int number);
long int card = get_long("Card: ");
int sum = 0;
int lastDigit = 0;
int leftOver = 0;
long int cardOG = card;
string name = "";
int index = 0;

if (card / 10000000000000 == 34 || card / 10000000000000 == 37) {
  name = "AMEX";
  index = 17;
}
else if (card / 1000000000000000 == 4 ) {
  name = "VISA";
  index = 18;
}
else if (card / 1000000000000 == 4) {
  name = "VISA";
  index = 15;
}
else if (card / 100000000000000 == 51 || card / 100000000000000 == 52 || card / 100000000000000 == 53 || card / 100000000000000 == 54 || card / 100000000000000 == 55) {
  name = "MASTERCARD";
  index = 18;
}
else {
  name = "INVALID\n";
  index = 20;
}

//printf("Name: %s\n" , name);

for (int i = 0; i < index; i += 2) {

    lastDigit = getLastDigit(card);
    card /= 10;
    lastDigit = lastDigit * 2;

       leftOver = lastDigit % 10;
       lastDigit = lastDigit / 10;

   // printf("lastDigit: %d\n" , lastDigit);
  // printf("leftOver: %d\n" , leftOver);
    sum = sum + lastDigit + leftOver;
    card /= 10;
    }
//printf("Sum: %d\n" , sum);

for (int j = 0; j < index; j+=2){
  lastDigit = getLastDigitNew(cardOG);
  sum = sum + lastDigit;
  cardOG /= 100;
}
//printf("Total Sum: %d\n" , sum);

if (sum % 10 == 0) {
      printf("%s\n" , name);
}
else
  {
      printf("INVALID\n");
  }
}

int getLastDigit(long int number)
{
    int rem = 0;
    number = number / 10;
    rem = number % 10;
  // printf("Remainder: %d\n" , rem);
    return rem;
}

int getLastDigitNew(long int number)
{
    int rem = 0;
    rem = number % 10;
   //printf("Remainder: %d\n" , rem);
    return rem;
}
