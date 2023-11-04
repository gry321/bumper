#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>
#include "functionFormat.h"

#define NO_FILENAME "wf.bpr"
#define MAX_PARAM_NUM 1024
#define MAX_FUNCTION_NUM 8192

using namespace std;

void trimAllSpaces(string &str);
void runOneRowCode(string &rowCode, map<string, string> *variables, map<string, FunctionFormat::function_no_name_t> *functions, vector<string> *ids, vector<string> *memories);
void stringSplit(string str, const char split, vector<string> &res);
void stringSplit(string str, const char split, string res[]);
bool analyzeFunction(string &rowCode, FunctionFormat::callFunction_t &function);
bool analyzeFunction(string &rowCode, FunctionFormat::function_t &function);
int main(int argc, char *argv[])
{
    string fileName;
    if (argc == 1)
    {
        cout << "Error: No FileName" << endl;
        exit(1);
    }
    else
    {
        fileName = argv[1];
    }
    // cout << "FileName: " << fileName << endl;

    ifstream file(fileName);
    if (!file)
    {
        cout << "Error: Failed to open the file." << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();

    string data = buffer.str();
    // trimAllSpaces(data);
    file.close();
    cout << "Test:" << endl
         << data;
    // Init
    map<string, string> variables;
    map<string, FunctionFormat::function_no_name_t> functions;
    vector<string> varFuncIds;
    vector<string> memories;
    // Over
    vector<string> lines;
    stringSplit(data, '\n', lines); // Not ";".Because my wish is don't write ";" in your codes.
    for (long long i = 0; i < lines.size(); i++)
    {
        // cout << "Count " << i << ": " << lines[i] << endl;
        runOneRowCode(lines[i], &variables, &functions, &varFuncIds, &memories);
    }

    return 0;
}

void trimAllSpaces(string &str)
{
    int index = 0;
    if (!str.empty())
    {
        while ((index = str.find(' ', index)) != string::npos)
        {
            str.erase(index, 1);
        }
    }
}

void runOneRowCode(string &rowCode, map<string, string> *variables, map<string, FunctionFormat::function_no_name_t> *functions, vector<string> *ids, vector<string> *memories)
{
    FunctionFormat::callFunction_t function;
    if (analyzeFunction(rowCode, function))
    {
        toRun(function, variables, functions, ids, memories);
    }
    // free(&function);
}

void stringSplit(string str, const char split, vector<string> &res)
{
    istringstream iss(str);
    string token;
    while (getline(iss, token, split))
    {
        res.push_back(token);
    }
}
void stringSplit(string str, const char split, string res[])
{
    istringstream iss(str);
    string token;
    long param_number = 0;
    while (getline(iss, token, split))
    {
        res[param_number] = token;
        param_number++;
    }
}

bool analyzeFunction(string &rowCode, FunctionFormat::callFunction_t &function)
{
    // use regex
    string rule = "(\\w+)\\(([^()]+)\\)";
    regex r(rule);
    smatch m;
    string args[MAX_PARAM_NUM] = {};
    if (regex_match(rowCode, m, r))
    {
        function.name = m[1];
        stringSplit(m[2], ',', args);
        function.params->clear();
        for (int i = 0; i < args->size(); i++)
        {
            function.params->append(args[i]);
        }
        return true;
    }
    else
    {
        return false;
    }
}