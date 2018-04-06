/*
拓扑排序:
对一个有向无环图(Directed Acyclic Graph,DAG)G进行拓扑排序,是将G中所有顶点排成线性序列,使得图中任意一对顶点u和v,
若边(u,v)∈E(G),则u在线性序列中出现在v之前。*/

///1.从有向图中选择一个没有前驱(即入度为0)的顶点并且输出它;
///2.从网中删去该顶点,并且删去从该顶点发出的全部有向边;
///3 重复上述两步,直到剩余的网中不再存在没有前趋的顶点为止。

/*总结：1.拓扑排序算法可以发现圈;
       2.其本质是不断输出入度为0的点;
       3.可以用队列(或者栈)保存入度为0的点,避免每次遍历所有点查找入度;
            排序列表中的点需要更新与之连接的点的入度。入度减小1之后,如果为0,放入队列(或者栈)中。
       4.拓扑排序其实是给定了结点的一组偏序关系

///节点数为n 用邻接矩阵graph[n][n]存储边权
///用indegree[n]存放节点的度
///toposort[n]存放拓扑顺序

void topologic(int* toposort)
{
    int cnt=0; ///记录当前的拓扑序列中的节点个数
    queue<int>q;
    int i;
    for(i=0;i<n;i++)///保存入度为0的节点
    {
        if(indegree[i]==0)
            q.push(i);
    }
    int cur;
    while(!q.empty())
    {
        cur = q.front();///可以使用队列中的其他入度为0 的点
        q.pop();
        toposort[cnt++] = cur;
        for(i = 0;i < n;i++)
        {
            if(graph[cur][i]!=0)
            {
                indegree[i]--;///相连 i节点入度减1
                if(indegree[i]==0)
                    q.push(i);
            }
        }
    }
}
