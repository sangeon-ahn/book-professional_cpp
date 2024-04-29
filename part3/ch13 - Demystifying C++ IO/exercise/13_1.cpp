#include "Person.h"

int main()
{
	Person p {"sangeon", "ahn"};
	p.output(cout);
	
	stringstream s;
	p.output(s);
	cout << s.str() << endl;

	// file output
	ofstream fs {"13_1.txt", ios_base::trunc};
	p.output(fs);
}