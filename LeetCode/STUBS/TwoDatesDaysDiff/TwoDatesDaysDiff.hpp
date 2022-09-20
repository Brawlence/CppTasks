// https://leetcode.com/problems/number-of-days-between-two-dates/

#include <chrono>

class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
        std::tm lhst = {0}, rhst = {0};
        std::istringstream d1(date1), d2(date2);
        
        d1 >> std::get_time(&lhst, "%Y-%m-%d");
        d2 >> std::get_time(&rhst, "%Y-%m-%d");
            
        auto lhs = std::mktime(&lhst);
        auto rhs = std::mktime(&rhst);        
        
        double seconds = std::abs(std::difftime(lhs, rhs));    
        
        return static_cast<int>(seconds / 60 / 60 / 24); 
    }
};