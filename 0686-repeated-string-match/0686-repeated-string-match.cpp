class Solution {
public:

void lpsfind(vector<int>&lps,string s) 
	{
	    // Your code goes here
	    int pre=0,suf=1;
	    
	    while(suf<s.size())
	    {
	       // match 
	       if(s[pre]==s[suf])
	       {
	           lps[suf]=pre+1;
	           suf++;
	           pre++;
	       }
	       //not matched
	       else
	       {
	           if(pre==0)
	           {
	               lps[suf]=0;
	               suf++;
	           }
	           else
	           {
	               pre=lps[pre-1];
	           }
	       }
	    }
	} 
	
    
    int KMP_MATCH(string haystack, string needle) 
    {
        
        vector<int>lps(needle.size(),0);
        lpsfind(lps,needle);
        int first=0,second=0;
        while(first<haystack.size()&&second<needle.size())
        {

        // matched
        if(haystack[first]==needle[second])
        {
            first++,second++;
        }
        // not matched
		else
        {
            if(second==0)
            
                first++;
            
            else
            second=lps[second-1];
        }
    }
		// Answer exists
        if(second==needle.size())
        return 1;
        return 0;
        
    
     }
    int repeatedStringMatch(string a, string b) {
        if (a==b)
        return 1;

        int repete=1;
        string temp=a;
        while(temp.size()<b.size())
        {
            temp+=a;
            repete++;
        }
        // KMP pattern 
        if(KMP_MATCH(temp,b)==1)
        return repete;
        // tem+a,kmp search
        if(KMP_MATCH(temp+a,b)==1)
        return repete+1;

        return -1;
    }
};