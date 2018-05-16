#include <fstream>
#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <utime.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	string file1;
	string file2;
	ifstream infile1;
        ifstream infile2;
	string option;
	string option1;
	string option2;
	int N;
	struct stat buf;
        struct utimbuf timebuf;
        char *token;
        string type;
	int myChar = 1;
	int line = 1;
	char f1;
	char f2;
	int asciiF1;
	int asciiF2;
        int octalF1;
        int octalF2;

	if((argc < 2) || (argc > 6))
	{
		cout << "Invalid number of arguments" << endl;
		exit(EXIT_FAILURE);
	}
	
	for (int i = 1;  i < argc;  i++)
        {
                lstat (argv[i], &buf);

                if (S_ISREG(buf.st_mode))
                {
                        type = "reg";
                }

                else if (S_ISDIR(buf.st_mode))
                {
                        type = "dir";
                }
        }

        if (type == "dir")
        {
                cout << "An invalid file type was used (directory)" << endl;
        }

	
	if (argc == 3)
	{
		for (int i = 1; i < 3; i++)
		{
                        if(!ifstream(argv[i]))
			{
                                cout << "The file " << argv[i] << " does not exist" << endl;
			        exit(EXIT_FAILURE);
			}

			else
			{
				file1 = argv[1];
				file2 = argv[2];
			}
		}

		infile1.open("file1", ifstream::in);
		infile2.open("file2", ifstream::in);

		while ((infile1.get(f1)) && (infile2.get(f2)))
		{
			if (f1 == f2)
                	{
                        	myChar++;

                        	if (f1 == '\n')
                       		{
                                	line++;
                        	}
                	
				if (f1 != f2)
				{
					cout << "the files differ: char " << myChar << ", line " << line << endl;
				}
			}
		}

        	if ((infile1.eof()) && (infile2.eof()))
        	{
			cout << "cmp: EOF on " << file1 << " and " << file2 << endl;
        	}

		else if (infile1.eof())
		{
			cout << "cmp: EOF on " << file1 << endl;
			exit(EXIT_FAILURE);
		}

		else if (infile2.eof())
		{
			cout << "cmp: EOF on " << file2 << endl;
		}
	}
	

	else if (argc == 4)
	{
		option = argv[1];
	
		if (option == "-c")
		{
			file1 = argv[2];
			file2 = argv[3];

			for (int i = 2; i < 4; i++)
			{
				if(!ifstream(argv[i]))
                		{
                        		cout << "The file " << argv[i] << " does not exist" << endl;
                        		exit(EXIT_FAILURE);
                		}
			}

			infile1.open("file1", ifstream::in);
                	infile2.open("file2", ifstream::in);

	                while ((infile1.get(f1)) && (infile2.get(f2)))
                        {       
                                if (f1 == f2)
                                {       
                                        myChar++;
                                }
                                if (f1 == '\n')
                                {
                                        line++;
                                }
				if (f1 != f2)
				{
					cout << "the files differ: char " << myChar << ", line" << line << " is ";
					asciiF1 = (int) f1;
		                        asciiF2 = (int) f2;
				}
                        }
		}	
		
		printf("%o " " %c " " %o " " %c\n", asciiF1, asciiF1, asciiF2, asciiF2);
	}

	else if (argc == 5)
	{
		option = argv[1];
	
		if (option == "-i")
		{
			N = atoi(argv[2]);
			file1 = argv[3];
			file2 = argv[4];

			infile1.open("file1", ifstream::in);
			infile2.open("file2", ifstream::in);
			infile1.seekg(N);
			infile2.seekg(N);

			for (int i = 3; i < 5; i++)
                        {
                        	if (!ifstream(argv[i]))
                        	{
                                	cout << "The file " << argv[i] << " does not exist" << endl;
                                	exit(EXIT_FAILURE);
                        	}
                        }

			while ((infile1.get(f1)) && (infile2.get(f2)))
                	{       
                        	if (f1 == f2)
                        	{       
                                	myChar++;
                                }
                                if (f1 == '\n')
                                {       
                                        line++;
                                }
				if (f1 != f2)
				{
					cout << "the files differ: char " << myChar << ", line " << line << endl;
				}
                        }
                }
	}

	else if (argc == 6)
        {
                option1 = argv[1];

                if (option1 == "-i")
                {
			option2 = argv[3];
                        N = atoi(argv[2]);
                        file1 = argv[4];
                        file2 = argv[5];
                        infile1.open("file1", ifstream::in);
                        infile2.open("file2", ifstream::in);
                        infile1.seekg(N);
                        infile2.seekg(N);
                        for (int i = 4; i < 6; i++)
                        {
                                if (!ifstream(argv[i]))
                                {
                                        cout << "The file " << argv[i] << " does not exist" << endl;
                                        exit(EXIT_FAILURE);
                                }
                        }

                        while ((infile1.get(f1)) && (infile2.get(f2)))
                        {
                                if (f1 == f2)
                                {
                                        myChar++;
                                }
                                if (f1 == '\n')
                                {
                                        line++;
                                }
                                if (f1 != f2)
                                {
                                        cout << "the files differ: char " << myChar << ", line " << line << endl;
                                }
                        }
		}

		else if (option1 == "-c")
                {
			option2 = argv[3];
                        file1 = argv[4];
                        file2 = argv[5];

                        for (int i = 4; i < 6; i++)
                        {
                                if(!ifstream(argv[i]))
                                {
                                        cout << "The file " << argv[i] << " does not exist" << endl;
                                        exit(EXIT_FAILURE);
                                }
                        }

                        infile1.open("file1", ifstream::in);
                        infile2.open("file2", ifstream::in);

                        while ((infile1.get(f1)) && (infile2.get(f2)))
                        {
                                if (f1 == f2)
                                {
                                        myChar++;
                                }
                                if (f1 == '\n')
                                {
                                        line++;
                                }
                                if (f1 != f2)
                                {
                                        cout << "the files differ: char " << myChar << ", line" << line << " is ";
                                        asciiF1 = (int) f1;
                                        asciiF2 = (int) f2;
                                }
                        }

			printf("%o " " %c " " %o " " %c\n", asciiF1, asciiF1, asciiF2, asciiF2);
                }

		if (option2 == "-i")
		{
                        N = atoi(argv[4]);
                        file1 = argv[4];
                        file2 = argv[5];
                        infile1.open("file1", ifstream::in);
                        infile2.open("file2", ifstream::in);
                        infile1.seekg(N);
                        infile2.seekg(N);
                        for (int i = 4; i < 6; i++)
                        {
                                if (!ifstream(argv[i]))
                                {
                                        cout << "The file " << argv[i] << " does not exist" << endl;
                                        exit(EXIT_FAILURE);
                                }
                        }

                        while ((infile1.get(f1)) && (infile2.get(f2)))
                        {
                                if (f1 == f2)
                                {
                                        myChar++;
                                }
                                if (f1 == '\n')
                                {
                                        line++;
                                }
                                if (f1 != f2)
                                {
                                        cout << "the files differ: char " << myChar << ", line " << line << endl;
                                }
                        }

		}

		else if (option2 == "-c")
		{
                        file1 = argv[4];
                        file2 = argv[5];

                        for (int i = 4; i < 6; i++)
                        {
                                if(!ifstream(argv[i]))
                                {
                                        cout << "The file " << argv[i] << " does not exist" << endl;
                                        exit(EXIT_FAILURE);
                                }
                        }

                        infile1.open("file1", ifstream::in);
                        infile2.open("file2", ifstream::in);

                        while ((infile1.get(f1)) && (infile2.get(f2)))
                        {
                                if (f1 == f2)
                                {
                                        myChar++;
                                }
                                if (f1 == '\n')
                                {
                                        line++;
                                }
                                if (f1 != f2)
                                {
                                        cout << "the files differ: char " << myChar << ", line" << line << " is ";
                                        asciiF1 = (int) f1;
                                        asciiF2 = (int) f2;
                                }
                        }

                        printf("%o " " %c " " %o " " %c\n", asciiF1, asciiF1, asciiF2, asciiF2);
		}
        }

	return 0;
}
