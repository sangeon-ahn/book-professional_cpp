#include <iostream>
#include <string>
using namespace std;

class Book
{
    public:
        Book() = default;
        virtual ~Book() = default;
        virtual string getDescription() const { return "Book"; }
        virtual int getHeight() const { return 120; }
};

class PaperBack : public Book
{
    public:
        string getDescription() const override {
            return "PaperBack " + Book::getDescription();
        }
};

class Romance : public PaperBack
{
    public:
        string getDescription() const override {
            return "Romance " + PaperBack::getDescription();
        }
        int getHeight() const override { return PaperBack::getHeight() / 2;}
};

class Technical : public Book
{
    public:
        string getDescription() const override {
            return "Technical " + Book::getDescription();
        }
};

int main()
{
    Romance novel;
    Book book;

    cout << novel.getDescription() << endl;
    cout << book.getDescription() << endl;
    cout << novel.getHeight() << endl;
    cout << book.getHeight() << endl;

    return 0;
}