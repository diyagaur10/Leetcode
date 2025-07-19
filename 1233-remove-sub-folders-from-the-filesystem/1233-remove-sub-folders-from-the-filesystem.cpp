class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> result;
        string prev = "";

        for (const string& f : folder) {
            // if current folder is not a sub-folder of the last added one
            if (prev.empty() || f.find(prev + "/") != 0) {
                result.push_back(f);
                prev = f;
            }
        }

        return result;
    }
};
