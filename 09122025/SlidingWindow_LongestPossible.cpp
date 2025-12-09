#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int max_len(string s, int k){
    int mx_len = 0;
    int ans = k;
    int left = 0, right = 0;
    vector<int> freq(26,0);
    while(right < s.size()){
        freq[s[right]-'A']++;
        mx_len = max(mx_len, freq[s[right]-'A']);
        if((right - left + 1) - mx_len > k){
            freq[s[left]-'A']--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}
int main(){
    string s;
    int k;
    cin>>s>>k;
    cout<<max_len(s,k);
}