字串 string
    字元的有序序列
    ai ∈ 字元集,n 是字串的長度
子字串 substring
    A 連續的一段
子序列 subsequence
    不連續
後綴 suffix
    A 的一個子字串
前綴 prefix
    A 的一個子字串

example:
S = "abcbbab"
    子字串: "bcb","bba", ...
    子序列: "acb","bbb", ...
    前綴: "abcb","ab", ...
    後綴: "bbab","ab", ...

prefix : KMP, AC automata
Suffix : Suffix Array , Suffix Auto mata
Palindrome: Trit

cow Xor virtual_judge


LCP
Longest Common Prefix
排序後 兩兩取相同 最後取min


Suffix Array
banana/0
0123456
0#           6       4
1a#          5       3
2ana#        3       6
3anana#      1       2
4banana#     0       5
5na#         4       1
6nana#       2       0
            SA      Rank

