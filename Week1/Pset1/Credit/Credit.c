#include <cs50.h>
#include <stdio.h>


int main(void)
{
    long CardNumber = 0;
    int checkSum = 0;
    int ununderlined = 0;
    int count = 0;
    int sum1 = 0;
    int sum2 = 0;

    // Get credit card number
    do
    {
        CardNumber = get_long("Number: ");
    }
    while (CardNumber < 0);

    // Count the length of the credit card number
    long creditCard = CardNumber;
    while (creditCard > 0)
    {
        creditCard = creditCard / 10;
        count++;
    }

    // Check if the length is valid
    if (count != 13 && count != 15 && count != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // A LOOP TO PERFORM THE Luhn’s Algorithm
    long creditCardNumber = CardNumber;
    while (creditCardNumber > 0)
    {

        //TO GET THE VALUE OF THE LAST NUMBER
        int modulo2 = creditCardNumber % 10;
        // TO REMOVE THE LAST NUMBER
        creditCardNumber = creditCardNumber / 10;
        // GET THE VALUE OF THE LAST NUMBER
        int modulo1 = creditCardNumber % 10;
        // MULTIPLY THE VALUE OF THE LAST NUMBER INTO 2
        int product1 = modulo1 * 2;
        // CHECK IF THE PRODUCT IS A TWO DIGIT NUMBER, THEN SPLIT AND ADD
        if (product1 > 9)
        {
            int last = product1 % 10;
            int first = product1 / 10;
            product1 = first + last;
        }
        // ADD THE PRODUCT'S DIGITS TOGETHER
        sum1 = sum1 + product1;
        //REMOVE THE LAST NUMBER
        creditCardNumber = creditCardNumber / 10;
        // ADD THE NUMBERS THAT ARE NOT MULTIPLIED BY 2
        sum2 = sum2 + modulo2;
    }


    checkSum = (sum1 + sum2) % 10;

    // CHECK IF THE CHECKSUM PASSESS THE LUHN'S ALGORITHM
    if (checkSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }

    // GET THE FIRST 2 DIGITS OF THE CARD
    do
    {
        CardNumber = CardNumber / 10;
    }
    while (CardNumber > 100);

    // CHECK IF THE CARD IS A MASTERCARD, VIS OR AMEX
    if ((CardNumber / 10 == 5) && (0 < CardNumber % 10 && CardNumber % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((CardNumber / 10 == 3) && (CardNumber % 10 == 4 || CardNumber % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (CardNumber / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



