#include <iostream>

int EnterDenomination(int);
int* EnterArray(int*, int);
void DisplayArray(int*, int);
int MinposMaxnegElements(int*, int);
int EvenCount(int);
void WorkProcessWithArray(int*, int);

using namespace std;

int main()
{
	while (true)
	{
		const int N = 100;
		int n = EnterDenomination(N);
		int* a = new int[n];
		int k = 0;
		EnterArray(a, n);
		system("cls");
		cout << "Source array " << endl;
		DisplayArray(a, n);
		cout << endl;
		WorkProcessWithArray(a, n);
		system("pause");
		system("cls");

		char yes;
		cout << "If you would like to continue, please, press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}

int EnterDenomination(int n)
{
	int k;
	while (true)
	{
		cout << "Please, enter 0 <= n <=" << endl << "n: ";
		cin >> k;
		if (k > 0 && k <= n)
			return k;
		cout << "Error! Enter the other value" << endl;
	}
}

int* EnterArray(int* a, int n)
{
	cout << "Enter elements of array" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << (i + 1) << "] = ";
		cin >> *(a + i);
	}
	return a;
}

void DisplayArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		cout << *(a + i) << " ";
}

int EvenCount(int number)
{
	if (number < 0)
		number = abs(number);
	int evenCounter = 0;
	while (number > 0)
	{
		if (number % 10 % 2 == 0)
			evenCounter++;
		number /= 10;
	}
	return evenCounter;
}

void WorkProcessWithArray(int* a, int n)
{
	int maxNeg = *(a + 0), maxNegIndex = 0, minPos = *(a + 0), minPosIndex = 0;
	for (int i = 0; i < n; i += 2)
	{
		if ((*(a + i) > 0) && (*(a + i) < minPos))
		{
			minPos = *(a + i);
			minPosIndex = i;
		}
		if ((*(a + i) < 0) && (abs(*(a + i)) < maxNeg))
		{
			maxNeg = *(a + i);
			maxNegIndex = i;
		}
	}
	cout << endl << "Min positive element is " << minPos << endl;
	cout << "Max negative element is " << maxNeg << endl;

	int startIndex = 0, endIndex = 0;
	if (maxNegIndex > minPosIndex)
	{
		startIndex = minPosIndex;
		endIndex = maxNegIndex;
	}
	if (minPosIndex > maxNegIndex)
	{
		startIndex = maxNegIndex;
		endIndex = minPosIndex;
	}
	if (endIndex - startIndex <= 2 || endIndex - startIndex == endIndex)
	{
		cout << endl << "Only one element is between min positive " << minPos << " and max negative " << maxNeg << ". It`s " << *(a + startIndex + 1) << endl;
		return;
	}


	for (int iterationCount = endIndex - startIndex - 1; iterationCount != 0; iterationCount--)
		for (int i = startIndex + 1; i < endIndex; i++)
		{
			if (i + 1 != endIndex)
				if (EvenCount(*(a + i)) > EvenCount(*(a + i + 1)))
					swap(*(a + i + 1), *(a + i));
		}

	int i, p = n + startIndex - endIndex;
	int* b = new int[p];
	for (i = 0; i < minPos; i++)
		*(b + i) = *(a + i);
	for (i = maxNeg + 1; i < n; i++)
		*(b + (minPos + i - maxNeg - 1)) = *(a + i);
	for (i = 0; i < n - minPos; i++)
		*(a + i) = *(a + (i + minPos));

	cout << endl<< "Array after sort " << endl;
	DisplayArray(b, p);

}
