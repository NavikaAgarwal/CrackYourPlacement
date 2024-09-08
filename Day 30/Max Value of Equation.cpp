class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int maxValue = INT_MIN; // Initialize maximum value to the smallest integer
        deque<pair<int, int>> window; // Deque to maintain the sliding window of valid points

        for (auto& point : points) {
            int x = point[0], y = point[1];
          
            // Remove points from the front of the deque that are out of the current x's range (distance greater than k)
            while (!window.empty() && x - window.front().first > k) {
                window.pop_front();
            }

            // If the deque is not empty, calculate the potential maximum value using the front element
            if (!window.empty()) {
                maxValue = max(maxValue, x + y + window.front().second - window.front().first);
            }

            // Maintain a monotone decrease in the value of y - x by popping from the back of the deque
            while (!window.empty() && y - x >= window.back().second - window.back().first) {
                window.pop_back();
            }

            // Add the current point to the deque
            window.emplace_back(x, y);
        }

        return maxValue; // Return the computed maximum value
    }
};
