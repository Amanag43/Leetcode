class Solution {
public:
    string removeDigit(string number, char digit) {
        for(int i =0; i<number.length()-1; i++)
        {
            if(number[i]==digit && number[i+1]>digit){
                return number.substr(0, i) + number.substr(i + 1);
            }
        }
        int last_index = number.rfind(digit);
        return number.substr(0, last_index) + number.substr(last_index + 1);
    
    }
};