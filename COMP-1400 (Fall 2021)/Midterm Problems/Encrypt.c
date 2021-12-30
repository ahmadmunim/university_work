#include <stdio.h>

int main(void) {

  puts("Enter a four digit number: ");
  int inputtedNumber;
  scanf("%d", &inputtedNumber);

  int usingInputtedNumber = inputtedNumber;

  int fourthDigitOfInputtedNumber = usingInputtedNumber % 10;
  usingInputtedNumber = usingInputtedNumber / 10;

  int modifiedFourthDigitOfInputtedNumber = (fourthDigitOfInputtedNumber + 7) % 10;

  int thirdDigitOfInputtedNumber = usingInputtedNumber % 10;
  usingInputtedNumber = usingInputtedNumber / 10;

  int modifiedThirdDigitOfInputtedNumber = (thirdDigitOfInputtedNumber + 7) % 10;

  int secondDigitOfInputtedNumber = usingInputtedNumber % 10;
  usingInputtedNumber = usingInputtedNumber / 10;

  int modifiedSecondDigitOfInputtedNumber = (secondDigitOfInputtedNumber + 7) % 10;

  int firstDigitOfInputtedNumber = usingInputtedNumber % 10;
  usingInputtedNumber = usingInputtedNumber / 10;

  int modifiedFirstDigitOfInputtedNumber = (firstDigitOfInputtedNumber + 7) % 10;

  int firstDigitOfEncryptedInteger = modifiedThirdDigitOfInputtedNumber;

  int secondDigitOfEncryptedInteger = modifiedFourthDigitOfInputtedNumber;

  int thirdDigitOfEncryptedInteger = modifiedFirstDigitOfInputtedNumber;

  int fourthDigitOfEncryptedInteger = modifiedSecondDigitOfInputtedNumber;

  int encryptedInteger = 0;
  
  encryptedInteger =  encryptedInteger * 10 + firstDigitOfEncryptedInteger;
  
  encryptedInteger =  encryptedInteger * 10 + secondDigitOfEncryptedInteger;

  encryptedInteger =  encryptedInteger * 10 + thirdDigitOfEncryptedInteger;

  encryptedInteger =  encryptedInteger * 10 + fourthDigitOfEncryptedInteger;

  printf("Data (%d) encrypted to %d", inputtedNumber, encryptedInteger);


}