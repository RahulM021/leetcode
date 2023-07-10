class Solution {
public:
    string simplifyPath(string path) {  
        stack<string> s;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/')
            continue;
            string temp;
            while(i<path.size() && path[i]!='/'){
            temp=temp+path[i];
            i++;
            }
            if(temp=="..")
            {
                if(!s.empty()) s.pop();
            }
            else if(temp==".")
            continue;
            else
            s.push(temp);
        }
        string ans;
        while(!s.empty()){
            ans="/"+s.top()+ans;
            s.pop();
        }
        if(ans.size()==0)
        return "/";
        return ans;
    }
};