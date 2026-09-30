class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        /*
        Intuition:
s1 ka permutation check karne ke liye s2 mein size n ki ek substring chahiye jisme exact same character frequency ho. Order matter nahi karta, sirf frequency match honi chahiye. Iske liye hum fixed-size sliding window (n length ki) use karke characters ka count track karte hain, jisse baar-baar poori string traverse na karni pade.

Algorithm:

1. Base Check: Agar s1.size() > s2.size(), return false.
2. Frequency Map: Size 26 ke do arrays (maps1, maps2) banao. s1 ke saare aur s2 ke pehle n characters ka frequency count fill karo.
3. First Check: Agar maps1 == maps2, return true.
4. Slide Window: i = n se end tak traversal karo:

* Add: Naye character ko count karo (maps2[s2[i]]++).
* Remove: Purane left character ko hatao (maps2[s2[i-n]]--).
* Match: Agar maps1 == maps2, return true.

5. End: Kuch match nahi hua toh return false.

Complexity: Time O(m) | Space O(1) (jahan m = s2.size())
        */

        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        vector<int>maps1(26,0);
        vector<int>maps2(26,0);

        for(int i = 0; i<n; i++){
            maps1[s1[i]-'a']++;
        }

        for(int i = 0; i<n; i++){
            maps2[s2[i]-'a']++;
        }

        if(maps1 == maps2) return true;

        for(int i = n; i<m; i++){
            maps2[s2[i]-'a']++;
            maps2[s2[i-n]-'a']--;
            if(maps1 == maps2) return true;
        }
        return false;
    }
};
