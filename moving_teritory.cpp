#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

vector<vector<int>> search_check;
bool pqVisit[100000];

int x[] = {-1, 0, 0, 1};
int y[] = {0, -1, 1, 0};

queue<pair<int, int>> q;

class Compare
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> land, int height)
{
    int answer = 0;
    int idx = 0;
    search_check.resize(land.size(), vector<int>(land.size(), 0));

    for (int i = 0; i < land.size(); i++)
    {
        for (int j = 0; j < land.size(); j++)
        {
            if (!search_check[i][j])
            {
                idx++;
                search_check[i][j] = idx;
                q.push(make_pair(i, j));
                while (q.size())
                {
                    pair<int, int> cur = q.front();
                    q.pop();
                    for (int i = 0; i < 4; i++)
                    {
                        if (cur.second + y[i] >= 0 && cur.first + x[i] >= 0 && cur.first + x[i] < land.size() && cur.second + y[i] < land.size() && !search_check[cur.first + x[i]][cur.second + y[i]])
                        {
                            int sub = abs(land[cur.first][cur.second] - land[cur.first + x[i]][cur.second + y[i]]);
                            if (sub <= height)
                            {
                                q.push(make_pair(cur.first + x[i], cur.second + y[i]));
                                search_check[cur.first + x[i]][cur.second + y[i]] = idx;
                            }
                        }
                    }
                }
            }
        }
    }

    // cout << "1\n";

    // for (int i = 0; i < land.size(); i++)
    // {
    //     for (int j = 0; j < land.size(); j++)
    //     {
    //         cout << search_check[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // 탐색으로 벡터 그래프를 생성
    vector<vector<pair<int, int>>> v1;
    v1.resize(idx + 3, vector<pair<int, int>>());

    for (int j = 0; j < land.size(); j++)
    {
        for (int k = 0; k < land.size(); k++)
        {
            for (int i = 0; i < 4; i++)
            {
                pair<int, int> cur = make_pair(j, k);
                if (cur.second + y[i] >= 0 && cur.first + x[i] >= 0 && cur.first + x[i] < land.size() && cur.second + y[i] < land.size())
                {
                    if (search_check[cur.first][cur.second] != search_check[cur.first + x[i]][cur.second + y[i]])
                    {
                        int sub = abs(land[cur.first][cur.second] - land[cur.first + x[i]][cur.second + y[i]]);
                        // cout << "x : " << j << ", y : " << k << " vs " << cur.first + x[i] << " " << cur.second << ", sub : " << sub << "\n";
                        v1[search_check[cur.first][cur.second]].push_back(make_pair(search_check[cur.first + x[i]][cur.second + y[i]], sub));
                    }
                }
            }
        }
    }

    // Minimum Spanning Tree 구현
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;

    pqVisit[1] = true;
    for (int i = 0; i < v1[1].size(); i++)
    {
        pq.push(pair<int, int>(v1[1][i].first, v1[1][i].second));
    }

    while (pq.size())
    {
        pair<int, int> tmp = pq.top();
        pq.pop();

        if (pqVisit[tmp.first])
            continue;

        pqVisit[tmp.first] = true;

        answer += tmp.second;

        for (int i = 0; i < v1[tmp.first].size(); i++)
        {
            pq.push(pair<int, int>(v1[tmp.first][i].first, v1[tmp.first][i].second));
        }
    }

    //cout << "3\n";

    return answer;
}

// int main()
// {
//     // int solution(vector<vector<int>> land, int height)
//     vector<vector<int>> land;
//     int height;
//     int N;
//     cout << "N, height plz : ";
//     cin >> N >> height;
//     land.resize(N, vector<int>(N, 0));
//     for (int i = 0; i < land.size(); i++)
//     {
//         for (int j = 0; j < land.size(); j++)
//         {
//             cin >> land[i][j];
//         }
//     }

//     cout << solution(land, height) << "\n";
// }