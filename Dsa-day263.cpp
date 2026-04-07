class Robot {
private:
    int width, height;
    int x, y;
    int dir; 
    vector<string> dirs = {"East", "North", "West", "South"};
    bool moved;

public:
    Robot(int width, int height) {
        this->width = width;
        this->height = height;
        x = 0;
        y = 0;
        dir = 0; 
        moved = false;
    }
    
    void step(int num) {
        int cycle = 2 * (width + height) - 4;
        num %= cycle;

        if (num == 0) num = cycle;

        moved = true;

        while (num > 0) {
            if (dir == 0) { 
                int steps = min(num, width - 1 - x);
                x += steps;
                num -= steps;
                if (num > 0) dir = 1;
            }
            else if (dir == 1) { 
                int steps = min(num, height - 1 - y);
                y += steps;
                num -= steps;
                if (num > 0) dir = 2;
            }
            else if (dir == 2) {
                int steps = min(num, x);
                x -= steps;
                num -= steps;
                if (num > 0) dir = 3;
            }
            else { 
                int steps = min(num, y);
                y -= steps;
                num -= steps;
                if (num > 0) dir = 0;
            }
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        if (!moved) return "East";
        return dirs[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */