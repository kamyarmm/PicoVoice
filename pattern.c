// [Python, C] Given an input string and a pattern, implement regular expression
// matching with support for ‘.’ and ‘*’.
// - '.' Matches any single character
// - '*' Matches zero or more of the preceding element


//There are two method for implementation : 1- dynamic 2-recursive
// For the C implementation it applied the dynamic method and for the recursive used the Python

// C
bool str_match (const char *msg, const char *pat)
{
	int msg_len = strlen(msg);
	int pat_len = strlen(pat);
	
	bool tt[msg_len+1][pat_len+1];
	memset(tt,0,msg_len + pat_len);
	
	tt[0][0]= true;
	for(int i =0; i<=msg_len; i++)
	{
		for(int j=0; j<= pat_len; j++)
		{
			if(pat[j-1]!= '.' && pat[j-1]!= "*")
			{
				if(i>0 && msg[j-1]==pat[j-1] && tt[i-1][j-1])
				{
					tt[i][j]= true;
				}
				else if (pat[j-1]=='.')
				{
					if(i>0 && tt[i-1][j-1])
					{
						tt[i][j]= true;
					}
				}
				else if(j>1)
				{
					if(tt[i][j-1] || tt[i][j-2])
					{
						tt[i][j]= true;
					}
					else if(i>0 && (pat[j-2]==msg[i-1] || p[j-2]=='.') &&tt[i-1][j])
					{
						tt[i][j]= true;
					}
				}
			}
		}
	}
	
	return tt[msg_len][pat_len];
}

# Python (recursive)

def str_match(msg , pat)
    if not pat:
	   return not text
    
	mp= bool(text) and pat[0] in {msg[0], '.'}  #check the first match 
	
	if len(pat) >=2 and pat[1:]== '*':
	   return (str_match(msg[1:],pat[1:]) or mp and str_match(msg[1:],pat))
	else:
	   return mp and str_match(msg[1:], pat[1:])
	   
	   
