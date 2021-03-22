#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";
    unordered_map<string, int> um;
    for (int i = 0; i < participant.size(); i++)
    {
        if (um.find(participant[i]) == um.end())
            um.insert(pair<string, int>(participant[i], 1));
        else
            um[participant[i]] += 1;
    }
    for (auto &tmp : completion)
    {
        if (um.find(tmp) != um.end())
        {
            um[tmp] -= 1;
            if (um[tmp] == 0)
                um.erase(tmp);
        }
    }

    for (auto &tmp : um)
        answer = tmp.first;
    return answer;
}