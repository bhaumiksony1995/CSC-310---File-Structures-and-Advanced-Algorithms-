// hash.cpp

#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <algorithm>

using namespace std;

typedef char String[20];
const int NumCities = 435;

struct Bucket
{
	int currSize;
	String key[3];
};

int hash (string key, int maxAddresses);
void numCollisions(int array[]);
void buildHashFile(Bucket mybucks[]);
void flushBuckets(Bucket mybucks[]);
void buildHashArray(fstream& infile, int array[], Bucket mybucks[]);
void testHash(fstream& infile, Bucket mybucks);
void printBuckets(Bucket mybucks[]);
bool isOdd (int Num);

int main()
{
	fstream infile("cities.dat", ios::in);
	int array[300] = {0};
        Bucket mybucks[300];

	flushBuckets(mybucks);
	buildHashArray(infile, array, mybucks);
	numCollisions(array);
	printBuckets(mybucks);
	buildHashFile(mybucks);
        return 0;
}

void flushBuckets(Bucket mybucks[])
{
	for (int i = 0;  i < 300;  i++)
	{
		mybucks[i].currSize = 0;
		for (int j = 0;  j < 3;  j++)
			strcpy (mybucks[i].key[j], "///");
	}
}

void printBuckets(Bucket mybucks[])
{
	for (int i = 0;  i < 300;  i++)
	{
		cout << "i = " << i;
		cout << " size = " << mybucks[i].currSize << " "; 
		for (int j = 0;  j < 3;  j++)
			cout << mybucks[i].key[j] << " ";
		cout << endl;
	}
}

void buildHashArray(fstream& infile, int array[], Bucket mybucks[])
{
	string s;  int i;

	getline (infile, s);
        while (infile)
        {
                int slot = hash(s, 300);
		 //cout << "Key = " << s << " with a hash val of " << slot << endl;
                array[slot] += 1;
                mybucks[slot].currSize += 1;
		i = 0;
                while(strcmp(mybucks[slot].key[i],"///") != 0)
                {
			i++;
			if (i == 3)
			{
			i = 0;
			 //cout<<"Overflow at "<<slot<<" on hash of "<<s<< endl;
			slot++;
			if (slot > 299)
				slot = 0;
			}
		}
                strcpy(mybucks[slot].key[i], s.c_str());
                getline (infile, s);
        }
}

void numCollisions(int array[])
{
	int synonymns = 0;
	for (int j = 0;  j < 300;  j++)
	{
		if (array[j] > 1)
			synonymns += array[j] - 1;
		cout << "j = " << j << " collisions = " << array[j] << endl;

	}
	cout << "Total Synonyms = " << synonymns << endl;

	cout.setf(ios::fixed, ios::floatfield);  cout.setf(ios::showpoint);
	for (int i=0;  i <= 8;  i++)
	{
		int count = 0;
		cout << "d(" << i << ") = ";
		for (int j = 0;  j < 300;  j++)
			if (array[j] == i)
				count++;
		cout << setprecision(2) << count << " " << float(count) / 300.0 << endl;
	}
}

int hash (string key, int maxAddresses)
{
	// YOUR HASH FUNCTION GOES HERE
	string keyCopy = key;
	int charCount = keyCopy.length();
	int i = 0;
	int Array[(keyCopy.length()) / 2];
	int arraySize;
        int remainder;
	int num;
	int newRemainder;

	transform(keyCopy.begin(), keyCopy.end(), keyCopy.begin(), ::toupper);

	if (isOdd(charCount) == false)
        {
                keyCopy += 'Z';
        }

        for (int count = 0; count < keyCopy.length(); count++)
        {
                Array[i] = (keyCopy[count] * 100) + keyCopy[count + 1];
                count++;
                i++;
        }

	arraySize = keyCopy.length() / 2;

        for (int j = 0; j < arraySize; j++)
        {
                num = Array[j] + Array[j + 1];
                j++;
                j++;
        }

	remainder = 36373 % num;
	newRemainder = remainder % maxAddresses;

	return newRemainder;
}

void buildHashFile(Bucket mybucks[])
{
	fstream outfile("hash.ind", ios::out | ios::binary);

        // YOUR LOOP GOES HERE
        for (int i = 0; i < 300; i++)
	{
		outfile.write((char *) &mybucks[i], sizeof(Bucket));
	}
}

bool isOdd (int Num)
{
        if (Num % 2 == 0)
                return true;
        else
                return false;
}

