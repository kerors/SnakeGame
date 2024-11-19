#pragma once
#ifndef GAME_H
#define GAME_H

#include "Snake.h"

class Game {
private:
    Snake snake;
    std::pair<int, int> food;  // 食物位置
    int width, height;         // 游戏区域大小
    bool isRunning;            // 游戏状态

    void generateFood();       // 随机生成食物
    void render();             // 渲染游戏画面
    void handleInput();        // 处理用户输入

public:
    Game();
    void start();              // 启动游戏
};

#endif
