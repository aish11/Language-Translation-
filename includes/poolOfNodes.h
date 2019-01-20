#include <vector>
class Node;

class PoolOfNodes {
public:
  static PoolOfNodes& getInstance();
  //void add(const Node* node) { nodePool.push_back(node); }
  void add(const Node* node) 
  {
   if (false == find(node))
      nodePool.push_back(node); 
  }
  bool find(const Node *node)
  {
  	bool result = false;
  	for ( const Node* curr_node : nodePool )
  	{	
    if(node == curr_node)
    	return true;
  	}
  return result;
  }
  	
  void drainThePool();
private:
  std::vector<const Node*> nodePool;
  PoolOfNodes() : nodePool() {}
};
