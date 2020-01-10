#include "treewalk_7.h"

TreeWalk::TreeWalk()
{

}
string TreeWalk::solve(string s)
{
    qDebug() << "TreeWalk, string:" << QString::fromStdString(s);

    char pre[(s.size()-1)/2];
    char in[(s.size()-1)/2];

    int i=0,j=0;

    for(int k=0;k<s.size();k++)
    {
        if(k<s.size()/2)
        {
            pre[i] = s[k];
            i++;
        }
        else if(k>s.size()/2)
        {
            in[j] = s[k];
            j++;
        }

    }

    int n = sizeof(in) / sizeof(in[0]);

    string vec_post;
    printPostOrder(in, pre, n,vec_post);
    return vec_post;
}
int TreeWalk::search(char arr[], char x, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x){
            return i;
        }
    return -1;
}
void TreeWalk::printPostOrder(char in[], char pre[], int n, string &vec_post)
{
    // The first element in pre[] is always root, search it
    // in in[] to find left and right subtrees
    int root = search(in, pre[0], n);

    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre + 1, root,vec_post);

    // If right subtree is not empty, print right subtree
    if (root != n - 1)
        printPostOrder(in + root + 1, pre + root + 1, n - root - 1,vec_post);

    // Print root
    //vec_post.push_back(pre[0]);
    vec_post = vec_post + pre[0];
}
