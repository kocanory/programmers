#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct node{
    node * l = NULL;
    node * r = NULL;
    int num;
    int x;
}node;

bool comp(vector<int> a, vector<int> b)
{
    if(a[1] == b[1]) return a[0] < b[0];
    return a[1] > b[1];
}

void SetPostorder(vector<int> *postorder, node *r)
{
    if(r->l != NULL) SetPostorder(postorder, r->l);
    if(r->r != NULL) SetPostorder(postorder, r->r);
    postorder->push_back(r->num);
}

void SetPreorder(vector<int> *preorder, node *r)
{
    preorder->push_back(r->num);
    if(r->l != NULL) SetPreorder(preorder, r->l);
    if(r->r != NULL) SetPreorder(preorder, r->r);
}

void SetTree(node *r, node *c)
{
    if(r->x > c->x)
    {
        if(r->l == NULL) r->l = c;
        else SetTree(r->l, c);
    }
    else
    {
        if(r->r == NULL) r->r = c;
        else SetTree(r->r, c);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer(2, vector<int>(0));
    vector<node> nodes;
    
    for(int i = 0;i < nodeinfo.size();i++)
    {
        nodeinfo[i].push_back(i + 1);
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), comp);
    for(int i = 0;i < nodeinfo.size();i++)
    {
        node n;
        n.num = nodeinfo[i][2];
        n.x = nodeinfo[i][0];
        nodes.push_back(n);
    }
    for(int i = 1;i < nodes.size();i++)
        SetTree(&nodes[0], &nodes[i]);
    
    SetPreorder(&answer[0], &nodes[0]);
    SetPostorder(&answer[1], &nodes[0]);
    return answer;
}