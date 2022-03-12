#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

string str_swap(string state, int old_loc, int new_loc) {
    swap(state[old_loc], state[new_loc]);
    return state;
}

int dr[] = {0, -1, 0, 1};
int dc[] = {-1, 0, 1, 0};

int next_loc(int old, int idx) {
    int r = old / 3, c = old % 3;
    int nr = r + dr[idx], nc = c + dc[idx];
    if (nr < 0 || nr >= 3) return -1;
    if (nc < 0 || nc >= 3) return -1;
    return nr * 3 + nc;
}

int main() {
    string state;
    for (int i = 0; i < 9; i++) {
        char c; cin >> c;
        state += c;
    }
    queue<string> q; q.push(state);
    unordered_map<string, int> dist; dist[state] = 0;
    bool flag = true;
    while (!q.empty()) {
        state = q.front(); q.pop();
        if (state == "12345678x") {
            printf("%d\n", dist[state]);
            flag = false;
            break;
        }
        int loc = state.find('x');
        for (int i = 0; i < 4; i++) {
            int nloc = next_loc(loc, i);
            if (nloc == -1) continue;
            string nstate = str_swap(state, loc, nloc);
            if (dist.find(nstate) == dist.end()) {
                q.push(nstate);
                dist[nstate] = dist[state] + 1;
            }
        }
    }
    if (flag) printf("-1\n");
    return 0;
}
