#include<iostream>
#include<vector>
#include<functional>
std::vector<std::vector<char> > g;

std::vector<bool> col, dg, udg;

int n;
int main() {
    std::cin >> n;
    g = std::vector<std::vector<char>>(n, std::vector<char>(n, '.'));
    col = std::vector<bool>(n, false);
    dg = std::vector<bool>(2 * n - 1, false); // 正对角线
    udg = std::vector<bool>(2 * n - 1, false); // 反对角线
    std::function<void(int)> dfs = [&] (int x)  {
        if(x == n) {
            for (const auto& row : g) {
                for (const auto& ch : row) {
                    std::cout << ch;
                }
                std::cout << '\n';
            }
            std::cout << '\n';
            return ; 
        }
        for(int i = 0;i < n ; i ++) {
            if(!col[i] && !dg[x + i] &&!udg[n + x - i]) {
                g[x][i] = 'Q';
                col[i] = dg[x + i] = udg[n + x - i] = true;
                dfs(x + 1);
                g[x][i] = '.';
                col[i] = dg[x + i] = udg[n + x - i] = false;
            }
        }

    };
    dfs(0);
    return 0;
}