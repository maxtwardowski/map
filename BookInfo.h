enum Status {
	ONTHEBOOKSHELF,
	BORROWED
};

class BookInfo {
public:
	std::string author;
	std::string category;
	unsigned int pagesno;
	Status status;
	BookInfo() {

	}
	BookInfo(std::string author, std::string category, unsigned int pagesno, Status status) {
		this->author = author;
		this->category = category;
		this->pagesno = pagesno;
		this->status = status;
	}
	friend std::ostream& operator<< (std::ostream& stream, const BookInfo& b) {
		stream << "Author: " << b.author << std::endl;
		stream << "Category: " << b.category << std::endl;
		stream << "Number of pages: " << b.pagesno << std::endl;
		stream << "Status: " << ((b.status == ONTHEBOOKSHELF) ? ("on the bookshelf") : ("borrowed")) << std::endl;
		return stream;
	}
};
