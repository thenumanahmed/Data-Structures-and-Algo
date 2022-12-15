#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int match(string , string );	// to compare strings char by char
int hashFun(string ) ;		
int rabinKarpAlgo(string ,string ) ;
int main() {
	ifstream in;
	string choice = "1";
	while (choice == "1") {
		in.open("data.txt");
		int count = 0;
		string line = "",// for holding file lines
		word ="";	// word to be count
		cout << "Enter the word to count: ";
		getline(cin, word);
		while (!in.eof()) {
			getline(in, line);
			count += rabinKarpAlgo(word, line);
		}
		cout << "Word \"" << word << "\" was found " << count << " times in the file." << endl;
		in.close();
		cout << "Enter 1 to count another word or any key to exit the program: ";
		getline(cin,choice);
	};
	return 0;
}
int match(string s1, string s2) {
	if (s1.size() != s2.size()) return false;	//for error handling
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] != s2[i])return 0;
	return 1;
}
int hashFun(string s) {
	int code = 0;
	for (int i = 0; i < s.size(); i++) {
		code += s[i];
	}
	return code;
}
int rabinKarpAlgo(string pattern,string line) {
	int count = 0; //for counting the pattern
	if (pattern.length() > line.length())return 0;
	//else case
	string temp = "";
	int patternHash = hashFun(pattern);
	int tempHash = 0;
	for (int i = 0; i < pattern.size(); i++) {
		temp += line[i];
	}
	tempHash = hashFun(temp);
	if (tempHash == patternHash &&  match(temp, pattern)) count++;
	//start from next index
	for (int i = pattern.size(); i < line.length(); i++) {
		temp = temp.substr(1);	//remove the first character
		temp += line[i];	//adding next char 
		tempHash -= line[i - pattern.size()];//remove the code of the first char of the temp
		tempHash += line[i];	//add the code for new char of the file
		if (tempHash == patternHash && match(temp, pattern)) count++;
	}
	return count;
}