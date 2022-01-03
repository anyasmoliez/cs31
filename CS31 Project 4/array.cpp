#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int locateMaximum(const  string  array[], int  n);
bool hasNoCapitals(const string array[], int n);
bool identicalValuesTogether(const string array[], int n);
bool hasTwoOrMoreDuplicates(const string array[], int  n);
int countFloatingPointValues(const string array[], int  n);
bool digitsAndDecimals(string s);
int shiftLeft(string array[], int n, int amount, string placeholder);
int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace);

//Anya Smolentseva 305503018



int main() {

	string numbers[10] = { "..", "+500", "-6.7", "500,000", "55", "55.", ".1", "555a", "3.5", "2.0.5" };
	string ex[5] = { ".", "000.75", "1000000", "12.345" };
	string array[7] = { "AA", "BB", "aa", "bb", "cc", "dd", "ee" };
	string data[5] = { " mamaBbcca", "mamaBbcca", "12,", "98.76", "tyrion" };
	string folks[8] = { "samwell", "jon", "margaery", "daenerys",
						  "tyrion", "sansa", "jon", "samwell" };
	string example[5] = { "a", "b", "c", "d", "e" };
	string help[7] = { "55.", "4A", "35", "55.", "15.0", "15.0", "A12A" };
	string check[7] = { "AA", "BB", "BB", "BB", "cc", "dd", "ee" };
	string check2[7] = { "AA", "BB", "BB", "BB", "AA", "dd", "ee" };
	string testID[8]= { "a", "a", "a", "a", "a", "b", "a","a" };
	string testID2[10] = { "hello", "hello", "hi", "hi", "bye", "hello", "bye", "a", "b", "b" };
	string find[7] = { "danny", "dan", "aBby", "goldie", "strawberry", "n1n2n3n4n", "bbbbby" };
	string newString[6] = { "", "1", "000.1", "b", "", "a" };
	string shift[5] = { "soap", "bar", "", "shampoo", "hair" };
	string replace[6] = { "zZoeZaay", "aZzq", "aaaZZ", "xy", "t12", "aaaaaZ" };
	string replace2[6] = { " ", "hiya", " ", "yo", "hello", " " };
	string folks2[8] = { "samwell", "jon", "margaery", "daenerys",
						  "tyrion", "sansa", "magdalena", "jon" };
	string identTest[5] = { "xy", "xy", "b", "xy", "xy" };

	assert(locateMaximum(array, 6) == 5);
	assert(locateMaximum(newString, 6) == 3);
	assert(locateMaximum(data, 5) == 4);
	assert(locateMaximum(example, 5) == 4);
	assert(locateMaximum(help, 7) == 6);
	assert(locateMaximum(check, 0) == -1);
	assert(locateMaximum(check2, 4) == 1);
	assert(countFloatingPointValues(folks, 8) == 0);
	assert(countFloatingPointValues(numbers, 10) == 4);
	assert(countFloatingPointValues(data, 4) == 1);
	assert(countFloatingPointValues(numbers, 1) == 0);
	assert(countFloatingPointValues(ex, 4) == 4);
	assert(countFloatingPointValues(newString, 6) == 2);
	assert(hasNoCapitals(data, 2) == false);
	assert(hasNoCapitals(newString, 6) == true);
	assert(hasNoCapitals(data, 1) == false);
	assert(hasNoCapitals(example, 3) == true);
	assert(hasNoCapitals(array, 3) == false);
	assert(hasNoCapitals(testID, 7) == true);
	assert(hasTwoOrMoreDuplicates(folks, 8) == true);
	assert(hasTwoOrMoreDuplicates(example, 5) == false);
	assert(hasTwoOrMoreDuplicates(testID, 5) == true);
	assert(hasTwoOrMoreDuplicates(testID, 3) == true);
	assert(hasTwoOrMoreDuplicates(help, 4) == false);
	assert(identicalValuesTogether(identTest, 5) == false);
	assert(identicalValuesTogether(newString, 6) == false);
	assert(identicalValuesTogether(example, 5) == true);
	assert(identicalValuesTogether(testID, 7) == false);
	assert(identicalValuesTogether(example, 5) == true);
	assert(identicalValuesTogether(check, 5) == true);
	assert(identicalValuesTogether(testID2, 4) == true);
	assert(identicalValuesTogether(testID2, 6) == false);
	assert(identicalValuesTogether(testID2, 5) == true);
	assert(identicalValuesTogether(testID, 8) == false);
	assert(shiftLeft(shift, 5, 2, "soap") == 2);
	assert(shiftLeft(data, 5, 10, "bar") == 5);
	assert(shiftLeft(testID2, 8, 0, "hello") == 0);
	assert(shiftLeft(check, 4, 3, "yo") == 3);
	assert(shiftLeft(example, 5, 4, "hi") == 4);
	assert(shiftLeft(folks2, 8, 22, "nancy") == 8);
	assert(shiftLeft(folks, 5, 3, "samwell") == 3);
	assert(identicalValuesTogether(check2, 5) == false);
	assert(replaceFirstAndLastOccurrences(array, 7, 'f', 'a') == 0);
//	assert(replaceFirstAndLastOccurrences(find, 7, 'n', 'A') == 5);
//	assert(replaceFirstAndLastOccurrences(find, 6, 'b', 'b') == 2);
//	assert(replaceFirstAndLastOccurrences(find, 7, 'b', 'T') == 4);
	assert(replaceFirstAndLastOccurrences(find, 7, 'b', 'b') == 4);
	assert(replaceFirstAndLastOccurrences(replace, 6, 'Z', 'a') == 6);
	assert(replaceFirstAndLastOccurrences(replace2, 0, 'a', 'b') == -1);
	assert(replaceFirstAndLastOccurrences(replace2, 6, ' ', 'z') == 3);
	
	assert(replaceFirstAndLastOccurrences(folks2, 8, 'a', 'Z') == 8);
	cerr << "All tests succeeded" << endl;
	
	return 0;

}

int locateMaximum(const  string  array[], int  n) { 
	string maximum = array[0];
	int maxIndex = 0;
	if (n <= 0) {
		return -1;
	}
	else {
		
		for (int k = 0; k < n - 1; k++) {  //loops through array
			if (maximum < array[k + 1]) {   // if following element is greater than previous, then the index of the greater element becomes the new maximum index
				maximum = array[k + 1];
				maxIndex = k + 1;
			}

		}
	}return maxIndex;
}
bool digitsAndDecimals(string s) { //helper function for floating point function
	bool result = true;
	int badCount = 0;
	
	int decimalCount = 0;
	for (size_t i = 0;i < s.size();i++) {   //loops through string and counts how many decimal characters are in the string
		if (s.at(i) == '.')

			decimalCount++;
	}for (size_t i = 0;i < s.size();i++) {
		if (!((s.at(i) >= '0' && s.at(i) <= '9') || s.at(i) == '.')) //loops through the string, if the character is not a digit or a decimal
			badCount++;                                              //add 1 to badCount to indicate this string does not meet floating point requirement
	}
		
	
	if (badCount==0 && (decimalCount == 0 || decimalCount == 1) && s.size()!=0)  // if there are 0 or 1 decimal points, and no elements that are not digits/decimal points, return true
		return result;
	else
		return (result==false);
	
}

int countFloatingPointValues(const string array[], int  n) { 
	int floatingPointCount = 0;
	

	if (n <= 0) {
		return -1;
	}
	else {
		for (int k = 0;k < n;k++) {
				if (digitsAndDecimals(array[k]))  //using helper function, if string is true (i.e. is a floating point), add 1 to floatingPointCount
					floatingPointCount++;
			
		}
	}
	return floatingPointCount;
}

bool hasNoCapitals(const string array[], int n) { 
	int upperCaseCount = 0;
	if (n <= 0) {
		return true;
	}
	else {
		for (int k = 0;k < n;k++) { //goes through whole array
			for (size_t j = 0; j < array[k].size();j++) {  //goes through each character in string 
				if ((array[k][j] >= 'A' && array[k][j] <= 'Z'))  //if character is between 'A' and 'Z' (inclusive) add 1 to upperCase count
					upperCaseCount++;
			}
		}
	}if (upperCaseCount > 0)
		return false;
	else
		return true;
}

bool identicalValuesTogether(const string array[], int n) { 
	int badCount = 0;
	if (n <= 0) {                                           
		return false;
	}
	else {
		
		for (int k = 0;k < n-1;k++) { //goes through array
			for (int j = k + 1;j < n;j++) { //goes through array and position starts at k+1
				if (array[k] == array[j] && (array[k]!=array[k+1]))  // if elemnt at index k and index j are identical but not next to eachother
					badCount++; //add 1 to the badCount

			}

		}

	}
	
	if (badCount > 0) //if this happens once or more, return false, since the loop found identical values that were not next to eachother
		return false;
	else
		return true;
	
}

bool hasTwoOrMoreDuplicates(const string array[], int  n) { 
	int dupCount = 0;
	if (n <= 0)
		return false;
	else {
		for (int k = 0;k < n;k++) {
			for (int j = k + 1;j < n ;j++) { //loops through array and starts at position k+1
				if (array[k] == array[j]) //if element at index k is identical to element at index j, add to dupCount
					dupCount++;
			}
		}
	}
	if (dupCount >= 2) //if dupCount greater than/equal to 2, return true
		return true;
	else
		return false;
}


int shiftLeft(string array[], int n, int amount, string placeholder) { 
	int placeHolderCount = 0;
	if (n <= 0 || amount < 0)
		return -1;
	else {
		if (amount >= n) {
			for (int j = 0;j < n;j++) { //outer loop will continue while j < n in the case that amount>=n

				for (int k = 0;k < n - 1;k++) {
					array[k] = array[k + 1]; //shifts element to the left



				}array[n - 1] = placeholder; //converts the last element (the original first element that was shifted to the left) into the placeholder
				placeHolderCount++; //adds 1 to count everytime this conversion occurs


			}

		}
		else {
			for (int j = 0;j < amount;j++) { //outer loop will continue while j < amount 

				for (int k = 0;k < n - 1;k++) { //following code follows same pattern as above
					array[k] = array[k + 1];



				}array[n - 1] = placeholder;
				placeHolderCount++;


			}
		}

	} //for (int i = 0;i < n;i++) 
		//  cout << array[i] << " ";
	return placeHolderCount;

	}





int replaceFirstAndLastOccurrences(string array[], int n, char charToFind, char charToReplace) {
	
	int replaceCount = 0;
	int minIndex = 0;
	
	if (n <= 0)
		return -1;
	else {
		for (int k = 0;k < n;k++) { //loops through each string in array
			for (size_t j = 0; j < array[k].size();j++) { //loops through each character in string to find first occurrence
				if (array[k][j] == charToFind) { // if element is charToFind
					array[k][j] = charToReplace; //convert to charToReplace
					replaceCount++; //add 1 to count
					minIndex = j; //keep track of the index where the first occurrence happens and break
					break;
				}
			}for (int i = array[k].size() - 1; i >= 0; i--) {//loops through each character in string backwards to find last occurrence
				if (array[k][i] == charToFind) { //if character is charToFind and it was not found at the same index as the first occurrence
					if (i != minIndex) {
						array[k][i] = charToReplace;  //convert to charToReplace
						replaceCount++; //add 1 to count and break
						break;
					}
				}
				else if (array[k][i]==charToFind && i==minIndex) //else if charToFind is found at index of first occurrence, don't do anything and break
					break;

			}
		}
	}
	return replaceCount; //return the count
}

				



