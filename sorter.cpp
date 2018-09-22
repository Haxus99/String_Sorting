#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <locale>

using namespace std;

string larger(string &s1, string &s2) {
	int length = s1.length();
	
	if (s2.length() > s1.length()) length = s2.length();
	
	for (int i = 0; i < length; i++) {
		if (tolower(s1[i]) + 0 > tolower(s2[i]) + 0) {
			return s1;
		}
		else if (tolower(s1[i]) + 0 < tolower(s2[i]) + 0) {
			return s2;
		}
	}
}


int main()
{	
	string temp; //used for interchanging words
	vector<string> vector_list; //list
	string filename; //filename of the list
	string sorted_filename; //output
	
	cout << "		SORTER\n\n";
	start:
	cout << "Drag the text file here and press enter (0 to exit)\n";
	
	cin >> filename;
	
	if (filename == "0") {
		system("pause");
		return 0;
	}
	
	ifstream list(filename.c_str()); //opening the file as list
	
	if (!list) { // checks if file exists
		cout << "THIS FILE DOES NOT EXIST!\n\n";
		goto start;
	}
	
	cout << "\nUploading file...";
	while (list) {
		list >> temp;
		vector_list.push_back(temp);
	} //writting file to vector
	
	list.close();
	
	vector_list.erase(vector_list.begin() + vector_list.size() - 1); 
	//the final word of the list is written 2 times
	//so we need to erase it
	cout << "\nSorting...";
	for (int i = 0; i < vector_list.size(); i++) {
		for (int j = i + 1; j < vector_list.size(); j++) {
			string largerString = larger(vector_list[i], vector_list[j]);
			if (largerString == vector_list[i]) {
				temp = vector_list[i];
				vector_list[i] = vector_list[j];
				vector_list[j] = temp;
			}
		}
	}
	
	sorted_filename = filename + "-sorted.txt";
	
	ofstream sorted(sorted_filename.c_str());
	
	cout << "\nCreating new sorted file...";
	
	for (int i = 0; i < vector_list.size(); i++) {
		sorted << vector_list[i] << "\n";
	}
	
	sorted.close();
	cout << "\nDONE! Sorted file saved as "<< sorted_filename <<"\n\n";
	goto start;
}
