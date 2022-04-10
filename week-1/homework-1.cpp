class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> tmp_vec;
        int carry = 0;

        for(int i = digits.size() -1; i >= 0; i--){
            int tmp = digits[i] + carry;
            if(i == digits.size() -1)
                tmp += 1;
            carry = tmp /10;
            tmp_vec.push_back(tmp % 10);
        }
        if(carry != 0){
            tmp_vec.push_back(carry);
        }
        reverse(tmp_vec.begin(), tmp_vec.end());
        return tmp_vec;
    }
};
