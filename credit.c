#include <cs50.h>
#include <stdio.h>
#include <math.h>


int main(void)
{
    long cardNumber = get_long("Number: ");;


    int validCount = 0;
    long digits = cardNumber;
    do
    {
        digits = digits / 10; //as this is a base ten number dividing it by 10 will shave off one digit at a time, then add to the count
        validCount++;
    }
    while (digits > 0); //repeat this process till there are no more digits

    if (validCount != 13 && validCount != 15 && validCount != 16) //checks that card is the correct amount of digits
    {
        printf("INVALID\n");
       
        return 0;

    }
    // now that we have checked if the number is the correct size and doesnt have unwanted characters we can use the luhn algorithm and figure out the card type

    //luhn algorithm steps to verify that the card is valid:
    // 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together
    // 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
    // 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid

    int sum1 = 0;
    int sum2 = 0;
    long Number = cardNumber; //the user input is now Number
    int module1;
    int module2;
    int digit1;
    int digit2;
    int total = 0;

    do
    {

        module1 = Number % 10; //last digit is taken off and stored in module1
        Number = Number / 10; //last digit is cut off total number
        sum1 = sum1 + module1; //last digit stored in module1 is added to sum1

        module2 = Number % 10; //second last number is taken off and added to module2
        Number = Number / 10;//second last number is taken off total number

        module2 = module2 * 2; //as per step 1 every other digit, which will be stored in module2 is multiplied by 2
        digit1 = module2 % 10; 
        digit2 = module2 / 10; //to take and add every singular digit use module to find last digit of the number, and divide by 10 to find the first. the most digits there can be is two
        
        sum2 = sum2 + digit1 + digit2; //add all digits to sum2

    }
    while (Number > 0); //continue until no more digits

    total = sum1 + sum2;

    if (total % 10 != 0) //if module 10 does not equal zero this card is invalid
    {
        printf("INVALID\n");
        return 0;
    }
    //the last step is to figure out the type of card

    long firstTwo = cardNumber; //user innput is now firstTwo (first two numbers)
    do
    {
        firstTwo = firstTwo / 10;
    }
    while (firstTwo > 100); //cuts off each number until the first two are remaining

    if ((firstTwo / 10 == 5) && (0 < firstTwo % 10 && firstTwo % 10 < 6)) //Mastercard starts with 51, 52, 53, 54, or 55
    {
        printf("MASTERCARD\n");
    }
    else if ((firstTwo / 10 == 3) && (firstTwo % 10 == 4 || firstTwo % 10 == 7)) //American Express numbers start with 34 or 37
    {
        printf("AMEX\n");
    }
    else if (firstTwo / 10 == 4) //Visa numbers start with 4
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }


}
