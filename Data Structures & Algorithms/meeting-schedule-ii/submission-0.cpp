/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.size() == 0) return 0;
        if (intervals.size() == 1) return 1;

        
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval &b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> p;
        p.push(intervals[0].end);
        int j = 1;
        int rooms = 1;

        while (j < intervals.size()) {
          
            if (intervals[j].start >= p.top()) {
                p.pop();
            } else {
                rooms++; 
            }
            p.push(intervals[j].end);
            j++;
        }

        return rooms;
    }
};

