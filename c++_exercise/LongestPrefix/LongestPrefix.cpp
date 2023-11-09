/**
* Longest Common Prefix
* Write a function to find the longest common prefix string amongst an array of strings.
* If there is no common prefix, return an empty string "".
* 
* Carson Gedeus, 11/8/2023
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class LongestPrefix {
    public:
        string longestCommonPrefix(vector<string>& strs) {

            string first = "";
            string second = "";
            char prefix[128] = {'\0'};

            for (int i = 0; i < strs.size(); i++)
            {
                first = strs[i];
                for (int j = (i + 1); j < strs.size(); j++)
                {
                    second = strs[j];
                    for (int k = 0; (k < first.size() && k < second.size()); k++)
                    {
                        if (first[k] == second[k])
                        {
                            prefix[k] = first[k];
                        }
                        else if (first[k] != second[k])
                        {
                            if (k == 0)
                            {
                                return "";
                            }
                            prefix[k] = '\0';
                            break;
                        }
                        else
                        {
                            // Nothing
                        }
                    }
                }
            }

            first = "";
            second = "";

            return prefix;
        }
};

int main(void)
{
    LongestPrefix longestPrefix;
    vector<string> prefixA = { "flower", "flow", "flight" };
    vector<string> prefixB = { "dog", "racecar", "car" };
    vector<string> prefixC = {"reflower", "flow", "flight"};
    vector<string> prefixD = { "napkin", "nap", "naptime" };

    cout << longestPrefix.longestCommonPrefix(prefixA) << endl;
    cout << longestPrefix.longestCommonPrefix(prefixB) << endl;
    cout << longestPrefix.longestCommonPrefix(prefixC) << endl;
    cout << longestPrefix.longestCommonPrefix(prefixD) << endl;

    return 0;
}