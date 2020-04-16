#include <iostream>
#include <vector>

using namespace std;

int board[100][100];
bool inRange(int y, int x) {

}

// const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
// const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};
// // 5x5의 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환
// bool hasWord(int y, int x, const string& word) {
//     // 기저 사례 1 : 시작 위치가 범위 밖이면 무조건 실패
//     if(!inRange(y, x)) return false;
//     // 기저 사례 2 : 첫 글자가 일치하지 않으면 실패
//     if(board[y][x] != word[0]) return false;
//     // 기저 사례 3 : 단어 길이가 1이면 성공
//     if(word.size() == 1) return true;
//     // 인접한 여덟 칸을 검사한다.
//     for(int direction = 0; direction < 8; direction++) {
//         int nextY = y + dy[direction], nextX = x + dx[direction];
//         // 다음 칸이 범위 안에 있는지, 첫 글자는 일치하는지 확인할 필요가 없다.
//         if(hasWord(nextY, nextX, word.substr(1))) { return true; }
//     }
//     return false;
// }

const int dx[8] = {-1, -1, -1, 1, 1, 1, 0, 0};
const int dy[8] = {-1, 0, 1, -1, 0, 1, -1, 1};

bool hasWord(int y, int x, const string& word) {
    if(!inRange(y, x)) return false;
    if(board[y][x] != word[0]) return false;
    if(word.size() == 1) return true;
    for(int direction = 0; direction < 8; direction++) {
        if(hasWord(y, x, word.substr(1))) {
            return true;
        }
    }
    return false;
}





int main() {
    return 0;
}