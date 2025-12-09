#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Question:

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
Return the length of the longest substring containing the same letter you can get after performing the above operations.
*/

/*
       we can have running maxFreq value - so here recomputing the value can be bypassed and use the latest maxFreq value
    here first we found the max possible length from there we are checking if current length represents max possible if not we are moving left pointer one step ahead.
*/
int max_len(string s, int k)
{
    int mx_len = 0;
    int ans = k;
    int left = 0, right = 0;
    vector<int> freq(26, 0);
    while (right < s.size())
    {
        freq[s[right] - 'A']++;
        mx_len = max(mx_len, freq[s[right] - 'A']);
        if ((right - left + 1) - mx_len > k)
        {
            freq[s[left] - 'A']--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}
int main()
{
    string s;
    int k;
    cin >> s >> k;
    cout << max_len(s, k);
}