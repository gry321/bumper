#pragma once
#ifndef _FUNCTION_FORMAT_H
#define _FUNCTION_FORMAT_H
#include <iostream>
#include <map>
#include <vector>
#define MAX_PARAM_NUM 1024
using namespace std;
namespace FunctionFormat
{
    typedef struct
    {
        string paramName;
        string paramType;
    } functionParam_t;
    typedef struct
    {
        // string name;
        functionParam_t params[MAX_PARAM_NUM];
        string returnType;
    } function_no_name_t;
    typedef struct
    {
        string name;
        functionParam_t params[MAX_PARAM_NUM];
        string returnType;
    } function_t;
    typedef struct
    {
        string name;
        string params[MAX_PARAM_NUM];
    } callFunction_t;
}

void toRun(FunctionFormat::callFunction_t function, map<string, string> *variables, map<string, FunctionFormat::function_no_name_t> *functions, vector<string> *ids, vector<string> *memories);
string bprStringToString(string bprString);
#endif