/*给定一个无向连通图,假定图中所有
边的权值都为1,显然,从源点A到终点T的
最短路径有多条,求不同的最短路径的数
目*/


///解析：权值相同的最短路径问题,则单源点Dijkstra算法退化成BFS广度优先搜索

///1初始化：结点步数step[0...N-1]初始化为0;路径数目pathNum[1...N-1]初始化为0; pathNum[0] = 1

///分析： 若从当前结点i扩展到邻接点j时:
///      若step[j]为0,则 step[j]=step[i]+1   pathN[j] = pathN[i]（未访问过节点j）
///      若step[j]==step[i]+1,则 pathN[j] += pathN[i]   （已经访问过j）
///一旦扩展到结点N,则提前终止算法



const int N = 16;
int calc(int G[N][N])
{
    int step[N];
    int pathN[N];
    memset(step,0,sizeof(int)*N);
    Memset(pathN,0,sizeof(int)*N);
    pathN[0]=1;

    queue<int>q;
    q.push(0);
    int from,i,s;///开始节点from
    while(!q.empty())
    {
        from = q.front();
        q.pop();///节点from 出队
        s = step[from] + 1;
        for(i=1;i<N;i++)///0是起点 不遍历
        {
            if(G[from][i]==1)///连通
                if(step[i]==0||step[i]>s)///未访问过
                {
                    step[i]=s;
                    pathN[i] = pathN[from];
                    q.push(i);
                }
                else if(step[i]==s)
                {
                    pathN[i] += pathN[from]
                }



        }

    }
}












