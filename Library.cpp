#include "Library.h"
#define NULL 0

Library::Library() : std::list<Book>()
{
	this->name = NULL;
	this->number = 0;
}
Library::Library(const char * name) : Library()
{
	this->setName(name);
}
Library::Library(const char * name, int number) : Library(name)
{
	this->setNumber(number);
}
Library::Library(const Library & library) : std::list<Book>(library)
{
	this->name = NULL;
	this->setName(library.name);
	this->setNumber(library.number);	
}

Library::~Library()
{
	delete [] this->name;
	this->clear();
}

void Library::setName(const char * name)
{
	delete this->name;
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
const char * Library::getName()const
{
	return this->name;
}
void Library::setNumber(int number)
{
	this->number = number;
}
int Library::getNumber()const
{
	return this->number;
}

std::ostream& operator<<(std::ostream& a, const Library& library)
{
	a <<"Library: "<< library.name << "\n#" << library.number << "\nBooks:\n\n";

	std::list<Book> list = std::list<Book>(library);
	while (!list.empty())
	{
		a << list.front()<<"\n";
		list.pop_front();
	}

	return a;
}