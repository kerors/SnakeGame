#include "Snake.h"

Snake::Snake(int startX, int startY) : direction(RIGHT) {
    body.push_back({ startX, startY }); // 蛇头初始位置
}

void Snake::move() {
    auto head = body.front(); // 当前头部位置
    switch (direction) {
    case UP:    head.second--; break;
    case DOWN:  head.second++; break;
    case LEFT:  head.first--; break;
    case RIGHT: head.first++; break;
    }
    body.insert(body.begin(), head); // 添加新头部
    body.pop_back();                 // 移除尾部
}

void Snake::grow() {
    body.push_back(body.back()); // 尾部增加一节

}

bool Snake::checkCollision(int width, int height) const {
    auto head = body.front();

    // 撞墙检测
    if (head.first < 1 || head.first >= width - 1 || head.second < 1 || head.second >= height - 1)
        return true;

    // 自撞检测（检查蛇头是否与蛇身的其他部分重叠）
    for (size_t i = 1; i < body.size() - 1; ++i) {
        if (body[i] == head) return true;
    }

    return false;
}


const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

void Snake::setDirection(Direction newDirection) {
    // 防止蛇反向移动
    if ((direction == UP && newDirection != DOWN) ||
        (direction == DOWN && newDirection != UP) ||
        (direction == LEFT && newDirection != RIGHT) ||
        (direction == RIGHT && newDirection != LEFT)) {
        direction = newDirection;
    }
}

Direction Snake::getDirection() const {
    return direction;
}
