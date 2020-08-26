// #include <algorithm>
// #include <iostream>
// #include <vector>
// #if defined(__unix__) || defined(__APPLE__)
// #include <sys/resource.h>
// #endif

// class Node;

// class Node {
// public:
//     int key;
//     Node *parent;
//     std::vector<Node *> children;

//     Node() {
//       this->parent = NULL;
//     }

//     void setParent(Node *theParent) {
//       parent = theParent;
//       parent->children.push_back(this);
//     }
// };

// int main_with_large_stack_space() {
//   std::ios_base::sync_with_stdio(0);
//   int n;
//   std::cin >> n;

//   std::vector<Node> nodes;
//   nodes.resize(n);
//   for (int child_index = 0; child_index < n; child_index++) {
//     int parent_index;
//     std::cin >> parent_index;
//     if (parent_index >= 0)
//       nodes[child_index].setParent(&nodes[parent_index]);
//     nodes[child_index].key = child_index;
//   }

//   // Replace this code with a faster implementation
//   int maxHeight = 0;
//   for (int leaf_index = 0; leaf_index < n; leaf_index++) {
//     int height = 0;
//     for (Node *v = &nodes[leaf_index]; v != NULL; v = v->parent)
//       height++;
//     maxHeight = std::max(maxHeight, height);
//   }

//   std::cout << maxHeight << std::endl;
//   return 0;
// }

// int main (int argc, char **argv)
// {
// #if defined(__unix__) || defined(__APPLE__)
//   // Allow larger stack space
//   const rlim_t kStackSize = 16 * 1024 * 1024;   // min stack size = 16 MB
//   struct rlimit rl;
//   int result;

//   result = getrlimit(RLIMIT_STACK, &rl);
//   if (result == 0)
//   {
//       if (rl.rlim_cur < kStackSize)
//       {
//           rl.rlim_cur = kStackSize;
//           result = setrlimit(RLIMIT_STACK, &rl);
//           if (result != 0)
//           {
//               std::cerr << "setrlimit returned result = " << result << std::endl;
//           }
//       }
//   }

// #endif
//   return main_with_large_stack_space();
// }

#include <algorithm>
#include <iostream>
#include <vector>

class TreeHeight {
    int n;
    std::vector<int> parent;

   public:
    void read() {
        std::cin >> n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
            std::cin >> parent[i];
    }

    int compute_height() {
        int maxHeight = 0;
        std::vector<int> heights;
        for (int i = 0; i < parent.size(); i++)
            heights.push_back(0);
        for (int vertex = 0; vertex < n; vertex++) {
            if (heights[vertex] != 0)
                continue;
            int height = 0;
            for (int i = vertex; i != -1; i = parent[i]) {
                if (heights[i] != 0) {
                    height += heights[i];
                    break;
                }
                height++;
            }
            maxHeight = std::max(maxHeight, height);
            for (int i = vertex; i != -1; i = parent[i]) {
                if (heights[i] != 0)
                    break;
                heights[i] = height--;
            }
        }
        return maxHeight;
    }

    int old_compute_height() {
        int maxHeight = 0;
        for (int vertex = 0; vertex < n; vertex++) {
            int height = 0;
            for (int i = vertex; i != -1; i = parent[i])
                height++;
            maxHeight = std::max(maxHeight, height);
        }
        return maxHeight;
    }
};

int main() {
    std::ios_base::sync_with_stdio(0);
    TreeHeight tree;
    tree.read();
    std::cout << tree.compute_height() << std::endl;
}