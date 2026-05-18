#include <bits/stdc++.h>
using namespace std;

// Function to demonstrate basic string concepts
void stringBasics()
{
    // * String declaration and initialization
    string s1 = "Hello";
    string s2("World");
    string s3;   // empty string

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3 (empty): " << s3 << endl;

    // * String input
    string name;
    cout << "\nEnter your first name: " ;
    cin >> name;   // reads only one word

    string fullName;
    cout << "Enter your full name: ";

    // ! Always clear input buffer before getline
    cin.ignore();

    getline(cin, fullName);   // reads complete line

    cout << "Name: " << name << endl;
    cout << "Full Name: " << fullName << endl;

    // * String length
    cout << "\nLength of full name: " << fullName.length() << endl;

    // * Accessing characters in a string
    cout << "\nCharacters in s1: ";
    for (int i = 0; i < s1.length(); i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;

    // * String concatenation
    string combined = s1 + " " + s2;
    cout << "\nConcatenated string: " << combined << endl;

    // ? append() can also be used for concatenation
    string temp = s1;
    temp.append(" ").append(s2);
    cout << "Using append(): " << temp << endl;

    // * String comparison
    string a = "apple";
    string b = "banana";

    if (a == b)
        cout << "\nStrings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;

    // * Substring extraction
    string sub = combined.substr(0, 5);
    cout << "\nSubstring: " << sub << endl;

    // * Finding substring
    int pos = combined.find("World");

    // ! find() returns string::npos if not found
    if (pos != string::npos)
        cout << "'World' found at index: " << pos << endl;
    else
        cout << "'World' not found" << endl;

    // * Modifying string characters
    string modify = "hello";
    for (char &c : modify)
        c = toupper(c);

    cout << "\nUppercase string: " << modify << endl;

    // * Reversing a string
    string rev = "Cplusplus";
    reverse(rev.begin(), rev.end());
    cout << "Reversed string: " << rev << endl;

    // * Checking empty string
    string emptyStr;
    if (emptyStr.empty())
        cout << "\nString is empty" << endl;

    // * Clearing a string
    string clearExample = "Clear me";
    clearExample.clear();
    cout << "Length after clear(): " << clearExample.length() << endl;
}

int main()
{
    stringBasics();   // function call only
    return 0;
}
