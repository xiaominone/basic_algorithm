/*二叉查找树(二叉搜索树)是满足以下条件的二叉树:
1.左子树上的所有结点值均小于根结点值,
2.右子树上的所有结点值均不小于根结点值,
3.左右子树也满足上述两个条件
*/

///二叉查找树的查找
node* search(node* tree,int value)
{
    if(!tree)
    {
        return null;

    }
    node* sub_node = tree;
    while(sub_node)
    {
        if(value<sub_node->value)
        {
            sub_node = sub_node->left;
        }
        else if
        {
            sub_node = sub_node->right;
        }
        else
        {
            return sub_node;
        }
    }
}

///二叉查找树的插入（构建）
///递归构建
bool insert(node* p, int value)
{
    if(!root)
    {
        root = new node(value);
        return true;
    }
    if(value < root->value)
    {
        return insert(root->left,value);
    }
    if(value > root->value)
    {
        return insert(root->right,value);
    }
    return false;
}
///非递归构建
bool insert2(int value)
{
    if(!root)
    {
        node* root = new node(value);
        return true;
    }
    node* pnode = root;
    node* pcur = root;
    while(pnode)
    {
        pcur = pnode;
        if(value < pnode->value)
            pnode = pnode->left;
        else if(value > pnode->value)
            pnode = pnode->right;
        else
            return false;
    }
    if(value < pcur->value)
        pcur->left = new node(value);
    else if(value > pcur->value)
        pcur->right = new node(value);
    return true;

}

///二叉插找树的删除












