#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int answer = 0;
    for (string s : skill_trees)
    {
        cout << "s : " << s << "\n";

        int seq = s.find(skill[0]);
        for (int j = 1; j < skill.size(); j++)
        {
            int compare = s.find(skill[j]);
            cout << compare << " ";
            if ((seq == -1 && compare != -1) || (compare < seq && compare != -1))
            {
                answer -= 1;
                cout << "baam";
                break;
            }
            seq = compare;
        }
        answer += 1;
        cout << "\n";
    }
    return answer;
}