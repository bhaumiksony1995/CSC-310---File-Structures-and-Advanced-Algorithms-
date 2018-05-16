#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <sstream>
#include <math.h>

using namespace std;

string compress(string toCompress);
string decompress(string toDecompress);
int peekCount(string input, int i, string substr);
string decToHex(int decimal);
string digitToHex(int remainder);
int hexToDec (string hex);
void nextHexDigit(string& s, int& digit);


int main(int argc, char *argv[])
{
	string toCompress = "93 93 94 94 94 94 94 95 95 95 95 84 32 73 73 73 73 73 73 73 12 12 12 45 45 45 45";
	string toDecompress = "ff 93 1a 21 21 80 00 82 ff 94 05  21 21 ff 95 06 ff 73 07";
	string compressed; //compressed string
        string decompressed; //decompressed string

	cout << "\nString to be compressed: " << toCompress << endl;
	cout << "String to be decompressed: " << toDecompress << endl;

	string::iterator it = toDecompress.begin(); //iterator starting at beginning of toDecompress
	while (it != toDecompress.end()) //while toDecompress doesn't end
	{
		if (isspace(*it)) //if there is a space while iterating remove it from toDecompress
		{
			it = toDecompress.erase (it);
		}

		else
		{
			it++;
		}
	}


	compressed = compress(toCompress);
	decompressed = decompress(toDecompress);

	cout << "\nCompressed string: " << compressed << endl;
	cout << "Decompressed string: " << decompressed << endl;

}

string compress (string toCompress)
{
        string build;  
	int count;
        
	for(int i = 0; i < toCompress.length(); i += 3 + (count*3))
        {
                string substr = toCompress.substr(i,2);
                count = peekCount(toCompress, i, substr);
                if (count <= 2)
                        for (int i = 0;  i <= count;  i++)
                                build += substr + " ";
                else
                        build += "ff " + substr + " " + decToHex(count+1) + " ";
        }
        return build;
}

string decompress (string toDecompress)
{
	string decompressed;
	string returnVal;
	int x = 0; 
	int y = 0;
  	int alert;
  
	while(x < toDecompress.length())
	{
		if (toDecompress[x] != 'f') //if an f is not detected push value to result and move to next value
		{
			decompressed += toDecompress[x];
			x++;
		}

		else if ( toDecompress[x] == 'f') //if an f is detected, skip to 4th value and assign it to alert
		{
			//alert = (toDecompress[x + 4] - 48 ) * 10 + (toDecompress[x + 5] - 48);
string alert2;
alert2 += toDecompress[x + 4];
alert2 += toDecompress[x + 5];
int num = hexToDec(alert2);
cout << "The num isL " << num << endl;
			while( y < num)
			{
				decompressed += toDecompress[x + 2]; //add 2nd value from input
				decompressed += toDecompress[x + 3]; //add 3rd value from input
				y++;
			}

			x = x + 6; //jump 6 values to next integer
			y = 0;
		}
  	}

	for(int i = 0 ; i < decompressed.length() -1 ; i++) //add decoded values to string to return to main
	{
		returnVal += decompressed[i]; 
		returnVal += decompressed[i + 1];
		returnVal += (char)(32); //add spaces back into string before returing
		i++;
	}

	return returnVal;
}

int peekCount (string input, int curr, string substr)
{
   int count = 0;
   for (int i = curr + 3;  i < input.length();  i += 3)
       if (input.substr(i, 2) == substr)
           count++;
       else
           return count;
   return count;
}

string decToHex(int decimal)
{
	long int count, remainder;
	int num = decimal;
	string hex;

	while(num != 0)
	{
		remainder = num % 16;
		hex = digitToHex(remainder) + hex;
		num = num / 16;
		count = count + 1;
	}

	if (hex.length() == 1)
	{
		hex = '0' + hex;
	}

	return hex;
}

string digitToHex(int remainder)
{
	std::string result;
   	std::stringstream ss;
    	ss << std::hex << remainder;
    	ss >> result;
    	return result;
}

int hexToDec (string hex)
{
    int temp, remain, decimal = 0, count = 0;  string s = hex;

    do
    {
                nextHexDigit(s, temp);
                remain = temp % 16;
                decimal = decimal + remain * int(pow(16,count));
                count = count + 1;
     } while (s.length() != 0);

     return decimal;
}

void nextHexDigit(string& s, int& digit)
{
        if (s.length() == 0)
        {
                digit = 0;
                return;
        }
        char last = s[s.length()-1];
        if (isdigit(last))
        {
                digit = int(last - '0');
                s = s.substr(0, s.length()-1);
        }
        else
        {
                switch(toupper(last))
                {
                        case 'A' : digit = 10; break;
                        case 'B' : digit = 11; break;
                        case 'C' : digit = 12; break;
                        case 'D' : digit = 13; break;
                        case 'E' : digit = 14; break;
                        case 'F' : digit = 15; break;
                }
                s = s.substr(0, s.length()-1);
        }
}
