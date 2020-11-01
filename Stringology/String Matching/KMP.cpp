/*
 * Knuth Morris Pratt algorithm (KMP)
 * Version 1.2
 * Author: WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (C) 2018 WildfootW All rights reserved.
 *
 */

// Alternative KMP
// * Put pattern in front of text and directly use calculate failure function
//
// Alternative Fail Function
// * failure value = Second Longest Proper Prefix-Suffix Length
// * if failure > pattern length, considered as not equal (allow_overlap)
// * if failure > pattern length, failure go back to 0 (!allow_overlap)

// [TODO]
// * fix text: NANANA, pattern: ANANA in !allow_overlap

// Allow Overlap = True (Default)
// Text: ANANANA
// Pattern: ANA
// A N A A N A N A N A
// 0 0 1 1 2 3 2 3 2 3
// Matched!
// ANANANA
// ⤴ ⤴ ⤴
//
// Allow Overlap = False
// Text: ANANANA
// Pattern: ANA
// A N A A N A N A N A
// 0 0 1 1 2 3 0 1 2 3
// Matched!
// ANANANA
// ⤴   ⤴

#include <iostream>
#include <vector>

using namespace std;

#ifndef KNUTHMORRISPRATT_HPP
#define KNUTHMORRISPRATT_HPP
class KnuthMorrisPratt
{
private:
#ifndef NDEBUG
    inline string fix_alignment(string para) const;
#endif // NDEBUG

protected:
    string text, pattern;
    vector<int> answer_pos; //answer text[answer_pos] == pattern[0]
    vector<int> failure; // second longest proper prefix-suffix length

    void calculate_failure(bool allow_overlap);
    void matching();

#ifndef NDEBUG
    void print_failure() const;
#endif // NDEBUG

public:
    KnuthMorrisPratt(string text, string pattern):
        text(text), pattern(pattern), failure(text.length() + pattern.length())
    {
    }

    vector<int> answer(bool allow_overlap = true);
};

#ifndef NDEBUG
inline string KnuthMorrisPratt::fix_alignment(string para) const
{
    const int alignment_num = 2;
    para.resize(alignment_num, ' ');
    return para;
}
#endif // NDEBUG

void KnuthMorrisPratt::calculate_failure(bool allow_overlap)
{
    failure[0] = 0;
    string combine_str = pattern + text;

    for(int i = 1, j = 0;i < combine_str.length();++i)
    {
        if(failure[i - 1] == pattern.length()) // failure[i - 1] == pattern.length() is my own alternative for in case failure > pattern length (z.B. ABZABC ABZABCABZABC)
        {
            if(allow_overlap)
                j = failure[j - 1];
            else
                j = 0;
        }

        while(combine_str[i] != combine_str[j] && j > 0)
        {
            j = failure[j - 1];
        }
        if(combine_str[i] == combine_str[j])
        {
            failure[i] = ++j;
        }
        else
        {
            failure[i] = 0;
        }
    }
}

void KnuthMorrisPratt::matching()
{
    for(int i = pattern.size() - 1;i < text.length();++i) // i = pattern.size() is avoid ... (z.B. text: 0110, pattern: 101, result should be 0 but 1)
    {
        if(failure[pattern.length() + i] == pattern.length())
        {
            answer_pos.push_back(i - pattern.length() + 1);
        }
    }
    return;
}

#ifndef NDEBUG
void KnuthMorrisPratt::print_failure() const
{
    for(int i = 0;i < pattern.length();++i)
        clog << fix_alignment(string(1, pattern[i]));
    for(int i = 0;i < text.length();++i)
        clog << fix_alignment(string(1, text[i]));
    clog << endl;

    for(int i = 0;i < (pattern.length() + text.length());++i)
        clog << fix_alignment(to_string(failure[i]));
    clog << endl;
}
#endif // NDEBUG

vector<int> KnuthMorrisPratt::answer(bool allow_overlap)
{
    calculate_failure(allow_overlap);

#ifndef NDEBUG
    print_failure();
#endif // NDEBUG

    matching();

#ifndef NDEBUG
    if(answer_pos.size() == 0)
    {
        clog << "Nothing Matched." << endl;
    }
    else
    {
        clog << "Matched! " << answer_pos.size() << endl;
        clog << text << endl;
        int idx = 0;
        for(int i = 0;i < text.length() && idx < answer_pos.size();++i)
        {
            if(i == answer_pos[idx])
            {
                clog << "⤴";
                ++idx;
            }
            else
                clog << " ";
        }
        clog << endl;
    }
#endif // NDEBUG

    return answer_pos;
}

#endif // KNUTHMORRISPRATT_HPP

int main()
{
    while(true)
    {
        string text, pattern;
        cout << "Text: ";
        getline(cin, text);
        cout << "Pattern: ";
        getline(cin, pattern);

        KnuthMorrisPratt test(text, pattern);
//        test.answer(true);
        test.answer(false);
    }
    return 0;
}

