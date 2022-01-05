class Solution {
public:
    
    int palindrome(int ind1, int ind2, string str)
    {
        
        while(ind1<=ind2)
        {
            if(str[ind1++]!=str[ind2--])
            {
                return 0;
            }
        }
        
        return 1;
    }
    
    void func(string str, int index, vector<vector<string>>&ans, vector<string>&ds)
    {
        
        if(index==str.length())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=index; i<str.length(); i++)
        {
            if(palindrome(index, i, str))
            {
                ds.push_back(str.substr(index, i-index+1));
                func(str, i+1, ans, ds);
                ds.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>ds;
        
        func(s, 0, ans, ds);
        
        return ans;
    }
};