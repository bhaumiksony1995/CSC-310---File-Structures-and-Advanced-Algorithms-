
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
     int num;
     string word;

     stringstream ss;

     ss<<"This line has four words";
     while (ss>>word)
           cout<<word<< endl;

     ss<<"54";
     ss>>num;
     cout<<" "<<num<<endl;

     return 0;
}
