#include <iostream>
#include <cmath>
#include <cstdlib>

int getUserInput()
{
	std::cout << "Please enter an integer: ";
	int value;
	std::cin >> value;
	return value;
}

int getMathematicalOperation()
{
	std::cout << "Please enter which operator you want (1 = +, 2 = -, 3 = *, 4 = /): ";
	int op;
	std::cin >> op;
	return op;
}

int calculateResult(int x, int op, int y)
{
	// Comments!

	if (op == 1)
		return x + y;
	if (op == 2)
		return x - y;
	if (op == 3)
		return x * y;
	if (op == 4)
		return x / y;

	return -1; // default "error" value in case user passed in an invalid op
}

void printResult(int result)
{
	std::cout << "Your result is: " << result << std::endl;
}

void additionalTests()
{
	int power = pow(2, 3);
	printResult(power);

	int exponential = exp(5);
	printResult(exponential);

	int logarithm = log(5);
	printResult(logarithm);

	int floorMethod = floor(5.4);
	printResult(floorMethod);

	int modulo = 7 % 5;
	printResult(modulo);

	if ((7 >= 5) && (9 == 10)) {
		printResult(1);
	}
	else if ((5 < 8) || (9 != 12)) {
		printResult(2);
	}
	else {
		printResult(3);
	}

	switch (5) {
	case 1:
		printResult(1);
		break;
	case 3:
		printResult(3);
		break;
	case 5:
		printResult(5);
		break;
	}

	for (int i = 0; i < 5; i++) {
		printResult(i);
	}

	int number = 0;

	while (number < 5) {
		printResult(number);
		number += 1;
	}

	int number2 = 0;

	do {
		printResult(number2);
		number2 += 1;
	} while (number2 < 5);

	int arrayPractice[10];
	arrayPractice[5] = 20;
	arrayPractice[8] = 30;
	printResult(arrayPractice[5]);

	int multiArrayPractice[10][10];
	multiArrayPractice[2][3] = 25;
	multiArrayPractice[7][8] = 45;
	printResult(multiArrayPractice[7][8]);
}

int main()
{
	//Run additional tests
	additionalTests();

	// Get first number from user
	int input1 = getUserInput();

	// Get mathematical operation from user
	int op = getMathematicalOperation();

	// Get second number from user
	int input2 = getUserInput();

	// Calculate result and store in temporary variable (for readability/debug-ability)
	int result = calculateResult(input1, op, input2);

	// Print result
	printResult(result);
}
