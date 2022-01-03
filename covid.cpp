#include <cassert>
#include<cctype>
#include <iostream>
#include <string>
using namespace std;
//Anya Smolentseva 305503018

bool isValidResultString(string results);
bool noSpacesInString(string results);
bool startsWithR(string results);
int extractNumber(string commands, size_t& index, bool& isValid);
bool plusAndNegative(string results);
bool firstZero(string results);
bool leadingZeros(string t);
bool equalsTotal(string t);
bool posNextToNeg(string t);
bool numberBatches(string t);
bool correctCharacters(string s);
int positiveTests(string results);
int negativeTests(string results);
int totalTests(string results);
int batches(string results);

int main() {

    assert(isValidResultString("") == false);
    assert(isValidResultString("    ") == false);
    assert(isValidResultString("1R") == false);
    assert(isValidResultString("R0+1-1") == false);
    assert(isValidResultString("R5+-1") == false);
    assert(isValidResultString("R2+2-0") == true);
    assert(isValidResultString("R5+00003-00002") == false);
    assert(isValidResultString("R50+30-20") == true);
    assert(isValidResultString("R5-2+3") == true);
    assert(isValidResultString("R50+30-25") == false);
    assert(isValidResultString("R50+30-20R10+5-5R2+1-1") == true);
    assert(isValidResultString("R5+3-2R") == false); 
    assert(isValidResultString("R5+3-2h") == false);
    assert(positiveTests("R2+1-1") == 1);
    assert(positiveTests("R5+2-3R5+2-6") == -1);
    assert(negativeTests("R2+1-1") == 1);
    assert(totalTests("R2+1-1") == 2);
    assert(batches("R2+2-0") == 1);
    assert(isValidResultString("R5") == false);
    assert(isValidResultString("R5+3+2R1-1-0") == false);
    assert(batches("R2+1-1R3+2-1") == 2);
    assert(totalTests("R100+50-50R10+5-5") == 110);
    assert(negativeTests("R5+3-2R20+0-20") == 22);
    assert(negativeTests("R5+6-1R3+2-1") == -1);
    assert(totalTests("R5+3-3R2-1+4") == -1);
    assert(batches("R5+0001-00004") == -1);
    assert(positiveTests("R10-7+3R0+0-0") == -1);
    assert(negativeTests("R200+150-50R5+-32") == -1);
    assert(totalTests("R1+1-0R2+2-0R1+1-0") == 4);
    assert(batches("R100+-100") == -1);

    cerr << "All tests succeeded" << endl;
    return(0);

}


bool isValidResultString(string results)
{

    return (noSpacesInString(results) && startsWithR(results) && correctCharacters(results) && plusAndNegative(results) && posNextToNeg(results) && firstZero(results) && leadingZeros(results) && equalsTotal(results) && numberBatches(results));
}
// isValidResultString function broken down into multiple functions that return boolean values. If one function returns false, isValidResultString
// automatically returns false

bool noSpacesInString(string s) { //checks that string is not less than the minimum length and that there are no spaces in the string
    if (s.size() < 6)
        return (false);
    else
    {
        for (int i = 0; i != s.size(); i++)
            if (s[i] == ' ')
                return(false);
    }
    return (true);
}

bool correctCharacters(string s) //checks that the string only has digits, +, -, and R. All other characters are invalid
{
    for (int k = 0; k != s.size(); k++)
    {
        if (s[k] != 'R' && (!(isdigit(s[k]))) && s[k] != '+' && s[k] != '-')
            return false;
    }
    return true;
}


bool startsWithR(string n) { //checks that the string starts with R, otherwise return false
    if (n[0] == 'R')
        return (true);
    else
        return (false);
}
int extractNumber(string commands, size_t& index, bool& isValid)
{
    // track the integer value found
    int quantity(0);

    //return quantity;



    // the number can't start with a zero!
    if (commands.at(index) >= '1' && commands.at(index) <= '9')
    {
        // the number should be made up of digits
        while (index < commands.length() &&
            (commands.at(index) >= '0' && commands.at(index) <= '9'))
        {
            // extract one digit and add it to the cumulative value
            // held in quantity "123" ---> 123
            int digit = commands.at(index) - '0';
            quantity = quantity * 10 + digit;
            index = index + 1;
        }
    }
    // once we run out of digits to consume, the cumulative quantity
    // must not still be zero
    isValid = (quantity != 0);
    return(quantity);

}

bool plusAndNegative(string results) //checks to validate + and - in the string
{
    int totalminus = 0;
    int totalplus = 0;
    int rCount = 0;
    for (size_t i = 0; i < results.size() - 1;i++) { //loops through the string
        if (isdigit(results.at(i))) {
            i++;
            if (results.at(i) == '+')
                totalplus++; //adds to count everytime the character is +
            else if (results.at(i) == '-')
                totalminus++; // adds to count everytime the character is -
            i--;
        }
    }
    for (int k = 0; k != results.size(); k++) { //checks how many R characters are in the string
        if (results[k] == 'R')
            rCount++;


    }

    if (totalplus == totalminus && totalminus >= 1 && totalplus >= 1 && totalplus == rCount) //checks that the total amount of '+' and total
        return true;                                                                         // amount of '-' equal eachother, checks that the
    else                                                                                     // string has at least 1 '+' and at least one '-'
        return false;                                                                        // checks that the number of R characters is equal to amount of '+'
}                                                                                            // since one batch can only have one '+' and one '-' 
 
bool posNextToNeg(string results) { //checks that there aren't 2 '+' in one batch or 2 '-' in one batch
    string t;
    for (size_t k = 0; k != results.size(); k++)
        if (!(isdigit(results.at(k)))) {  //if character is R, or +, or -, append it to a new list t
            t += results[k];
        }
    for (size_t j = 0; j < t.size() - 1;j++)
        if (t.at(j) == '+') { // if character is '+' and next character is '+', that means there are 2 '+' in one batch, therefore invalid
            j++;
            if (t.at(j) == '+')
                return false;
            j--;
        }
        else if (t.at(j) == '-') { //same as above, but with '-' character
            j++;
            if (t.at(j) == '-')
                return false;
            j--;
        }
    return true;
}






bool firstZero(string results) { //checks that if character is 'R', next character isn't a 0, since a batch can't have 0 total cases.
    for (size_t k =0; k!=results.size(); k++)
        if (results.at(k) == 'R') {
            k++;
            if (results.at(k) == '0')
                return false;
        }
    return true;
    
}

bool leadingZeros(string t) { //checks for leading zeros, if digit starts with 0 and a digit afterwards, then it is a leading zero and invalid
    for (size_t k = 0; k < t.size() - 2; k++) {
        if (t.at(k) == '-' || t.at(k) == '+') { //if character is '+' or '-'
            k++;                                // increment and check next character
            if (t.at(k) == '0') {               // if character is '0'
                k++;                            // increment
                if (isdigit(t.at(k)))           // if next character is a digit, false
                    return false;
            }


        }



    } return true;
}
           






bool equalsTotal(string t) { //checks that positive cases and negative cases equal total cases
    int numberCases = 0;
    int totalCases = 0;
    
    bool c = true;

    for (size_t k = 1; k < t.size()-1; k++) {
        if (t.at(k) == '-' || t.at(k) == '+') { // if character is '+' or '-', extract the next position to find the amount of negative/positive cases
            k++;
            numberCases = extractNumber(t, k, c) + numberCases; //adds up all the positive and negative cases
            k--;
            
        }    

    }
    for (size_t i = 0; i != t.size(); i++) { //if character is 'R', extract the next position to find the amount of total cases
        if (t.at(i) == 'R') {
            i++;
            totalCases = extractNumber(t, i, c) + totalCases; //adds up total cases
            i--;
        }

    }
    if (totalCases == numberCases) 
        return true;
    else
        return false;
}
    




bool numberBatches(string t) { //validates that there can be multiple batches in one string, by stating that there can be more than one 'R'
    int rCount = 0;
    
    for (int k = 0; k != t.size(); k++) {
        if (t[k] == 'R')
            rCount++;
            
         
    }
    if (rCount > 0)
        return true;
    else
        return false;
    

}

///////////////////////////////////////////////////////////////////////////////////////////////
int positiveTests(string results) {
    int amount = -1;
    int positiveCases = 0;
    bool c = true;
    if (isValidResultString(results) == false)
        return amount;
    else
    {
        for (size_t k = 0; k != results.size();k++)
            if (results[k] == '+') { // if character is '+', goes to next index and turns value into digit to find value of positive cases
                k++;
                positiveCases = extractNumber(results, k, c) + positiveCases;
                k--;
            }
    } return (positiveCases);

}
///////////////////////////////////////////////////////////////////////////
int negativeTests(string results) {
    int amount = -1;
    int negativeCases = 0;
    bool c = true;
    if (isValidResultString(results) == false)
        return amount;
    else {
        for (size_t k = 0; k != results.size();k++) // if character is '-', go to next position and turns value into digit to find value of negative cases
            if (results[k] == '-') {
                k++;
                negativeCases = extractNumber(results, k, c) + negativeCases;
                k--;
            }
    }return negativeCases;
}
//////////////////////////////////////////////////////////
int totalTests(string results) {
    int amount = -1;
    int totalCases = 0;
    bool c = true;
    if (isValidResultString(results) == false)
        return amount;
    else {
        for (size_t i = 0; i != results.size();i++) // if character is 'R', go to next position and turn value into digit to find value of total cases
            if (results[i] == 'R') {
                i++;
                totalCases = extractNumber(results, i, c) + totalCases;
                i--;
            }

    }return totalCases;
}
///////////////////////////////////////////////////////////////
int batches(string results) {
    int amount = -1;
    int rCount = 0;
    if (isValidResultString(results) == false)
        return amount;
    else {
        for (int k = 0; k != results.size();k++) { //counts how many 'R's are in the string and returns the amount
            if (results[k] == 'R')
                rCount++;
        }

    }return rCount;

}