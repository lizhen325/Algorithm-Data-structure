/*
1. Open and read both documents that you are going to compare. Only read words and numbers, skip special characters (spaces, dots, etc..) and convert the words to lower case
2. Calculate the word frequency in both collections of words, this means how many times each word occur in each document
3. Compare the frequencies from both computations and calculate the distance
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <map>
#include <regex>
#include <set>
#include <cmath>


class WordFreq {

	std::ifstream wordFile;
	std::map<std::string, int> wordCountMap;

public:

	WordFreq(const std::string& filename) : wordFile(filename) {
		if (!wordFile) {
			std::ostringstream os;
			os << "Could not open file: " << filename;
			throw std::runtime_error(os.str());
		}
	}

	void countWords() {
		std::string fileContents;
		wordFile.seekg(0, std::ios::end);
		fileContents.resize(wordFile.tellg());
		wordFile.seekg(0, std::ios::beg);
		wordFile.read(&fileContents[0], fileContents.size());
		std::string alNum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
		std::ostringstream os;
		for (std::string::iterator current, next = fileContents.begin();
			current != fileContents.end() || next != fileContents.end();){
			if (alNum.find(*next) == std::string::npos) {
				wordCountMap[os.str()]++;
				while ((next != fileContents.end()) && (alNum.find(*next) == std::string::npos)) {
					next++;
				}
				os.str("");
				current = next;
			}
			else {
				if (*next <= 'Z' && *next >= 'A')
					os << char(*next - ('Z' - 'z'));
				else
					os << (*next);
				next++;
			}
		}
		/*for (std::map<std::string,int64_t>::iterator it = wordCountMap.begin();
		it != wordCountMap.end(); it++) {
		std::cout << "'" << it->first << "' " << it->second << "\n";
		}*/
	}

	const int getWordFreq(const std::string& word) const {
		if (wordCountMap.find(word) != wordCountMap.end()) {
			return wordCountMap.at(word);
		}
		else {
			return 0;
		}
	}

	const size_t getWordsCount() {
		return wordCountMap.size();
	}

	int getDotProduct(const WordFreq& wordFreq) {
		int acc = 0;
		for (std::map<std::string, int>::iterator it = wordCountMap.begin();
			it != wordCountMap.end(); it++) {
			acc += this->getWordFreq(it->first) * wordFreq.getWordFreq(it->first);
		}
		return acc;
	}

};


int main(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Please supply at least two file names." << std::endl;
		return 1;
	}
	WordFreq file1Words(argv[1]);
	file1Words.countWords();
	WordFreq file2Words(argv[2]);
	file2Words.countWords();
	std::cout << "Distinct words in file 1 " << file1Words.getWordsCount() << "\n";
	std::cout << "Distinct words in file 2 " << file2Words.getWordsCount() << "\n";
	int t1 = file1Words.getDotProduct(file2Words);
	double t2 = sqrt((double)file1Words.getDotProduct(file1Words));
	double t3 = sqrt((double)file2Words.getDotProduct(file2Words));
	std::cout << "Document distance is " << acos(t1 / (t2*t3)) << "\n";
	return 0;
}