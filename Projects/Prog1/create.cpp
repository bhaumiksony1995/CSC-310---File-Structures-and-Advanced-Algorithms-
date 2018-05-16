#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
using namespace std;

typedef char String[25];
struct BookRec
{
	unsigned int isbn;
	String name;
	String author;
	int onhand;
	float price;
	String type;
};

int main(int argc, char *argv[])
{
	string fileName;
        if(argc == 2)
        {
                fileName = argv[1];
        }
        else
        {
                fileName = "";
        }

        ifstream file (fileName.c_str(), ios::in);
        ofstream output ("library.out", ios::out | ios::binary);

        BookRec buffer;
        char temp;
        int last = 0;
        int line = 0;
        long tempIsbn;

        while(file >> tempIsbn)
        {
                buffer.isbn = tempIsbn;
                line++;
            
	    	file >> temp;
                file.getline(buffer.name, 25, '|');
                file.getline(buffer.author, 25, '|');

                file >> buffer.onhand >> temp >> buffer.price;

                file >> temp;
                file.getline(buffer.type, 25, '\n');
	
		 if(tempIsbn < 1)
                {
                        cerr << "Illegal ISBN number encountered on line " << line << " of data file - record ignored." << endl;
                        continue;
                }
                else if(buffer.isbn < last)
                {
                        cerr << "ISBN number out of sequence on line " << line << " of data file." << endl;
                        cout << buffer.isbn << " " << buffer.name << " " << buffer.author << " " << buffer.onhand << " " << buffer.price << " " << buffer.type << endl;
                }
                else if(buffer.onhand < 0)
                {
                        cerr << "Negative amount onhand on line " << line << " of data file - record ignored." << endl;
                        cout << buffer.isbn << " " << buffer.name << " " << buffer.author << " " << buffer.onhand << " " << buffer.price << " " << buffer.type << endl;
                        continue;
                }
                else if(buffer.price < 0)
                {
                        cerr << "Negative price on line " << line << " of data file - record ignored." << endl;
                        cout << buffer.isbn << " " << buffer.name << " " << buffer.author << " " << buffer.onhand << " " << buffer.price << " " << buffer.type << endl;
                        continue;
                }

		last = buffer.isbn;
                output.write((char *) &buffer, sizeof(BookRec));


		while (file.read((char *) &buffer, sizeof(buffer)))
		{
			cout<<setw(10)<<setfill('0')<<buffer.isbn
			<<setw(25)<<setfill(' ')<<buffer.name
			<<setw(25)<<buffer.author
			<<setw(3)<<buffer.onhand
			<<setw(6)<<buffer.price
			<<setw(10)<<buffer.type<<endl;
		}

	}
return 0;	
}
