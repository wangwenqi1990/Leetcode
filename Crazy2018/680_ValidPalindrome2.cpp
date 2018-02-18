class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left]==s[right]){
                left++; right--;
            }
            else{
                return validPalindrome0(s.substr(left+1, right-left)) || validPalindrome0(s.substr(left, right-left));
            }
        }
        return true;
    }
    
    bool validPalindrome0(string s){
        int left = 0, right = s.size()-1;
        while(left < right){
            if(s[left]==s[right]){
                left++; right--;
            }
            else
                return false;
        }
        return true;
    }
};