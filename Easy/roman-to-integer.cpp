// Given a roman numeral, convert it to an integer. 
// Input is guaranteed to be within the range from 1 to 3999.

// Hardcoding each value
// Time Complexity O(N) - Linaer
// Runtime: 12 ms
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for(int i = 0 ; i < s.length(); i ++){
            if(s [i] == 'I' && s [i + 1] == 'V'){
                result+= 4;
                i++;
            }
            else if(s [i] == 'I' && s [i + 1] == 'X'){
                result+= 9;
                i++;
            }
            else if(s [i] == 'X' && s [i + 1] == 'L'){
                result+= 40;
                i++;
            }
            else if(s [i] == 'X' && s [i + 1] == 'C'){
                result+= 90;
                i++;
            }
            else if(s [i] == 'C' && s [i + 1] == 'D'){
                result+= 400;
                i++;
            }
            else if(s [i] == 'C' && s [i + 1] == 'M'){
                result+= 900;
                i++;
            }
            else {
                if(s[i] == 'I')
                    result+= 1;
                else if(s[i] == 'V')
                    result+= 5;
                else if(s[i] == 'X')
                    result+= 10;
                else if(s[i] == 'L')
                    result+= 50;
                else if(s[i] == 'C')
                    result+= 100;
                else if(s[i] == 'D')
                    result+= 500;
                else if(s[i] == 'M')
                    result+= 1000;
                
            }
        }
       return result; 
    }
};


// HashMap Approach
// Runtime: 24 ms
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        unordered_map <char, int> HashMap = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        for (int i = 0; i < s.length(); i++){
            auto it = HashMap.find(s[i]);
            if(i+1 < s.length()){
                auto it1 = HashMap.find(s[i+1]);
                if( it1->second > it->second && it1->second != it->second){
                    result = result + (it1->second - it->second);
                    i++;
                }
                else
                    result+= it->second;
            }
            else
                result+= it->second;
        }
        return result;
    }
};

// HashMap Optimized
// Runtime: 20 ms
class Solution {
public:
    int romanToInt(string s) {
        unordered_map <char, int> HashMap = {
            {'I' , 1},
            {'V' , 5},
            {'X' , 10},
            {'L' , 50},
            {'C' , 100},
            {'D' , 500},
            {'M' , 1000}
        };
        int result = HashMap[s.back()];
        for (int i = s.length() - 2; i >= 0; i--){
            if (HashMap[s[i]] < HashMap[s[i + 1]] )
                result-= HashMap[s[i]];
            else
                result+= HashMap[s[i]];
        }
        return result;
    }
};