#pragma once
#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility> // for std::pair

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake {
private:
    std::vector<std::pair<int, int>> body; // 蛇身坐标
    Direction direction;                   // 当前方向

public:
    Snake(int startX, int startY);

    void move();                                   // 移动蛇
    void grow();                                   // 蛇变长
    bool checkCollision(int width, int height) const; // 检测撞墙或自撞
    const std::vector<std::pair<int, int>>& getBody() const;
    void setDirection(Direction newDirection);    // 设置方向
    Direction getDirection() const;               // 获取方向
};

#endif
