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

bool isNearObstacle(const Mat& map, const Point& pt, int r, int threshold = 50) {
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
    if (map.empty())
        return {};

    static Point lastStart(-1, -1);
    static Point lastGoal(-1, -1);
    static bool firstRun = true;

    priority_queue<AstarNode*, vector<AstarNode*>, NodeCompare> openList;
    unordered_map<int, AstarNode*> visited;

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


            if (firstRun || start != lastStart || goal != lastGoal) {
                firstRun = false;
                lastStart = start;
                lastGoal = goal;

                int steps = static_cast<int>(path.size()) - 1;
                cout << "A-star Completed! 🌟 Total steps: " << steps << endl;

                double totalDistance = 0.0;
                for (size_t i = 1; i < path.size(); ++i) {
                    Point p1 = path[i - 1], p2 = path[i];
                    totalDistance += (p1.x != p2.x && p1.y != p2.y) ? 1.414 : 1.0;
                }
                cout << "Total distance: " << totalDistance << " Pixels " << endl;
            }

            for (auto& pair : visited)
                delete pair.second;
            visited.clear();

            return path;
        }

        for (auto& d : directions) {
            Point newPos = current->pos + d;
            if (newPos.x < 0 || newPos.x >= MapParam.width || newPos.y < 0 || newPos.y >= MapParam.height)
                continue;
            if (isNearObstacle(map, newPos, 2)) 
                continue;

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

    for (auto& pair : visited)
        delete pair.second;
    visited.clear();

    return {};
}

#endif
