#include "table.h"
#include "util.h"
#include <iostream>
using namespace std;
int main()
{
	std::locale::global(std::locale(""));

	for (int a =1; a< 50000; a+=1000)
	{
		for (int c =0; c<50000; c+=10000)
		{
			HashTable h(50'000, a, c);
			ReaderFile reder("input2.txt");

			while (!reder.isEOF())
			{
				std::string str = reder.getNextWord();
				if (str.length() > 0)
					h.add(str);
			}
			cout <<"a="<<a<<" c="<<c<<" %="<< h.getPercentFull() << endl;
		}
	}




	/*h.showTable();

	cout << endl<< endl;
	
	cout << h.countColision() <<endl;
	cout << h.getPercentFull() << endl;
	h.getLongChain()->show();*/

	return 0;
}