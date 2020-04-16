#include <iostream>
#include <vector>

using namespace std;

int n, board[100][100];
bool jump(int y, int x) {
    // 기저 사례 : 게임판 밖을 벗어난 경우
    if(y >= n || x >= n) return false;
    // 기저 사례 : 마지막 칸에 도착한 경우
    if(y == n - 1 && x == n - 1) return true;
    int jumpSize = board[y][x];
    return jump(y + jumpSize, x) || jump(y, x + jumpSize);
}