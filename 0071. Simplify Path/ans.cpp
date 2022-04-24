#include <string>
#include <vector>

class Solution
{
public:
    std::string simplifyPath(std::string path)
    {
        std::vector<std::string> folders;
        int idx = 0;
        while (idx < path.length())
        {
            while (idx < path.length() && path[idx] == '/')
                idx++;
            std::string f = "";
            while (idx < path.length() && path[idx] != '/')
            {
                f += path[idx];
                idx++;
            }
            if (f == ".")
            {
                continue;
            }
            else if (f == "..")
            {
                if (!folders.empty())
                {
                    folders.pop_back();
                }
            }
            else if (f.length())
            {
                folders.push_back(f);
            }
        }

        std::string result = "";
        for (auto fo : folders)
        {
            result += "/";
            result += fo;
        }
        if (result.empty())
        {
            result = "/";
        }
        return result;
    }
};