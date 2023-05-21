#include <iostream>
#include "Stack.h"


/*Ввести некоторое число и записать его цифры в стек.Вывести
число, у которого цифры идут в обратном порядке.Цифры из
записи числа считывать поочередно(например, с помощью
getch()).Вычислить наименьшую и наибольшую цифры в записи
числа.*/

void selectStack(stack& q1, stack& q2, stack& chosenStack, int& tmp2)
{
	while (true)
	{
		printf_s("Enter stack number: ");
		scanf_s("%d", &tmp2);
		if (tmp2 == 1)
		{
			chosenStack = q1;
			break;
		}
		if (tmp2 == 2)
		{
			chosenStack = q2;
			break;
		}
		printf_s("Invalid value.\n");
	}
}

void assignStack(stack& q1, stack& q2, stack& chosenStack, int& tmp2)
{
	if (tmp2 == 1)
		q1 = chosenStack;

	if (tmp2 == 2)
		q2 = chosenStack;
}

void loopStack()
{
	stack myStack1;
	stack myStack2;
	stack chosenStack;
	int choice = 0;
	bool flag = 1;
	int max = -1, min = 10;
	int tmp = 0, index = 0, tmp2 = 0;

	while (flag)
	{

		printf_s("0 - Exit \n1 - Add element \n2 - Delete element \n3 - Clear stack \n4 - Atach stack \n5 - Clone stack in reverse order \n\
6 - Insert element \n7 - Removed choosen element \n8 - Check stack size \n9 - Look at stack \n");
		printf_s("Your choice: ");
		scanf_s("%d", &choice);
		tmp2 = 0;



		switch (choice)
		{
		case 0:
			flag = 0;
			break;

		case 1:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			printf_s("Enter your element: ");
			scanf_s("%d", &tmp);
			pushStack(chosenStack, tmp);
			assignStack(myStack1, myStack2, chosenStack, tmp2);
			break;

		case 2:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			if (pullStack(chosenStack) == INT_MAX)
				printf_s("Your stack is empty.\n");
			assignStack(myStack1, myStack2, chosenStack, tmp2);
			break;
		
		case 3:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			freeStack(chosenStack);
			assignStack(myStack1, myStack2, chosenStack, tmp2);
			break;

		case 4:
			atachStack(myStack1, myStack2);
			break;

		case 5:
			max = -1, min = 10;
			while (getchar() != '\n');
			printf_s("Enter your number: ");
			while ((tmp = getchar()) != '\n')
			{
				tmp -= '0';
				if (tmp > max)
					max = tmp;
				if (tmp < min)
					min = tmp;
				pushStack(myStack1, tmp);
			}
			if (max != -1)
				printf_s("max = %d\t min = %d\n", max, min);
			break;

		case 6:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			printf_s("Enter your element: ");
			scanf_s("%d", &tmp);
			while (true){
				printf_s("Enter index: ");
				scanf_s("%d", &index);
				if (index >= 1)
					break;
				printf_s("Invalid value.\n");
			}
			insertStack(chosenStack, tmp, index);
			assignStack(myStack1, myStack2, chosenStack, tmp2);
			break;

		case 7:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			while (true) {
				printf_s("Enter index: ");
				scanf_s("%d", &index);
				if (index >= 1)
					break;
				printf_s("Invalid value.\n");
			}
			removeStack(chosenStack, index);
			assignStack(myStack1, myStack2, chosenStack, tmp2);
			break;

		case 8:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			printf_s("Size of stack: %d\n", sizeStack(chosenStack));
			break;

		case 9:
			selectStack(myStack1, myStack2, chosenStack, tmp2);
			while (true) {
				printf_s("Enter index: ");
				scanf_s("%d", &index);
				if (index >= 0)
					break;
				printf_s("Invalid value.\n");
			}
			if((tmp = lookAtStack(chosenStack, index)) != INT_MAX)
				printf_s("Stack[%d] = %d\n", index, tmp);
			break;
			

		default:
			printf_s("Invalid choice.\n");
		}

		printStack(myStack1);
		printStack(myStack2);
	}

	freeStack(myStack1);
	freeStack(myStack2);
}

 
int main()
{
	loopStack();


	return 0;
}