#include <exception>
#include <string>
using namespace std;

class FileError : public exception
{
    public:
        FileError(string fileName) : m_fileName{std::move(fileName)} {}
        const char* what() const noexcept override { return m_message.c_str();}
        virtual const string& getFileName() const noexcept { return m_fileName; }
    protected:
        virtual void setMessage(string message) { m_message = std::move(message); }
    private:
        string m_fileName;
        string m_message;
};

class FileOpenError : public FileError
{
    public:
        FileOpenError(string fileName) : FileError{std::move(fileName)} {
            setMessage("Unable to open " + getFileName() + ".");
        }
};

class FileReadError : public FileError
{
    public:
        FileReadError(string fileName, size_t lineNumber) : FileError{std::move(fileName)}, m_lineNumber{lineNumber} {
            setMessage("Error reading " + getFileName() + ", line " + to_string(m_lineNumber));
        }
        virtual size_t getLineNumber() const noexcept { return m_lineNumber; }
    private:
        size_t m_lineNumber { 0 };
};