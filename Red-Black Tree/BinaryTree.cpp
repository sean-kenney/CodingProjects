TreeNode * BinaryTree::deleteNode(TreeNode * root, int data)
{
	if(root == nullptr)
	{
		return nullptr;
	}
	else
	{
		if(root->getValue() > data)
		{
			root->setLeftChild(deleteNode(root->getLeftChild(), data));
			return root;
		}
		else if(root->getValue() < data)
		{
			root->setRightchild(deleteNode
		}
		else
		{
			if(root->getLeftChild() == nullptr && root->getRightChild() == nullptr)
			{
				delete root;
				return nullptr;
			}
			else if(root->getLeftChild() == nullptr)
			{
				TreeNode * node = root->getRightChild();
				
				node->setParent(nullptr);
				
				root->setRightchild(nullptr);
				
				delete root;
				
				return node;
			}
			else if(root->getRightChild() == nullptr)
			{
				TreeNode * node = root->getLeftChild();
				node->setParent(nullptr);
				root->setLeftChild(nullptr);
				delete root;
				return node;
			}
			else
			{
				TreeNode * nodeParent = root;
				TreeNode * node = root->getRightChild();
				
				while(node->getLeftChild() != nullptr)
				{
					nodeParent = node;
					node = node->getLeftChild();
				}
				if(nodeParent != root)
				{
					nodeParent->setLeftChild(node->getRightChild());
				}
				else
				{
					nodeParent->setRightchild(node->getRightChild());
				}
				
				root->setValue(node->getValue());
				
				node->setLeftChild(nullptr);
				node->setParent(nullptr);
				node->setRightchild(nullptr);
				
				delete node;
			}
		}
	}
}