#include "album.h"

Album::Album (const Album& otherAlbum)
{
	strcpy(UPC, otherAlbum.UPC);
	strcpy(Artist, otherAlbum.Artist);
	strcpy(Title, otherAlbum.Title);
}

Album::Album (String upc, String artist, String title)
{
	strcpy(UPC, upc);
	strcpy(Artist, artist);
	strcpy(Title, title);
}

Album::Album ()
{
	strcpy(UPC, "\0");
	strcpy(Artist, "\0");
	strcpy(Title, "\0");
}

Album & Album::operator = (const Album& otherAlbum)
{
	strcpy(UPC, otherAlbum.UPC);
	strcpy(Artist, otherAlbum.Artist);
	strcpy(Title, otherAlbum.Title);
	return *this;
}

string Album::getUPC()
{
	return UPC;
}

int Album::recordSize()
{
	return (strlen(UPC) + strlen(Artist) + strlen(Title));
}

bool operator < (const Album& a, const Album& b)
{
	int avalue;
	int bvalue;
	avalue = atoi(a.UPC);
	bvalue = atoi(b.UPC);

	if (avalue < bvalue)
		return true;
	else
		return false;
}

ostream & operator << (ostream & stream, Album & C)
{
	stream << C.UPC << "\n" << C.Artist << "\n" << C.Title << endl;
	return stream;
}

istream & operator >> (istream & stream, Album & C)
{
	string upc;
	string artist;
	string title;

	getline(stream, upc);
	getline(stream, artist);
	getline(stream, title);

	strcpy(C.UPC, upc.c_str());
	strcpy(C.Artist, artist.c_str());
	strcpy(C.Title, title.c_str());

	return stream;
}
	
