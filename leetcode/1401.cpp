class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y2 + radius) return true;
        if (x1 - radius <= xCenter && xCenter <= x2 + radius && y1 <= yCenter && yCenter <= y2) return true;
        for (int x: {x1, x2}) {
            for (int y: {y1, y2}) {
                if ((x - xCenter) * (x - xCenter) + (y - yCenter) * (y - yCenter) < radius * radius) return true;
            }
        }
        return false;
    }
};