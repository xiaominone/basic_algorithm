/*
两个序列X和Y的公共子序列中,长度最长的那个,定义为X和Y的最长公共子序列。
egg:字符串13455与245576的最长公共子序列为455
    字符串acdfg与adfc的最长公共子序列为adf

注意：最长公共子序列与最长公共子串不同，后者要求连续

*/
/*LCS可以描述两段文字之间的“相似度”,即它们的雷同程度,从而能够用来辨别抄袭。另一方面,对一段文字进行修改之后,计算改动前后文字的最长公共子序列,将除此子序列外的部分提取出来,这
种方法判断修改的部分,往往十分准确*/

///解析：动态规划

/*
LCS（Xm,Yn）= LCS(X(m-1),Y(n-1))+Xm  if Xm=Yn

LCS（Xm,Yn）= max(LCS(X(m-1),Y(n)),LCS(X(m),Y(n-1)))  if Xm !=Yn
*/

//使用二维数组C[m,n],c[i,j]记录序列Xi和Yj的最长公共子序列的长度。当i=0或j=0时,空序列是Xi和Yj的最长公共子序列,故c[i,j]=0

///使用二维数据B[m,n],其中,b[i,j]标记c[i,j]的值是由哪一个子问题的解达到的。即c[i,j]是由c[i-1,j-1]+1或者c[i-1,j]或者c[i,j-1]的哪一个得到的。取值范围为Left,Top,LeftTop三种情况

void lcs(const char* str1, const char* str2, string& str)
{
    int i,j;
    int size1 = (int)strlen(str1);
    int size2 = (int)strlen(str2);
    int chese[size1+1][size2+1];
    for(i = 0;i<=(size1+1);i++)
        chese[i][0] = 0;
    for(j = 0;j<=(size2+1);j++)
        chese[0][j] = 0;

    for(i=1;i<=(size1+1);i++)
    {
        for(j=1;j<(size2+1);j++)
        {
            if(s1[i]==s[j])
                chese[i][j] = chese[i-1][j-1]+1;
            else
                chese[i][j] = max(chese[i][j-1],chese[i-1][j]);
        }
    }

}
