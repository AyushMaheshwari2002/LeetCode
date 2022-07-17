/* Given a string path, which is an absolute path (starting with a slash '/') to a file or directory in a Unix-style file system, convert it to the simplified 
   canonical path.
   In a Unix-style file system, a period '.' refers to the current directory, a double period '..' refers to the directory up a level, and any multiple consecutive
   slashes (i.e. '//') are treated as a single slash '/'. For this problem, any other format of periods such as '...' are treated as file/directory names.

   The canonical path should have the following format:
       * The path starts with a single slash '/'.
       * Any two directories are separated by a single slash '/'.
       * The path does not end with a trailing '/'.
       * The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')
       * Return the simplified canonical path.

              Example 1:
                    Input: path = "/home/"
                    Output: "/home"
                    Explanation: Note that there is no trailing slash after the last directory name.

              Example 2:
                    Input: path = "/../"
                    Output: "/"
                    Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

              Example 3:
                    Input: path = "/home//foo/"
                    Output: "/home/foo"
                    Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
*/




class Solution {
public:
    string simplifyPath(string path) 
    {
        vector<string> v;
        string ans = "";
        
        for(int i = 0; i < path.size(); i++)
        {
            string str = "";
            
            while(i < path.size() && path[i] != '/') 
                str += path[i++];              //get the string till i hits '/'
            
            if(str == "" || str == ".") 
                continue;                     //If the string we get is "." or "" we skip the pushing part
            
            else if(str == "..")
            {                                  
                if(v.size() > 0) 
                    v.pop_back();             //If "..", we pop back so as to go to parent directory
            }
            
            else 
                v.push_back(str);             //To push the string we obtained till '/'     
        }
        
        if(v.size() == 0) 
            return "/";
        
        for(int i = 0; i < v.size(); i++)
            ans += "/" + v[i];
        
        return ans;
    }
};




