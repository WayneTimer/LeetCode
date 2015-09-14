/*
Time: O(n)
Space: O(n)
Runtime: 8ms

by Timer [linyicx@126.com]
2015.09.14
*/
char* convert(char* s, int numRows)
{
    char* a;
    int l,x,k;
    l = strlen(s);
    a = (char*)malloc(l+1);
    if (numRows == 1)
        x = 1;
    else
        x = (numRows<<1) - 2;
    k = 0;
    for (int i=0;i<numRows;i++)
    {
        if (i==0 || i==numRows-1)
        {
            for (int j=i;j<l;j+=x) a[k++] = s[j];
        }
        else
        {
            for (int j1=i,j2=x-i;j1<l || j2<l;j1+=x,j2+=x)
            {
                a[k++] = s[j1];
                if (j2<l) a[k++] = s[j2];
            }
        }
    }
    a[k] = '\0';
    return a;
}
