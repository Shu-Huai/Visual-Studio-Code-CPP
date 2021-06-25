#pragma once
#ifndef __PATTERN_MATCHING_H__
#define __PATTERN_MATCHING_H__
#include <iostream>
using namespace std;
class PatternMatching
{
protected:
    static int *GetFailure(string &pat);

public:
    static int BruteForcePatternMatching(string &ob, string &pat);
    static int KMPPatternMatching(string &ob, string &pat);
};
int *PatternMatching::GetFailure(string &pat)
{
    int j = 0;
    int k = -1;
    int *failure = new int[pat.length()];
    failure[0] = -1;
    while (j < int(pat.length()) - 1)
    {
        if (k == -1 || pat[j] == pat[k])
        {
            j++;
            k++;
            failure[j] = k;
        }
        else
        {
            k = failure[k];
        }
    }
    return failure;
}
int PatternMatching::BruteForcePatternMatching(string &ob, string &pat)
{
    int i = 0;
    int j = 0;
    while (j < int(pat.length()) && i < int(ob.length()) && int(pat.length()) - j <= int(ob.length()) - i)
    {
        if (ob[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j >= int(pat.length()))
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}
int PatternMatching::KMPPatternMatching(string &ob, string &pat)
{
    int *failure = GetFailure(pat);
    int i = 0;
    int j = 0;
    while (j < int(pat.length()) && i < int(ob.length()) && int(pat.length()) - j <= int(ob.length()) - i)
    {
        if (j == -1 || ob[i] == pat[j])
        {
            i++;
            j++;
        }
        else
        {
            j = failure[j];
        }
    }
    delete[] failure;
    if (j >= int(pat.length()))
    {
        return i - j;
    }
    return -1;
}
#endif