#pragma once
#ifndef __PATTERN_MATCHING_H__
#define __PATTERN_MATCHING_H__
#include <iostream>
using namespace std;
class PatternMatching
{
protected:
    static void GetFailure(string &pat, int *failure);

public:
    static int BruteForcePatternMatching(string &ob, string &pat);
    static int KMPPatternMatching(string &ob, string &pat);
};
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
void PatternMatching::GetFailure(string &pat, int *failure)
{
    int j = 0;
    int k = -1;
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
}
int PatternMatching::KMPPatternMatching(string &ob, string &pat)
{
    int *failure = new int[pat.length()];
    GetFailure(pat, failure);
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
    if (j >= int(pat.length()))
    {
        return i - j;
    }
    return -1;
}
#endif