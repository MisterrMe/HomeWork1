#ifndef __LIBRARY_H
#define __LIBRARY_H

#include <list>
#include "Book.h"

class Library : public std::list<Book>
{
public:
	Library();
	Library(const char * name);
	Library(const char * name, int number);
	Library(const Library & library);

	~Library();

	void setName(const char * name);
	const char * getName()const;
	void setNumber(int number);
	int getNumber()const;
	friend std::ostream& operator<<(std::ostream&, const Library&);
private:
	char * name;
	int number;
};

#endif