class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hourSpeed = 360.0 / (12.0 * 60.0), hourAngle = hourSpeed * (float) (hour * 60 + minutes);
        
        float minuteSpeed = 360.0 / 60.0, minuteAngle = minuteSpeed * (float) minutes;
        float diff = abs(minuteAngle - hourAngle);
        return diff > 180.0 ? 360.0 - diff : diff;
    }
};