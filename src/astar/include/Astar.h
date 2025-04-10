#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
#include <queue>
#include <vector>
#include <unordered_map>
#include <nav_msgs/OccupancyGrid.h>
#include <tf/tf.h>
using namespace std;
using namespace cv;



struct MapParamNode{
    Point StartPoint, TargetPoint;
    Mat Rotation;
    Mat Translation;
    double resolution ;
    int height;
    int width;
    int x;
    int y;

};

struct AstarNode {
    Point pos;       // 当前节点坐标
    double g;        // 从起点到当前节点的实际代价
    double h;        // 估算的启发式代价
    double f;        // 总代价 f = g + h
    AstarNode* parent; // 父节点，用于回溯路径

};
struct NodeCompare {
    bool operator()(const AstarNode* a, const AstarNode* b) const {
        return a->f > b->f;  // f 值小的优先
    }
};

inline double heuristic(Point a, Point b) {
    return sqrt(pow(static_cast<double>(a.x) - static_cast<double>(b.x), 2.0) +
                pow(static_cast<double>(a.y) - static_cast<double>(b.y), 2.0));
}

bool isNearObstacle(const Mat& map, const Point& pt, int r, int threshold = 20) {
    for (int dy = -r; dy <= r; ++dy) {
        for (int dx = -r; dx <= r; ++dx) {
            int nx = pt.x + dx, ny = pt.y + dy;
            if (nx >= 0 && nx < map.cols && ny >= 0 && ny < map.rows) {
                if (map.at<uchar>(ny, nx) < threshold)
                    return true;
            }
        }
    }
    return false;
}

vector<Point> AstarSearch(MapParamNode& MapParam, const Mat& map, Point start, Point goal) {
    // 如果地图为空则直接返回空路径
    if (map.empty())
        return {};

    priority_queue<AstarNode*, vector<AstarNode*>, NodeCompare> openList;
    unordered_map<int, AstarNode*> visited;

    // 初始化起点
    AstarNode* startNode = new AstarNode{start, 0, heuristic(start, goal), heuristic(start, goal), nullptr};
    openList.push(startNode);
    visited[start.y * MapParam.width + start.x] = startNode;

    vector<Point> directions = { {0,1}, {1,0}, {0,-1}, {-1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1} };

    while (!openList.empty()) {
        AstarNode* current = openList.top();
        openList.pop();

        if (current->pos == goal) {
            vector<Point> path;
            AstarNode* node = current;
            while (node) {
                path.push_back(node->pos);
                node = node->parent;
            }
            reverse(path.begin(), path.end());
            // 释放内存
            for (auto& pair : visited)
                delete pair.second;
            visited.clear();
            return path;
        }

        // 遍历相邻节点
        for (auto& d : directions) {
            Point newPos = current->pos + d;
            if (newPos.x < 0 || newPos.x >= MapParam.width || newPos.y < 0 || newPos.y >= MapParam.height)
                continue;
            // 如果该位置为障碍物则跳过

            if (isNearObstacle(map, newPos, 5)) 
                continue;
            // 计算新的 g, h, f 值
            // cout<<"newPos.x:"<<newPos.x<<" newPos.y:"<<newPos.y<<endl;
            // cout<<"map.at<uchar>(newPos.y, newPos.x):"<<(int)map.at<uchar>(newPos.y, newPos.x)<<endl;
            double newG = current->g + ((d.x == 0 || d.y == 0) ? 1.0 : 1.414);
            double newH = heuristic(newPos, goal);
            double newF = newG + newH;

            int key = newPos.y * MapParam.width + newPos.x;
            if (visited.find(key) == visited.end() || newF < visited[key]->f) {
                AstarNode* newNode = new AstarNode{newPos, newG, newH, newF, current};
                openList.push(newNode);
                visited[key] = newNode;
            }
        }
    }

    // 若未找到路径，释放内存
    for (auto& pair : visited)
        delete pair.second;
    visited.clear();

    return {}; // 无路径
}

#endif
