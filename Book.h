#ifndef __BOOK_H
#define __BOOK_H

#include <iostream>

class Book
{
public:
	Book();
	Book(const char * name);
	Book(const char * name, const char * autor);
	Book(const char * name, const char * autor, int year);
	Book(const Book & book);
	~Book();

	void setName(const char * name);
	void setAutor(const char * autor);
	void setYear(int year);
	void setAll(const char * name, const char * autor, int year);
	const char * getName() const;
	const char * getAutor() const;
	int getYear()const;

	bool operator==(const Book & book);
	const Book & operator=(const Book & book);

	friend std::ostream& operator<<(std::ostream&, const Book&);
private:
	char * name;
	char * autor;
	int year;
};

#endif