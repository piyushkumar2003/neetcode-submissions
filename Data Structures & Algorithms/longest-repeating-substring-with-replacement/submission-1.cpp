class Solution {
public:
    int characterReplacement(string s, int k) {
        
        /*

Intuition:
Goal: Har unique character c ko baari-baari target banao aur uski sabse lambi continuous substring dhundho.

Logic: Window size (r - l + 1) mein se agar non-target characters ((r - l + 1) - count) ki quantity k se badi ho jaye, toh window invalid ho jati hai. Tab left pointer l ko aage badha kar window shrink kar do.

Algorithm:

1. String ke sare unique characters nikaal kar unpar loop chalao.
2. Har character c ke liye:

* Expand Window: Right pointer r ko aage badhao, agar s[r] == c toh count++ karo.
* Shrink Window: Jab tak replacements k se zyada ho ((r - l + 1) - count > k):
* Agar s[l] == c toh count-- karo.
* l++ karke window chhota karo.


* Update Result: Maximum length update karo: res = max(res, r - l + 1).

3. Sare characters check hone ke baad res return kar do.

        */

        unordered_set<char> charSet(s.begin(),s.end());
        int res = 0;
        for(char c:charSet){
            int count = 0;
            int l = 0;
            for(int r = 0; r<s.size();r++){
                if(s[r] == c){
                    count++;
                }

                while((r-l+1)-count > k){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                res = max(res, r-l+1);
            }
        }
        return res;


        
    }
};
