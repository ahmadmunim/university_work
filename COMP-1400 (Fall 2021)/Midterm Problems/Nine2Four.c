#include <stdio.h>

int main(void) {

  int counter = 1;
  
  puts("Enter your 9-digit student ID: ");
  int studentID;
  scanf("%d", &studentID);

  int usingStudentID = studentID;
  
  int rightFirstDigit;
  int rightSecondDigit;
  int rightThirdDigit;

  int l = 0;
  int m = 0;
  int r = 0;
  int i = 0;
  int digit = 0;
  int straightR = 0;
  int straightM = 0;
  int straightL = 0;

  while (counter < 4) {
    i = usingStudentID % 10;
    r = r * 10 + i;   
    usingStudentID = usingStudentID / 10; 
    counter++; 
  }

  while (r != 0) {
    digit = r % 10;
    straightR = straightR * 10 + digit;
    r = r / 10;
  }

  counter = 1;
  i = 0;
  digit = 0;

  while (counter < 4) {
    i = usingStudentID % 10; 
    m = m * 10 + i;
    usingStudentID = usingStudentID / 10; 
    counter++; 
  }

  while (m != 0) {
    digit = m % 10;
    straightM = straightM * 10 + digit;
    m = m / 10;
  }

  counter = 1;
  i = 0;
  digit = 0;

  while (counter < 4) {
    i = usingStudentID % 10; 
    l = l * 10 + i;
    usingStudentID = usingStudentID / 10; 
    counter++; 
  }

  while (l != 0) {
    digit = l % 10;
    straightL = straightL * 10 + digit;
    l = l / 10;
  }

  int sum1 = 0;
  counter = 1;
  digit = 0;
  int usingStraightR = straightR;

  while (counter < 4) {
    digit = usingStraightR % 10;
    sum1 = sum1 + digit;
    usingStraightR = usingStraightR / 10;
    counter++;
  }

  while (sum1 > 9) {
    sum1 = sum1%10 + sum1/10;
  }

  int sum2 = 0;
  counter = 1;
  digit = 0;
  int usingStraightM = straightM;

  while (counter < 4) {
    digit = usingStraightM % 10;
    sum2 = sum2 + digit;
    usingStraightM = usingStraightM / 10;
    counter++;
  }

  while (sum2 > 9) {
    sum2 = sum2%10 + sum2/10;
  }

  int sum3 = 0;
  counter = 1;
  digit = 0;
  int usingStraightL = straightL;

  while (counter < 4) {
    digit = usingStraightL % 10;
    sum3 = sum3 + digit;
    usingStraightL = usingStraightL / 10;
    counter++;
  }

  while (sum3 > 9) {
    sum3 = sum3%10 + sum3/10;
  }

  int s = 0;
  counter = 1;
  digit = 0;
  
  while (counter < 4) {
    digit = usingStraightL % 10;
    s = sum1 + sum2 + sum3;
    usingStraightL = usingStraightL / 10;
    counter++;
  }

  while (s > 9) {
    s = s%10 + s/10;
  }

  int hash = sum2 * 1000 + s*100 + sum3 * 10 + sum1;
  printf("The hash value of your ID(%d) is %d", studentID, hash);





  

}