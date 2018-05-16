#include <iostream>
#include <ctype.h>
#include <algorithm> 
#include <string>  

using namespace std;

bool isOdd(int Num);

int main()
{
	string key = "Dalton"; 
	string keyCopy = key;
	int charCount = 0;
	int Array[(key.length())/2];

	cout << key << endl;
	cout << keyCopy << endl;
	
	transform(keyCopy.begin(), keyCopy.end(), keyCopy.begin(), ::toupper);
	cout << keyCopy << endl;
	charCount = keyCopy.length();
	cout << charCount << endl;

	if (isOdd(charCount) == false)
        {
                cout << "Length is Odd" << endl;
		keyCopy += 'Z';
        }

	else if (isOdd(charCount) == true)
	{
		cout << "Length is Even" << endl;
	}

	cout << keyCopy << endl;

	int i = 0;
	for (int count = 0; count < keyCopy.length(); count++)
	{
		Array[i] = (keyCopy[count] * 100) + keyCopy[count + 1];	
		count++;
	//	cout << Array[i] << endl;
		i++;
	}

	int arraySize = sizeof(Array)/sizeof(*Array);
	int remainder;
	int num;
	for (int j = 0; j < arraySize; j++)
	{
		num = Array[j] + Array [j + 1];
		j++;
		j++;
	}
int d = (5 % 3);
cout << d << endl;
	cout << num << endl;
remainder = (36373 % num);
	cout << remainder << endl;
return 0;
}

bool isOdd (int Num)
{
	if (Num % 2 == 0)
		return true;
	else
		return false;
}
