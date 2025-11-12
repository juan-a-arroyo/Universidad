Node* Node::insertNode(Node* root, int val)
{
    if(!root)
        return new Node(val);
    if(val>root->Val)
        root->Right = insertNode(root->Right, val);
    if(val<root->Val)
        root->Left = insertNode(root->Left, val);
    return root;
}