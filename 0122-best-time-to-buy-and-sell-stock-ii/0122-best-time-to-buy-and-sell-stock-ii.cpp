class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mp = 0;
        int res=0;
        int min = 0, max = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[min] > prices[i]) {

                min = i;
            } else {
                int x = (prices[i] - prices[min]);
                res+=x;
                min=i;
            }
        }
        return res; 
    }
};