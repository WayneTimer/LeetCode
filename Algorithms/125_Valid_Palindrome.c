/*
Time: O(n)
Space: O(1)
Runtime: 4ms

by Timer [linyicx@126.com]
2015.09.17
*/
bool isAlphanumeric(char c)
{
    if (c>='a' && c<='z') return true;
    if (c>='A' && c<='Z') return true;
    if (c>='0' && c<='9') return true;
    return false;
}

bool isPalindrome(char* s)
{
    int i,j;
    i = 0;
    j = strlen(s)-1;
    while (i<j)
    {
        while (i<j && !isAlphanumeric(s[i])) i++;
        while (i<j && !isAlphanumeric(s[j])) j--;
        if (i>=j) break;
        if (s[i]>='0' && s[i]<='9')
            if (s[i] != s[j])
                return false;
        char x,y;
        if (s[i]>='a' && s[i]<='z') x = s[i]-'a';
        if (s[i]>='A' && s[i]<='Z') x = s[i]-'A';
        if (s[j]>='a' && s[j]<='z') y = s[j]-'a';
        if (s[j]>='A' && s[j]<='Z') y = s[j]-'A';
        if (x!=y) return false;
        i++;
        j--;
    }
    return true;
}
