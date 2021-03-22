#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    stack<int> stk;
    for (int i = 0; i < moves.size(); i++)
    {
        for (int j = 0; j < board[moves[i] - 1].size(); j++)
        {
            if (board[j][moves[i] - 1] != 0)
            {
                if (!stk.empty())
                {
                    if (stk.top() != board[j][moves[i] - 1])
                        stk.push(board[j][moves[i] - 1]);
                    else
                    {
                        answer += 2;
                        stk.pop();
                    }
                }
                else
                {
                    stk.push(board[j][moves[i] - 1]);
                }

                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    return answer;
}