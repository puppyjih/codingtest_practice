#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(string new_id)
{
    string answer = "";

    // step 1
    transform(new_id.begin(), new_id.end(), new_id.begin(), ::tolower);

    cout << "st1 : " << new_id << "\n";

    // step 2
    int i = 0;
    while (new_id[i] != '\0')
    {
        char cmp = new_id[i];
        if (!((cmp >= '0' && cmp <= '9') || (cmp >= 'a' && cmp <= 'z') || cmp == '-' || cmp == '_' || cmp == '.'))
            new_id.erase(new_id.begin() + i);
        else
            i++;
    }

    cout << "st2 : " << new_id << "\n";
    // step 3
    i = 0;
    while (i < new_id.size() - 1 && new_id[i] != '\0')
    {
        if (new_id[i] == '.' && new_id[i + 1] == '.')
            new_id.erase(new_id.begin() + i);
        else
            i++;
    }

    cout << "st3 : " << new_id << "\n";

    // step 4
    if (new_id.size() > 0 && new_id[0] == '.')
        new_id.erase(new_id.begin());

    if (new_id.size() > 0 && new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.end() - 1);

    // step 5
    if (new_id.size() == 0)
        new_id.append("a");

    // step 6
    if (new_id.size() >= 16)
    {
        new_id.erase(15);
        if (new_id.size() > 0 && new_id[new_id.size() - 1] == '.')
            new_id.erase(new_id.end() - 1);
    }

    cout << "st 6: " << new_id << "\n";
    //step 7
    while (new_id.size() <= 2)
    {
        new_id.push_back(new_id[new_id.size() - 1]);
    }

    answer = new_id;
    return answer;
}

int main()
{
    string s;
    cin >> s;
    cout << solution(s) << "\n";
}