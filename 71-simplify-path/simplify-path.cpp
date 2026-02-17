class Solution {
public:
    string simplifyPath(string path) {
        
        vector<string> stack;
        string current = "";
        
        for(int i = 0; i <= path.size(); i++) {
            
            // If slash OR end of string → process collected directory
            if(i == path.size() || path[i] == '/') {
                
                if(current == "" || current == ".") {
                    // do nothing
                }
                else if(current == "..") {
                    if(!stack.empty())
                        stack.pop_back();
                }
                else {
                    stack.push_back(current);
                }
                
                current = "";
            }
            else {
                current += path[i];
            }
        }
        
        // Build final path
        if(stack.empty()) return "/";
        
        string result = "";
        for(string &dir : stack) {
            result += "/" + dir;
        }
        
        return result;
    }
};
