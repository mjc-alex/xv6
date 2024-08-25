#include <cstdio>
#include <iostream>
const int maxn = 30;
int n, V, maxValue = 0;
int w[maxn], c[maxn];

void DFS(int index, int sumW, int sumC) {
    if (index == n){
        if (sumW <= V && sumC > maxValue) {
            maxValue = sumC;
        }
        return;
    }
    DFS(index + 1, sumW, sumC);
    DFS(index + 1, sumW + w[index], sumC + c[index]);
}

int main() {
    std::cin >> n >> V;
    for (int i = 0; i < n; i++) {
        std::cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> c[i];
    }
    DFS(0, 0, 0);
    std::cout << maxValue << "\n";
    return 0;
}