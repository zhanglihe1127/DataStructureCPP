#include<iostream>
#include<algorithm>
#include<string>

// reference: https://www.cnblogs.com/maybe2030/p/5469877.html
// Longest-Common-Subsequence 最长公共子序列
// Longest-Common-Substring 最长公共子串

using namespace std;


class Solution
{
    public:
        int lcs(string str1, string str2){
            int s1_len = str1.length();
            int s2_len = str2.length();

            int a[s1_len+1][s2_len+1];

            for(int i=0; i<=s1_len; i++){
                for(int j=0; j<=s2_len; j++){
                    if(i==0 || j==0){
                        a[i][j] = 0;
                    }else if(str1[i-1] == str2[j-1]){
                        a[i][j] = a[i-1][j-1] + 1;
                    }else{
                        a[i][j] = max(a[i-1][j], a[i][j-1]);
                    }
                }
            }

            return a[s1_len][s2_len];
        }
};

int main()
{   
    // abcfbc abfcab        4
    // programming contest  2
    // abcd mnp             0

    string s1 = "programming";
    string s2 = "contest";
    
    Solution method;
    int lcs_val = method.lcs(s1, s2);

    cout << "Longest-Common-Substring: " << lcs_val << endl;

    return 0;
}