#include<iostream>
#include<functional>
std::vector<bool> row,col,dg,udg;
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<char>> g(n, std::vector<char>(n, '.'));
    std::vector<bool> row(n, false), col(n, false), dg(2 * n - 1, false), udg(2 * n - 1, false);
    std::function<void(int,int)> dfs = [&] (int x,int s) {
        if(x == n) {
            if(s == n) {
                for(const auto& r : g) {
                    for(const auto& ch : r) {
                        std::cout << ch;
                    }
                    std::cout <<'\n';
                }
                std::cout << '\n';
            }
            return ;
        }
        
        for(int y = 0; y < n; y++) {
            if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[n+y-x]) {
            row[x] = col[y] = dg[x+y] = udg[n+y-x] = true;
            g[x][y] = 'Q';
            dfs(x + 1,s + 1);
            row[x] = col[y] = dg[x+y] = udg[n+y-x] = false;
            g[x][y] = '.';
            }
        }
    };
    dfs(0,0);
    return 0;
}