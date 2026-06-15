#include <bits/stdc++.h>
using namespace std;

// Single character to ASCII
void charToASCII()
{
    char c = 'A';
    cout << "Char to ASCII: " << c << " -> " << (int)c << endl;
}

// ASCII to character
void asciiToChar()
{
    int ascii = 65;
    cout << "ASCII to Char: " << ascii << " -> " << (char)ascii << endl;
}

// String to binary
void stringToBinary()
{
    string s = "Hi";
    cout << "String to Binary: " << s << " -> ";
    for (char c : s)
        cout << bitset<8>((int)c).to_string() << " ";
    cout << endl;
}

// String to decimal (numeric string)
void stringToDecimal()
{
    string s = "12345";
    cout << "String to Decimal: " << s << " -> ";
    cout << stoi(s) << " (stoi)";
    cout << ", " << stol(s) << " (stol)";
    cout << ", " << stoll(s) << " (stoll)";
    cout << endl;
}

// String to float/double
void stringToFloat()
{
    string s1 = "3.14", s2 = "2.718";
    cout << "String to Float: " << s1 << " -> " << stof(s1) << endl;
    cout << "String to Double: " << s2 << " -> " << stod(s2) << endl;
}

// Digit character to digit
void digitCharToDigit()
{
    string s = "12345";
    cout << "Digit Char to Digit: " << s << " -> ";
    for (char c : s)
        cout << (c - '0') << " ";
    cout << endl;
}

// Hex string to decimal
void hexStringToDecimal()
{
    string hexStr = "1F";
    cout << "Hex to Decimal: " << hexStr << " -> " << stoi(hexStr, nullptr, 16) << endl;
}

// Decimal to binary
void decimalToBinary()
{
    int num = 10;
    cout << "Decimal to Binary: " << num << " -> " << bitset<8>(num).to_string() << endl;
}

// Integer/Float to string
void intToString()
{
    int num = 42;
    cout << "Integer to String: " << num << " -> " << to_string(num) << endl;

    float num = 3.14;
    cout << "Float to String: " << num << " -> " << to_string(num) << endl;
}

// Binary string to decimal
void binaryStringToDecimal()
{
    string binary = "1010";
    cout << "Binary to Decimal: " << binary << " -> " << stoi(binary, nullptr, 2) << endl;
}

// String case conversion
void stringCaseConversion()
{
    string s = "Hello World";
    string upper = s, lower = s;
    transform(upper.begin(), upper.end(), upper.begin(), ::toupper);
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    cout << "Original: " << s << endl;
    cout << "Uppercase: " << upper << endl;
    cout << "Lowercase: " << lower << endl;
}

// Character type checking
void charTypeChecking()
{
    cout << "\nCharacter Type Checking:" << endl;
    string s = "Hello123!";
    for (char c : s)
    {
        cout << "'" << c << "': ";
        if (isalpha(c)) cout << "alpha ";
        if (isdigit(c)) cout << "digit ";
        if (ispunct(c)) cout << "punct";
        cout << endl;
    }
}

// Reverse string
void reverseString()
{
    string s = "Hello";
    reverse(s.begin(), s.end());
    cout << "Reverse: Hello -> " << s << endl;
}

// Check if string is numeric
void isNumericString()
{
    cout << "Is Numeric Check: ";
    vector<string> test = {"12345", "12.34", "abc123"};
    for (string s : test)
    {
        bool isNum = all_of(s.begin(), s.end(), ::isdigit);
        cout << s << "(" << (isNum ? "Y" : "N") << ") ";
    }
    cout << endl;
}

// Split string by delimiter
void splitString()
{
    string s = "apple,banana,cherry";
    cout << "Split 'apple,banana,cherry' by ',': ";
    size_t pos = 0;
    while ((pos = s.find(",")) != string::npos)
    {
        cout << s.substr(0, pos) << " | ";
        s.erase(0, pos + 1);
    }
    cout << s << endl;
}

// Built-in functions reference
void builtInFunctionsReference()
{
    cout << "\n=== BUILT-IN FUNCTIONS ===" << endl;

    // Number system conversions
    cout << "\nNumber systems:" << endl;
    cout << "stoi(\"1F\", 0, 16) = " << stoi("1F", nullptr, 16) << " (hex)" << endl;
    cout << "stoi(\"1010\", 0, 2) = " << stoi("1010", nullptr, 2) << " (binary)" << endl;

    // Character checks not in examples
    cout << "\nCharacter checks:" << endl;
    cout << "isalnum('5') = " << isalnum('5') << ", isalnum('!') = " << isalnum('!') << endl;
    cout << "isspace(' ') = " << isspace(' ') << ", isspace('A') = " << isspace('A') << endl;

    // String operations
    string s = "Hello World";
    cout << "find(\"World\") = " << s.find("World") << endl;
    cout << "substr(0, 5) = " << s.substr(0, 5) << endl;
    cout << "length() = " << s.length() << endl;
    
    s = "Hello";
    reverse(s.begin(), s.end());
    cout << "reverse(\"Hello\") = " << s << endl;

    string str = "Hello";
    str.append(" World");
    cout << "append() = " << str << endl;

    str = "Hello World";
    str.replace(6, 5, "C++");
    cout << "replace() = " << str << endl;

    cout << "compare(\"abc\", \"abc\") = " << string("abc").compare("abc") << endl;

    str = "Hello";
    str.clear();
    cout << "clear() = \"" << str << "\" (length=" << str.length() << ")" << endl;

    // Algorithm functions not in examples
    cout << "\nAlgorithm functions:" << endl;
    string mixed = "abc123";
    cout << "any_of(\"abc123\", isdigit) = " << any_of(mixed.begin(), mixed.end(), ::isdigit) << endl;

    int cnt = count(string("banana").begin(), string("banana").end(), 'a');
    cout << "count('a' in \"banana\") = " << cnt << endl;

    // I/O functions
    cout << "\nI/O functions:" << endl;
    stringstream ss;
    ss << hex << 255;
    cout << "stringstream: 255 in hex = " << ss.str() << endl;

    char buffer[50];
    sprintf(buffer, "Hex of 255: %X, Octal: %o", 255, 255);
    cout << "sprintf: " << buffer << endl;

    // Math functions
    cout << "\nMath functions:" << endl;
    cout << "abs(-42) = " << abs(-42) << endl;
    cout << "pow(2, 3) = " << pow(2, 3) << endl;
    cout << "floor(3.7) = " << floor(3.7) << endl;
    cout << "ceil(3.2) = " << ceil(3.2) << endl;
}

// Main function
int main()
{
    charToASCII();
    asciiToChar();
    stringToBinary();
    stringToDecimal();
    stringToFloat();
    digitCharToDigit();
    hexStringToDecimal();
    decimalToBinary();
    intToString();
    binaryStringToDecimal();
    stringCaseConversion();
    charTypeChecking();
    reverseString();
    isNumericString();
    splitString();

    // Show all built-in functions reference
    builtInFunctionsReference();

    return 0;
}
