class Solution {
private:
    // This function checks if the rest of the string after 'e' is a valid integer
    bool restValidNumCheck(string &s, int ind) {
        // Skip sign if present
        if (ind < s.length()) {
            if (s[ind] == '-' || s[ind] == '+') ind++;
        }

        bool hasDigit = false;
        
        // Check remaining characters after 'e' or 'E'
        while (ind < s.length()) {
            char ch = s[ind];
            // If it's not a digit, it's invalid
            if (!isdigit(ch)) {
                return false;
            }
            hasDigit = true;  // Mark that a digit has been encountered
            ind++;
        }
        
        return hasDigit;  // Valid if there was at least one digit
    }
    
public:
    bool isNumber(string s) {
        bool decimal_used = false;  // Track if a decimal point has been used
        bool isPrvNum = false;  // Track if there is a valid number before 'e'
        int i = 0;

        // Skip initial sign if present
        if (s[i] == '-' || s[i] == '+') i++;
        
        while (i < s.length()) {
            char ch = s[i];
            
            // No signs allowed in the middle of the number
            if (ch == '-' || ch == '+') return false;
            
            // Handle alphabetic characters
            else if (isalpha(ch)) {
                if (ch == 'e' || ch == 'E') {
                    // If 'e' is found, check the rest of the string for a valid integer
                    if (isPrvNum && restValidNumCheck(s, i + 1)) return true;
                    else return false;
                } else return false;  // Any other alphabetic character is invalid
            }
            
            // Handle decimal point
            else if (ch == '.') {
                if (decimal_used) return false;  // No multiple decimal points allowed
                else decimal_used = true;  // Mark that a decimal point has been used
            }
            
            // Handle digits
            else isPrvNum = true;  // Mark that we've encountered a digit
            
            i++;
        }
        
        // The string is valid only if there was at least one digit
        return isPrvNum;
    }
};