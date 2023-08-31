#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

//defines the function that completes problem 1
void calculator(){
	//the following two print statements provide context for how to use the calculator to user.
	printf("\nWelcome to the calculator. You will first enter a number, then an operation (+,-,*, or /) and then another number.");
	printf("\nPlease enter a operation (i.e enter '3 + 3'): ");

	//the following two lines define three variables to use in calculator
	float num1, num2;
	char op;

	//the following line reads in two floats for the numbers and a character inbetween the floats to signify the operation
	scanf("%f %c %f", &num1, &op, &num2);

	//clears the input buffer of newline characters
	while ((getchar()) != '\n');

	//defines a variable used to store the result
	float result;
	
	//the following begins a switch statement which takes in the char for the operation and selects how to calculate and print result.
	switch (op){

		//case statement for the addition operator
		case '+':

			//the following 3 lines	calculates the result from addition, prints it, and breaks from switch statement
			result = num1 + num2;
			printf("Result is %f\n  ", result);
			break; 

		//case statement for the subtraction operator  
		case '-':

			//the following 3 lines	calculates the result from subtraction, prints it, and breaks from switch statement
			result = num1 - num2;
			printf("Result is %f\n", result);
			break;   

		//case statement for the multiplication operator
		case '*':

			//the following 3 lines	calculates the result from multiplication, prints it, and breaks from switch statement
			result = num1 * num2;
			printf("Result is %f\n", result);
			break; 

		//case statement for the division operator  
		case '/':

			//the following 3 lines	calculates the result from division, prints it, and breaks from switch statement
			result = num1 / num2;
			printf("Result is %f\n", result);
			break;  
		//provides definition if the operator is incorrect
		default:
			
			//the following two lines print telling the user they input an invalid operator and then breaks from switch statement
			printf("Invalid operation %c", op);
			break; 
	}
          
}

//defines a function solving the second problem
void heightCategorize(){
	//defines a float to store height from user
    float height;

	//the following two lines ask the user for their height and then stores it in a float
    printf("Please enter your height in centimeters: ");
    scanf("%f", &height);

	//clears the input buffer of newline characters
	while ((getchar()) != '\n');

	//if statement to categorize the user
    if (height < 168.0){
		//if height is less than 168, print telling the user they are short
        printf("\nYou are short!");
    }
    else if (height < 178.0){
		//if the height is greater than 168 and less than 178, print telling the user they are average height
        printf("\nYou are average height");
    }
    else {
		//if the height is greater than 178, print telling user they are very tall
        printf("\nYou are very tall!");
    }   
}

//defines a function solving the third problem
void createPrimes(){
	//defines a int to store the limit set by the user
    int limit;

	//the following two lines ask the user for the limit and then store it as an int
    printf("\nPlease enter the upper limit of the list of primes: ");
    scanf("%d", &limit);
	
	//clears the input buffer of newline characters
	while ((getchar()) != '\n');	

	//print marking the beginning of the list of primes
    printf("\nList of primes is: ");
	
	//defines a boolean that will act as a flag marking that a number is a prime
    bool isPrime;

	//start a loop that will iterate from 2 until the limit set by the user
    for (int i = 2; i <= limit; i++){
		//sets isPrime to true. It will be set to false later in another loop that will attempt to prove the current num (i) is divisible by a number besides itself and 1. 
		//if isPrime is true after that loop, then the number (i) is confirmed as a prime.
        isPrime = true;

		//begins a for loop that iterates from 2 until the sqrt of the current num (i). This works because a number (n1) is not prime if it is divisible by a number >= 2 or <= sqrt of n1
        for (int j = 2; j <= sqrt(i); j++){
			//if the current num is divisible by another number n such that 2<= n <= sqrt(i)
            if (i % j == 0){
				//set isPrime to false
                isPrime = false;

				//break from the loop
                break;
            }   
        }
		//check if the current number is prime
        if (isPrime){
			//print the current number
            printf("%d ",i); 
        }
    }
	//print newline character to make output easier to read
    printf(" \n");
}

//defines solution to part of problem 4
void convertToBinary(){
	//the following two lines define the hexadecimal value that will be read in and a int to store the hexadecimal number as a decimal number
    char hexIn[10000];
	int decimalVal;

	//The following two lines asks for a hexadecimal value and stores it as hexIn
	printf("\nEnter a hexadecimal number: ");
	scanf("%s", hexIn);
	
	//clears the input buffer of newline characters
	while ((getchar()) != '\n');

	//confirms the hex value read in to the user
	printf("\nHex read in as: %s\n", hexIn);

	//defines an int that represents the current value of the hexadecimal value, and an int to store what digit the current digit is(for equation to convert hex to decimal)
	int curVal = 0, iterator = 0;

	//for loop that iterates through every digit in the hexadecimal input, starting from the rightmost/leastsignificant bit
	for (int i = strlen(hexIn) - 1; i >= 0; i--){
		//converts current digit to lowercase
		hexIn[i] = tolower(hexIn[i]);
	
		//defines switch statement that will determine what the value of curVal based on the value of the cur hexadecimal value.
		switch (hexIn[i]){
			//the following three lines are a case that will perform the logic 'if hex val is 0, set the current value to 0 and then break'
			case '0':
				curVal = 0;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 1, set the current value to 1 and then break'
			case '1':
				curVal = 1;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 2, set the current value to 2 and then break'
			case '2':
				curVal = 2;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 3, set the current value to 3 and then break'
			case '3':
				curVal = 3;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 4, set the current value to 4 and then break'
			case '4':
				curVal = 4;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 5, set the current value to 5 and then break'
			case '5':
				curVal = 5;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 6, set the current value to 6 and then break'
			case '6':
				curVal = 6;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 7, set the current value to 7 and then break'
			case '7':
				curVal = 7;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 8, set the current value to 8 and then break'
			case '8':
				curVal = 8;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is 9, set the current value to 9 and then break'
			case '9':
				curVal = 9;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is a, set the current value to 10 and then break'
			case 'a':
				curVal = 10;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is b, set the current value to 11 and then break'
			case 'b':
				curVal = 11;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is c, set the current value to 12 and then break'
			case 'c':
				curVal = 12;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is d, set the current value to 13 and then break'
			case 'd':
				curVal = 13;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is e, set the current value to 14 and then break'
			case 'e':
				curVal = 14;
				break;
			//the following three lines are a case that will perform the logic 'if hex val is f, set the current value to 15 and then break'
			case 'f':
				curVal = 15;
				break;
		}
		//add the cur val multiplies by 16 to the power of the location of the current digit to the decimal value, as by the formula for hex to decimal
		decimalVal = decimalVal + (curVal * pow(16, iterator));
		//add 1 to the int representing the location of the current digit
		iterator = iterator + 1;
	}
	//print the decimal value of the hex input, and print the decimal value as a binary number using %b
	printf("\nDecimal val: %d, Binary value : %b\n", decimalVal, decimalVal);
}

//defines part of the solution to problem 4
void convertToHex(){
	//defines a var that stores binary input and the decimal value that will be represented.
	int binaryIn, decimalVal = 0;

	//the following two lines ask for the binary number and store it in binaryIn
	printf("\nEnter a binary num: ");
	scanf("%d", &binaryIn);

	//clears the input buffer of newline characters
	while ((getchar()) != '\n');
	
	//confirms that the binary value was read in correctly
	printf("\nBinary val read in %d: ", binaryIn);

	//defines a var that stores the cur binary digit and the location of the digit as a number
	int curDigit, placeVal = 0;
	
	//begins a while loop while binaryIn is not 0
	while (binaryIn != 0){
		//grab the rightmost digit of the binary num using modulo operator
		curDigit = binaryIn % 10;
		
		//add the curDigit multiplied by 2 to the power of the location of the digit to the decimal value, as per the formula for binary to hex
		decimalVal = decimalVal + (curDigit * pow(2,placeVal));

		//increase the number representing location of current digit by 1
		placeVal = placeVal + 1;

		//removes the rightmost digit from the var storing the binary number
		binaryIn = binaryIn/10;
	}
	
	//prints the decimal value represented by the binary input and then prints that value as a hexadecimal number using %x
	printf("\nDecimal val: %d, Hexadecimal value : %x\n", decimalVal, decimalVal);
   
}

//defines whole solution to problem 4
void conversion(){
	//defines a char to store the input from user 	
	char in;

	//the following two lines ask the user if they want to convert from binary or from hex and stores it in a variable
	printf("\nEnter b if you want to convert from binary or h if you want to convert from hexadecimal: ");
	
	//stores input in in var
	scanf("%c", &in);

	//clears the input buffer of newline characters
	while ((getchar()) != '\n');

	//converts in to a lowercase version of itself
	in = tolower(in);

	//begins switch statement that determines which function to run
	switch (in){
		//defines case if user input b or B
		case 'b':
			//runs convertToHex function that will handle this use-case
			convertToHex();
	
			//break from switch
			break;
		case 'h':
			//runs convertToBinary function that will handle this use-case
			convertToBinary();
	
			//break from switch
			break;
		default:
			//print indicating the user entered wrong input
			printf("Incorrect input!");

			//break from switch
			break;
	}
}

//defines a function that is part of the solution to problem 5
int duplicates(int nums[], size_t length){
	//intializes a var representing number of duplicates as 0
	int duplicates = 0;

	//creates an array of same length as input array. This array will store the locations of duplicates that have already been counted, so they aren't counted twice
	int skips[length];

	//creates boolean flag representing if the current element has a duplicate (will cause the number of duplicates to be increased by 1)
	bool hasDupe = false;
	
	//creates a for loop that iterates through each index in the input array
	for (int i = 0; i < length; i++){
		//set boolean flag to false (current element doesnt have a duplicate
		hasDupe = false;
		
		//creates another for loop that iterates through each index in the input array again, starting 1 after the current index
		for (int j = i+1; j < length; j++){
			//if the current element of the first loop is the same as the current element of the second loop AND the current element of the second loop wasn't already counted 
			//as a duplicate, run the code inside
			if (nums[i] == nums[j] && skips[j] != 1){
				//set the boolean flag to true (the current element of the first loop is a duplicate)
				hasDupe = true;

				//increase int storing the number of duplicates
				duplicates++;

				//mark that the current index had been counted as a duplicate
				skips[j] = 1;
			}
		}
		//if the current element of the first loop has a duplicate, run the following
		//exists so that if the current element is the first of its kind, it is also counted as a duplicate
		if (hasDupe){
			//increase int storing the numbre of duplicates
			duplicates++;
		}
	}
	//return the number of duplicates
	return duplicates;
}

//defines solution to problem 5
void dupeProblem(){
	//initialize a list of numbers
	int nums[] = {1,1,1,3,2,1,3,4,2,2,2};

	//defines an unsigned long int representing the length of nums by getting the size of nums and dividing it by the size of each element (all elements have the same size)
	size_t length = sizeof(nums)/sizeof(nums[0]);
	
	//print statement marking beginning of array
	printf("\nArray is: {");

	//starts a for loop that will iterate through each index of nums
	for (int i = 0; i < length; i++){
		//print the current element of nums
		printf(" %d ", nums[i]);
	}
	//print statement marking the ending of the array
	printf("}\n");

	//print indicating the number of duplicates
	printf("Duplicates are %d\n", duplicates(nums, length));
}

//defines a function that is part of the solution to problem 6
int getLength(char *p){
	//initializes a number representing the length as 0
	int length  = 0;

	//starts a while loop which will end once pointer representing the element length spaces away from start is the end character of a string
	while (*(p+length) != '\0'){
		//increases length to get closer to end of string
		length = length + 1;
	}

	//returns length
	return length;
}

//defines function with whole solution to problem 6
void lengthProblem(){
	//defines a variable to store user input
	char in[1000];

	//the following two lines ask the user for a string to obtain the length of and then stores that string
	printf("\nPlease enter a string: ");
	scanf("%s", in);
	
	//clears the input buffer of newline characters
	while ((getchar()) != '\n');
	
	//print statement returning length of entered string
	printf("\nThe length of %s is %d\n", in, getLength(in));
}

//defines the function that solves problem 7
void calculatorExtended(){
	//the following two lines define how to use the calculator will be used by the user
	printf("\nWelcome to the calculator. You will first enter a number, then an operation (+,-,*,/,^, sqrt, ceil, or floor) (NOTE:don't enter a second num for sqrt, ceil, or floor) and then another number.");
	printf("\nPlease enter a operation (i.e enter '3 + 3', '3 ^ 2', '4 sqrt'): ");

	//creates two vars that will store the numbers and the operation
	float num1, num2;
	char op;

	//obtains the numbers and operator entered by the user. num 2 will become 0 if the user enters sqrt, ceil, or floor and op will become the first letter of word input (s for sqrt, c for ceil, f for floor)
	scanf("%f %c %f", &num1, &op, &num2);

	//clears the input buffer of newline characters
	while ((getchar()) != '\n');
	

	//defines a float that will store the result
	float result;

	//creates a switch statement which will compare the char operator to the cases.
	switch (op){
		//case statement for addition operator
		case '+':
			//the following three lines will store result of addition, print the result, and break from the case statement
			result = num1 + num2;
			printf("Result is %f\n  ", result);
			break;   

		//case statement for subtraction operator
		case '-':
			//the following three lines will store result of subtraction, print the result, and break from the case statement
			result = num1 - num2;
			printf("Result is %f\n", result);
			break;   

		//case statement for multiplication operator
		case '*':
			//the following three lines will store result of multiplication, print the result, and break from the case statement
			result = num1 * num2;
			printf("Result is %f\n", result);
			break;   

		//case statement for division operator
		case '/':
			//the following three lines will store result of division, print the result, and break from the case statement
			result = num1 / num2;
			printf("Result is %f\n", result);
			break; 

		//case statement for square root operator
		case 's':
			//the following three lines will store result of square root, print the result, and break from the case statement
			result = sqrt(num1);
			printf("Result is %f\n  ", result);
			break;   

		//case statement for ceiling operator
		case 'c':
			//the following three lines will store result of ceiling, print the result, and break from the case statement
			result = ceil(num1);
			printf("Result is %f\n", result);
			break;   

		//case statement for floor operator
		case 'f':
			//the following three lines will store result of floor, print the result, and break from the case statement
		   result = floor(num1);
		   printf("Result is %f\n", result);
			break;

		//case statement for power operator
		case '^':
			//the following three lines will store result of the power operation, print the result, and break from the case statement
			result = pow(num1, num2);
			printf("Result is %f\n", result);
			break;   

		//case statement for invalid operator
		default:
			//the following two lines will print to the user that their input was incorrect and break from the case statement
			printf("Invalid operation %c", op);
			break; 
	}

}

//defines main function that will run the other functions in the file that solve each problem
int main(){
	//creates a var to store user input 
	char input;
	//begins a while loop that will not end until the user enters 'exit'
	while (true){
		//the following two lines tell the user how to enter input, asks them for input, and then stores that input
		printf("\nEnter your choice for problem to solve (1 for problem 1, 2 for problem 2, ... , 7 for problem 7, exit to exit: \n");
		scanf("%c", &input);

		//clears the input buffer of newline characters
		while ((getchar()) != '\n');

		//begins a switch statement with input
		switch (input){
			//the following three lines handle if the user entered 1, run the program for problem 1, and breaks
			case '1':
				calculator();
				break;

			//the following three lines handle if the user entered 2, run the program for problem 2, and breaks
			case '2':
				heightCategorize();
				break;

			//the following three lines handle if the user entered 3, run the program for problem 3, and breaks
			case '3':
				createPrimes();
				break;

			//the following three lines handle if the user entered 4, run the program for problem 4, and breaks
			case '4':
				conversion();
				break;

			//the following three lines handle if the user entered 5, run the program for problem 5, and breaks
			case '5':
				dupeProblem();
				break;

			//the following three lines handle if the user entered 6, run the program for problem 6, and breaks
			case '6':
				lengthProblem();
				break;

			//the following three lines handle if the user entered 7, run the program for problem 7, and breaks
			case '7':
				calculatorExtended();
				break;

			//the following two lines handle if the user entered exit and exits the main file
			case 'e':
				return(0);

			//the following three lines handle if the user entered non-accepted input, tells the user they entered bas input, and breaks
			default:
				printf("Invalid input!");
				break;
		}
	}
}
