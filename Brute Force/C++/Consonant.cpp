// SOLUTION: Brute Force (Vét Cạn)
#include <iostream>
#include <math.h>
#include <cctype>
using namespace std;

bool kiem_tra_nguyen_am(char c)
{
    /*
    Hàm được dùng để kiểm tra một kí tự có phải là nguyên âm hay không
    Args:
       c (char): Kí tự c (s[i]) cần kiểm tra
    Returns:
       True nếu c là nguyên âm và False nếu c không phải là nguyên âm
    */
    return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i' || c == 'w' || c == 'y';
}

void consonant(string &s)
{
    /*
    Hàm chính được dùng để giải quyết bài toán
    Args:
       s (str): Xâu kí tự s cần biến đổi
    */
    int index_phu_am[256];
    for (int i = 0; i < 256; i++)
    {
        index_phu_am[i] = -1;
    }
    int index = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (kiem_tra_nguyen_am(s[i]) == false && index_phu_am[s[i]] == -1)
        {
            index_phu_am[s[i]] = index;
            index += 1;
        }
    }
    int total_mask = int(pow(2, index));
    int freq_tuple_phu_am[19][19] = {0};
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (kiem_tra_nguyen_am(s[i]) == false && kiem_tra_nguyen_am(s[i + 1]) == false)
        {
            int u = index_phu_am[s[i]];
            int v = index_phu_am[s[i + 1]];
            freq_tuple_phu_am[u][v] += 1;
        }
    }
    int max_mask = 0;
    int max_doi_tinh_phu_am = -1;
    for (int mask = 0; mask < total_mask; mask++)
    {
        int doi_tinh_phu_am = 0;
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 19; j++)
            {
                int bit_ki_tu_thu_nhat = (mask >> i) & 1;
                int bit_ki_tu_thu_hai = (mask >> j) & 1;
                if (bit_ki_tu_thu_nhat != bit_ki_tu_thu_hai)
                {
                    doi_tinh_phu_am += freq_tuple_phu_am[i][j];
                }
            }
        }
        if (doi_tinh_phu_am > max_doi_tinh_phu_am)
        {
            max_doi_tinh_phu_am = doi_tinh_phu_am;
            max_mask = mask;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (kiem_tra_nguyen_am(s[i]) == false)
        {
            int bit_ki_tu = (max_mask >> index_phu_am[s[i]]) & 1;
            if (bit_ki_tu == 1)
            {
                s[i] = toupper(s[i]);
            }
        }
    }
}

int main()
{
    string s;
    cin >> s;
    consonant(s);
    cout << s;
    return 0;
}