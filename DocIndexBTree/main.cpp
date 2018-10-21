// Provide 9598 text file(numbers are consecutive like 1.txt,2.txt).
// Run the program. (It will create a binary search tree consists of words from files read. While reading a file, it first checks whether the word exists in tree. If it does, the program adds the name of the file to the listOfFiles variable in BTreeNode of that word. If it doesn't, the program creates a BTreeNode and insert it to tree.)
// The program will give you the list of files which contain that word. 

#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

bool isThere(string w){
	string stopword;
	ifstream myReadFile;
	myReadFile.open("stopwords.txt");
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()){
			 myReadFile >> stopword;
			 if(w == stopword)
				 return true;
		}
		myReadFile.close();
		return false;
	}
	else{
		cout << "Can not open file.." << endl;
	}
	return false;
}

int main(){
	BinarySearchTree myTree;
	ifstream myReadFile;
	ifstream myOutFile;
	int index;
	int fileCount = 1;
	myOutFile.open("files.txt");
	string filename;
	string s;
	if(myOutFile.is_open()){
		while(!myOutFile.eof()){
			myOutFile >> filename;
			myReadFile.open(filename);
			if (myReadFile.is_open()) {
				while (!myReadFile.eof()) {
					myReadFile >> s;
					if(s[s.length()-1] == '.' || s[s.length()-1] == ','|| s[s.length()-1] == ':' || s[s.length()-1] == ';'
					   || s[s.length()-1] == '?' || s[s.length()-1] == '!'){
					   s.erase(s.length()-1,1);
					}
					std::transform(s.begin(), s.end(), s.begin(), ::tolower);
					if(!isThere(s)){
						myTree.insertWord(s,fileCount);
					}
				}
			fileCount++;
			myReadFile.close();
			}
		}
	}
	else
		cout << "Can't open file." << endl;

	myTree.inOrderTraversal();
	cout << endl;

	while(true){
		string word;
		cout << "Enter a word: ";
		cin >> word;
		cout << "The files that contain '" << word << "': "; 
		myTree.printListOfFiles(word);
		cout << endl << endl;
	}
	system("pause");
	return 0;

}

