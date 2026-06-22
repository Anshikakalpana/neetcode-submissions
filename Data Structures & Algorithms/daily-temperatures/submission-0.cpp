class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> a(temperatures.size(), 0);
        stack<pair<int, int>> s;
        int j = 1;
        s.push({temperatures[0], 0});

        while(j < temperatures.size()) {
            if(!s.empty() && s.top().first < temperatures[j]) {
                while(!s.empty() && s.top().first < temperatures[j]) {
                    a[s.top().second] = j - s.top().second;
                    s.pop();
                }
            }
            s.push({temperatures[j], j});
            j++;
        }

        return a;
    }
};
