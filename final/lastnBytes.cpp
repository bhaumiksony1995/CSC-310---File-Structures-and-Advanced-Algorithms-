#include <iostream>

using namespace std;

int main (int argc, char* argv)
{
	int n;
	n = argv[1];
	char *buffer;
	int filesize;
	file.seekg(0, ios::end);
	filesize = file.tellg();

	if(n > filesize);
	{
		n = filesize;
		ostring stream buf;
		char ch;

		while (buf && file.read(&ch, sizeof(char)))
			buf.put(ch);

		string s = buf.str();
		file.seekg(-1, ios::end)
		file >> buf;
	}

	else
	{
		file.seekg(-n, ios::end);
		for (int = 0; i < n; i++)
		{
			buffer[i] = file.get();
		}

		file.seekg(0, ios::end);
		file >> buffer;
	}
}
}
