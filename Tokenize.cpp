#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> splitString(const string &input, char delimiter)
{
    vector<string> tokens;
    istringstream tokenStream(input);
    string token;

    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
{
    string input = "apple,banana,cherry,date";

    char delimiter = ',';
    vector<string> tokens = splitString(input, delimiter);

    for (const string &token : tokens)
    {
        cout << token << endl;
    }

    return 0;
}
