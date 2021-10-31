class Solution {
public:
    bool compare(vector<int> x, vector<int> y)
    {
        for(int i=0; i<26; i++)
            if(x[i] != y[i])
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);
        vector<int> curr_freq(26, 0);
        int n1 = (int)s1.size();
        int n2 = (int)s2.size();
        
        if(n1 > n2)
            return false;
        for(int i=0; i<n1; i++)
            freq[s1[i]-'a']++;
        
        for(int i=0; i<n1; i++)
            curr_freq[s2[i]-'a']++;
        
        #compares two vectors and returns true if they are same false otherwise
        if(compare(freq, curr_freq))
            return true;
        
        for(int i=n1; i<n2; i++)
        {
            // remove first char freq
            curr_freq[s2[i-n1]-'a']--;
            
            // add current char freq
            curr_freq[s2[i]-'a']++;
            if(compare(freq, curr_freq))
                return true;
        }
        
        return false;
    }
};

int main()
{
    Solution obj1 = Solution.new();
    string a = 'dummystring';
    string b = 'dumb';
    bool t = obj1.checkInclusion(a,b);
    cout<<"returned value "<<t;
    
    
    return 0;
}
