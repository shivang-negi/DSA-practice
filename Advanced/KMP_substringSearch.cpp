#include <iostream>
using namespace std;
 
int KMP(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();
 
    if (n == 0) return 1;
    if (m < n) return 0;

    int next[n + 1];
    for (int i = 0; i < n + 1; i++) next[i] = 0;
    
    for (int i = 1; i < n; i++) {
        int j = next[i + 1];
        while (j > 0 && pattern[j] != pattern[i]) j = next[j];
        if (j > 0 || pattern[j] == pattern[i]) next[i + 1] = j + 1;
    }
 
    for (int i = 0, j = 0; i < m; i++) {
        if (text[i] == pattern[j]) {
            if (++j == n)
                return 1;
        }
        else if (j > 0) {
            j = next[j];
            i--;  
        }
    }
    return 0;
}
 
int main()
{
    string text = "ABCABAABCABAC";
    string pattern = "CAB";
 
    cout<<KMP(text, pattern);
 
    return 0;
}


// KMP to print all the indexes where substring is found
void KMP(string text, string pattern)
{
    int m = text.length();
    int n = pattern.length();
 
    if (n == 0) {
        cout << "The pattern occurs with shift 0";
        return;
    }
 
    if (m < n) {
        cout << "Pattern not found";
        return;
    }
 
    int next[n + 1];
    for (int i = 0; i < n + 1; i++) 
        next[i] = 0;
 
    for (int i = 1; i < n; i++)
    {
        int j = next[i + 1];
        while (j > 0 && pattern[j] != pattern[i]) j = next[j];
        if (j > 0 || pattern[j] == pattern[i]) next[i + 1] = j + 1;
        
    }
 
    for (int i = 0, j = 0; i < m; i++) {
        if (text[i] == pattern[j]) {
            if (++j == n) 
                cout << "The pattern occurs with shift " << i - j + 1 << endl;
        }
        else if (j > 0) {
            j = next[j];
            i--;    
        }
    }
}