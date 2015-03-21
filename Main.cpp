#include <iostream>
#include "Library.h"



int main()
{
	Library library1("Library1",1);
	Book book1("Book1", "Autor1", 1);
	library1.push_back(book1);

	Book * book2 = new Book("Book2", "Autor2", 2);
	library1.push_front(*book2);

	Library * library2 = new Library(library1);
	library2->setName("Library2");

	std::list<Book>::iterator iterator;

	iterator = library1.insert(library1.end(), Book("Book3", "Autor3", 3));
	library1.insert(library1.begin() , Book("Book4", "Autor4", 4));
	library1.insert(iterator, Book("Book5", "Autor 5", 5));

	std::cout << book1 <<"\n"<< *book2<<"\n";
	std::cout << library1;
	system("pause");
	delete book2;
	delete library2;
	return 0;
}