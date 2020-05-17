class Solution {
public:
    bool compare(vector<int> a, vector<int> b)
    {
        for(int i=0; i<26; i++)
            if(a[i] != b[i])
                return false;
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int> freq(26, 0);
        int p_size = p.length();
        int s_size = s.length();
        cout<<p_size<<" "<<s_size;
        for(int i=0; i<p_size; i++)
            freq[p[i]-'a']++;
        
        vector<int> ans;
        if(s_size < p_size)
            return {};
        vector<int> curr_freq(26, 0);
        for(int i=0; i<p_size; i++)
        {
            curr_freq[s[i]-'a']++;
        }
        if(compare(freq, curr_freq))
            ans.push_back(0);
        for(int i=p_size; i<s_size; i++)
        {
            //remove first entry
            curr_freq[s[i-p_size]-'a']--;
            
            //add current entry
            curr_freq[s[i]-'a']++;
            if(compare(curr_freq, freq))
                ans.push_back(i-p_size+1);
        }
        return ans;
    }
};
