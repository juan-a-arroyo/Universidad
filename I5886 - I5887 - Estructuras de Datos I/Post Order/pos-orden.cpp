void Node::postOrder(Node* root)
{
    if(!root)
        return;
    else{
        postOrder(root->Left);
        postOrder(root->Right);
        cout<<root->Val<<endl;
    }
}