class Solution {
public:
    string simplifyPath(string path) {

        if (0 == path.length())
            return "/";

        std::stack<string> paths;

        std::stringstream ss(path);

        std::string token;
        while (std::getline(ss, token, '/')) {
            if (".." == token) {
                if (!paths.empty()) {
                    paths.pop();
                }
            } else if (("." != token) && ("" != token)) {
                paths.push(token);
            }
        }
                
        if (paths.empty())
            return "/";

        std::string result(paths.top());
        result.reserve(path.length());

        paths.pop();
        
        while(!paths.empty()) {
            
            result.insert(0, paths.top() + "/");
            paths.pop();
        }

        return "/" + result;
    }
};
