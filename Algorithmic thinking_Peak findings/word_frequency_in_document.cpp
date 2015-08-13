#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;
	int main()
	{
		// for function read;
		ifstream ifs{ "C:/Users/zhenli/Desktop/text1.txt" };
		vector<string> content;
		for (string buffer; ifs >> buffer; content.push_back(buffer));

		// remove all special characters
		for (auto& word : content)
		{
			std::string converted;
			for (auto ch : word)
				if (isalpha(ch)) converted.push_back(tolower(ch));
			word = converted;
		}

		// compute word frequency in the document
		map <string, int> mymap;
		for (auto &word : content)
			mymap[word]++;
			/*if (mymap.find(word) != mymap.end())
				cout << mymap.at(word) << endl;*/
		for (auto i = mymap.begin(); i != mymap.end(); ++i)
			cout << i->first << " => " << i->second << endl;
		system("pause");
		return 0;
	}