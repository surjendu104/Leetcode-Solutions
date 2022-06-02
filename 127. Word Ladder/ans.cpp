class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> s1;
        unordered_set<string> s2;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;
        s1.insert(beginWord);
        s2.insert(endWord);
        int ans = 0;
        int len = beginWord.size();

        while (!s1.empty() && !s2.empty())
        {
            ans++;
            if (s1.size() > s2.size())
            {
                swap(s1, s2);
            }
            unordered_set<string> cur;
            for (auto w : s1)
            {
                for (int i = 0; i < len; i++)
                {
                    char c = w[i];
                    for (int j = 0; j < 26; j++)
                    {
                        w[i] = j + 'a';
                        if (s2.count(w))
                        {
                            return ans + 1;
                        }
                        if (dict.count(w))
                        {
                            dict.erase(w);
                            cur.insert(w);
                        }
                    }
                    w[i] = c;
                }
            }
            s1 = cur;
        }
        return 0;
    }
};

// another approach

class Solution
{
public:
    bool connected(string &s1, string &s2)
    {
        int m = s1.size();
        int n = s2.size();
        if (m != n)
            return -1;

        int count = 0;
        for (int i = 0; i < m; ++i)
        {
            if (s1[i] != s2[i])
            {
                ++count;
                if (count > 1)
                    return false;
            }
        }
        return count == 1;
    };

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        auto it = find(wordList.begin(), wordList.end(), beginWord);
        int start;
        if (it == wordList.end())
        {
            wordList.push_back(beginWord);
            start = wordList.size() - 1;
        }
        else
        {
            start = it - wordList.begin();
        }

        it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end())
            return 0;
        int end = it - wordList.begin();

        // cout << "start: " << start << ", end: " << end << endl;

        int n = wordList.size();

        vector<vector<int>> adjList(n);

        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (connected(wordList[i], wordList[j]))
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                    // cout << wordList[i] << " <-> " << wordList[j] << endl;
                }
            }
        }

        // BFS
        queue<int> q;
        int cur;
        int level = 1; // the length of the path containing only start
        vector<bool> visited(n, false);
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int levelSize = q.size();
            // cout << "level: " << level << ", levelSize: " << levelSize << endl;

            while (levelSize-- > 0)
            {
                cur = q.front();
                q.pop();
                // cout << wordList[cur] << endl;

                if (cur == end)
                {
                    return level;
                }

                for (int nei : adjList[cur])
                {
                    if (!visited[nei])
                    {
                        visited[nei] = true;
                        q.push(nei);
                    }
                }
            }

            ++level;
        }

        // cannot find a path
        return 0;
    }
};