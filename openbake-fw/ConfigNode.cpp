// 
// 
// 

#include "ConfigNode.h"

ConfigNode::ConfigNode(String _name, ConfigNode* _parent, ConfigNode** _children, int _num_children)
{
	exit_node = false;
	name = _name;
	parent = _parent;
	children = _children;
	num_children = _num_children;
}

ConfigNode::ConfigNode(String _name, View::ViewType _exit_dest)
{
	exit_node = true;
	name = _name;
	exit_dest = _exit_dest;
}

ConfigNode::~ConfigNode()
{
	if (!exit_node)
	{
		for (int i = 0; i < num_children; i++)
		{
			delete children[i];
		}
	}
}


