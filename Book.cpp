#include "Book.h"
#define NULL 0

Book::Book()
{
	this->name = NULL;
	this->autor = NULL;
	this->year = 0;
}
Book::Book(const char * name) : Book()
{
	this->setName(name);
}
Book::Book(const char * name, const char * autor) : Book()
{
	this->setName(name);
	this->setAutor(autor);
}
Book::Book(const char * name, const char * autor, int year) : Book()
{
	this->setName(name);
	this->setAutor(autor);
	this->year = year;
}
Book::Book(const Book & book) : Book()
{
	this->setAll(book.name, book.autor, book.year);
}
Book::~Book()
{
	if(this->name) delete [] this->name;
	if(this->autor) delete [] this->autor;
}

void Book::setName(const char * name)
{
	delete [] this->name;
	if (name)
	{
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	else
	{
		this->name = NULL;
	}
}
void Book::setAutor(const char * autor)
{
	delete [] this->autor;
	if (autor)
	{
		this->autor = new char[strlen(autor) + 1];
		strcpy(this->autor, autor);
	}
	else
	{
		this->autor = NULL;
	}
}
void Book::setYear(int year)
{
	this->year = year;
}
void Book::setAll(const char * name, const char * autor, int year)
{
	this->setAutor(autor);
	this->setName(name);
	this->setYear(year);
}
const char * Book::getName()const
{
	return this->name;
}
const char * Book::getAutor()const
{
	return this->autor;
}
int Book::getYear()const
{
	return this->year;
}
bool Book::operator==(const Book & book)
{
	if (this == &book) return true; 
	bool bAutor = this->autor == book.autor || !strcmp(this->autor, book.autor);
	bool bName = this->name == book.name || !strcmp(this->name, book.name);
	if (bAutor && bName && this->year == book.year)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const Book & Book::operator=(const Book & book)
{
	this->setAll(book.name, book.autor, book.year);
	return *this;
}

std::ostream& operator<<(std::ostream& a, const Book& book)
{
	a << book.name << "\n" << book.autor << "\n" << book.year << "\n";
	return a;
}