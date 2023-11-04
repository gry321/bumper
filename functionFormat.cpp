#include "functionFormat.h"

void toRun(FunctionFormat::callFunction_t function, map<string, string> *variables, map<string, FunctionFormat::function_no_name_t> *functions, vector<string> *ids, vector<string> *memories)
{
    if (function.name == "print")
    {
        for (int i = 0; i < MAX_PARAM_NUM; i++)
        {
            if (function.params[i] != "")
            {
                cout << bprStringToString(function.params[i]) << endl;
            }
            else
            {
                break;
            }
        }
    }
}
// From "bumper" to bumper.
string bprStringToString(string bprString)
{
    string retVal = "";
    short temp = 0;
    char firstChar = bprString[0];
    char endChar = bprString[bprString.size() - 1];
    if ((firstChar == '"' && endChar == '"') || (firstChar == '\'' && endChar == '\''))
    {
        retVal += bprString.substr(1, bprString.size() - 2);
    }
    for (int i = 0 + 1; i < bprString.size() - 1; i++)
    {
        if (temp == 1)
        {
            /*             if (bprString[i] == '\\')
                        {
                            retVal += "\\";
                        }
                        else if (bprString[i] == '"')
                        {
                            retVal += """;
                        }
                        else if (bprString[i] == '\'')
                        {
                            retVal += "\'";
                        }
                        else if (bprString[i] == 'n')
                        {
                            retVal += "\n";
                        }
                        else if (bprString[i] == 't')
                        {
                            retVal += "\t";
                        }
                        else if (bprString[i] == 'r')
                        {
                            retVal += "\r";
                        }
                        else if (bprString[i] == 'b')
                        {
                            retVal += "\b";
                        }
                        else if (bprString[i] == 'f')
                        {
                            retVal += "\f";
                        }
                        else if (bprString[i] == 'a')
                        {
                            retVal += "\a";
                        } */
            switch (bprString[i])
            {
            case '\\':
                retVal += "\\";
                break;
            case '"':
                retVal += "\"";
                break;
            case '\'':
                retVal += "'";
                break;
            case 'n':
                retVal += "\n";
                break;
            case 't':
                retVal += "\t";
                break;
            case 'r':
                retVal += "\r";
                break;
            case 'b':
                retVal += "\b";
                break;
            case 'f':
                retVal += "\f";
                break;
            case 'a':
                retVal += "\a";
                break;
            default:;
            }
            temp = 0;
        }
        if (bprString[i] == '\\')
        {
            temp = 1;
            continue;
        }
        retVal[i] += bprString[i];
    }
    return retVal;
}