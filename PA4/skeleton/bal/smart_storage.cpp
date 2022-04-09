#include "smart_storage.h"

using namespace std;

// During ZINC grading, TA will provide some of his code to help you achieve the goal.
// For example, when grading the function select_container_for_buyer, TA will provide his code of deselect_container.
// This allows you to get points even without the implementation of deselect_container.
// However, there are some drawbacks as TA's code may not be compatible with yours, and you may fail in some cases.
// Therefore, if you are confident with your implementation and don't want TA to help you,
// uncomment the following line (make sure there is no space before '#'):
#define PLEASE_DONT_HELP_ME

// You can define the following helper functions.
// Note that they are optional. If you don't need them, just delete them.
// They are just hints for your reference and the grader won't check them.

// Helper functions begin.

int num_children(const SmartContainer *p)
{
    // Return the number of children given a smart container.
    int x = 0;
    if (p->left != nullptr){++x;}
    if (p->right != nullptr){++x;}
    return x;
}

bool on_tree(SmartContainer *p)
{
    // Return true if the container is on a BST else false.
    return ((p->parent != nullptr) || (p->left != nullptr) || (p->right != nullptr))?true:false;
}

SmartContainer *&get_first_child(SmartContainer *p)
{
    // Return a reference to the first non-null child pointer.
    // If it does not have a non-null child pointer,
    // just return either of the null child pointer.
    return (p->left)?p->left:p->right;
}
SmartContainer *loop_root(SmartContainer *p){ // my own helper func to find the root from a given node in a bst recursively
    if (p->parent == nullptr){
        return p;
    }
    return loop_root(p->parent);
}
SmartContainer *find_root(const vector<Container *> &containers, Container *ignored = nullptr)
{
    cout << "findroot" << endl;
    // Find the root from the containers.
    // Ignore the 'ignored' container to avoid treating the node to be inserted as the root.
    //cout << "ignored: " << ignored << endl;
    for (Container* i : containers){
        if (i->empty()||i == ignored){continue;}
        SmartContainer *x = dynamic_cast<SmartContainer *>(i);
        //cout << "not empty" << endl;
        if (x->parent == nullptr && (x->left || x->right)){
            return x;
        }
        if (x->parent == nullptr ){
            return x;
        }
        if (x->parent != nullptr){
            return loop_root(x);
        }
    }
    return nullptr;
}

SmartContainer *find_just_heavier(SmartContainer *root, const SmartContainer *reference)
{
    // Find a container that is just heavier than the reference container.
    //cout << "ohnooooo" << endl;
    
    if (root == nullptr){
        return nullptr;
    }
    if (reference->empty()){
        if (root->left == nullptr){
            return root;
        }
        //cout << "ohnooooo1" << endl;
        return find_just_heavier(root->left, reference);
    }
    if (!(*reference < *root)){ // ref >= root
        if (!root->right){
            return nullptr;
        }
        //cout << root->right << endl;
        //cout << "ohnooooo2" << endl;
        return find_just_heavier(root->right, reference);
    }else{ // ref < root
        if (!root->left){
            return root;
        }
        //cout << "ohnooooo3" << endl;
        
        SmartContainer *y = find_just_heavier(root->left, reference);
        if(y != nullptr){
            return y;
        }else{
            return root;
        }
    }
}
int get_height(SmartContainer *node);
int height_difference(SmartContainer *root){

    if (root == nullptr){
        return 0;
    }
    return get_height(root->right) - get_height(root->left);
}
void print_tree(SmartContainer*, int);
void rotate_left(SmartContainer* a){

    SmartContainer* b = a->right;
    if (a->parent){
        if (a->parent->left == a){
            a->parent->left = b;
        }else {
            a->parent->right = b;
        }
    }
    b->parent = a->parent;
    a->right = b->left;
    if (b->left){
        b->left->parent = a;
    }
    b->left = a;
    a->parent = b;

}

void rotate_right(SmartContainer* a){
    SmartContainer* b = a->left;
    //cout << "1" << endl;
    if (a->parent){
        if (a->parent->left == a){
            a->parent->left = b;
        }else {
            a->parent->right = b;
        }
    }
    b->parent =a->parent;
    a->left = b->right;
    if (b->right){
        b->right->parent = a;
    }
    b->right = a;
    a->parent = b;


    
}
void balancing_on_breaking_bridges(SmartContainer *root){
    //cout << "hiii" << endl;
    
    int balance_factor = height_difference(root);
    //if (balance_factor == 0) {
        //return;
    //}
    //cout << balance_factor;
    if (balance_factor == 2){
        if (height_difference(root->right) < 0){
            rotate_right(root->right);

        }
        rotate_left(root);
    }else if(balance_factor == -2){
        if (height_difference(root->left) > 0){
            rotate_left(root->left);
        }
        //cout << "here" << endl;
        rotate_right(root);
    }
}

void insert_node(SmartContainer *root, SmartContainer *node)
{
    // Insert a node to the BST given its root.
    //cout << "here" << endl;
    if (node->empty() || root == nullptr){
        return;
    }
    if (root == node){
        return;
    }
    if (num_children(root) == 0){
        //cout << "no child" << endl;
        if (*root < *node){
            root->right = node;
            node->parent = root;
            node->right = node->left = nullptr;
        } else{
            root->left = node;
            node->parent = root;
        }
    }else{
    if(*root < *node){
        //cout << " bigger" << endl;
        if (!root->right){
            root->right = node;
            node->parent = root;
            node->right = node->left = nullptr;
        }else{
            insert_node(root->right, node);
        }
    }else{
        //cout << "smaller" << endl;
        if (!root->left){
            root->left = node;
            node->parent = root;
            node->right = node->left = nullptr;
        }else{
            insert_node(root->left, node);
        }
    }
    }
}

int get_height(SmartContainer *node){ // my helper function to get the height of the node
    if (node == nullptr){
        return -1;
    }
    if (node->left == nullptr && node->right == nullptr){
        return 0;
    } else if (node->right == nullptr && node->left != nullptr){
        return 1 + get_height(node->left);
    } else if (node->right != nullptr && node->left == nullptr){
        return 1 + get_height(node->right);
    } 
    int x = get_height(node->right);
    int y = get_height(node->left);

    if (x >= y){
        return 1 + x;
    }else {
        return 1 + y;
    }
    return 0;
}
SmartContainer * get_min(SmartContainer *node){
    if (node->left == nullptr){
        return node;
    } else {return get_min(node->left);}
} 

SmartContainer * get_max(SmartContainer *node){
    if (node->right == nullptr){
        return node;
    } else {return get_max(node->right);}
}
void detach_node(SmartContainer *node)
{
    // Detach (delete, without destruction though) a node from the BST given the node.
    if (!on_tree(node) || node == nullptr){ // when given node is invalid
        return;
    }
    if (num_children(node) == 2){//when given node has two children
        SmartContainer * new_root;//store the replacement
        //cout << "left tree height: " << get_height(node->left) << endl;
        //cout << "right tree height: " << get_height(node->right) << endl;
        if (get_height(node->left) <= get_height(node->right)){ // see which method will result a more balance bst

            new_root = get_min(node->right); // min approach(right tree)
        } else {

            new_root = get_max(node->left); // max approach(left tree)
        }
        // swap parent
        if (node->parent){ // node isnt root if pass this logical expression
        //cout << "node isnt root" << endl;
            if (node->parent->left == node){ 

                node->parent->left = new_root; // node is parent's left child
            }else {

                node->parent->right = new_root; // node is parent's right child
            }
        }
        if (new_root->parent->left == new_root){ 

                new_root->parent->left = node; // new_root is parent's left child
            }else {

                new_root->parent->right = node; // new_root is parent's right child
            }
        // switch parent
        SmartContainer *node_parent = node->parent;
        node->parent = new_root->parent;
        new_root->parent = node_parent;
        //cout << "oh" << new_root->parent << endl;

        // swap child
        node->left->parent = node->right->parent = new_root; // node children's parent pointing to new root

        if (new_root->left != nullptr){ // check if new root have children
            new_root->left->parent = node;
        }
        if (new_root->right != nullptr){
            new_root->right->parent = node;
        }
        // switch children
        SmartContainer *node_left = node->left;
        SmartContainer *node_right = node->right;
        node->left = new_root->left;
        node->right = new_root->right;
        new_root->right = node_right;
        new_root->left = node_left;

        detach_node(node); // recursively detach node until it completely out of the bst
    }else if(num_children(node) == 1){
        if (node->parent){
            if (node->parent->left == node){ // if node has parent or not

                node->parent->left = (node->left)?node->left:node->right;

            }else {

                node->parent->right = (node->left)?node->left:node->right;
            }
        }
        if (node->left){ //if the child is left

            node->left->parent = node->parent;
            
        } else { // if the child is right or no child at all
            node->right->parent = node->parent;
        }

    }else{
        if (node->parent != nullptr){
            if (node->parent->left == node){ // if node has parent or not

                node->parent->left = nullptr;

            }else {

                node->parent->right = nullptr;
            }
        }
    }
    node->parent = node->right = node->left = nullptr;
}

void print_tree(SmartContainer *x, int height){
    if (x == nullptr){
        return;
    }
    print_tree(x->right, height + 1);

    //for (int j = 0; j < height; ++j)
        //cout << '\t';
    //cout<<"self: " << x  << endl;
    for (int j = 0; j < height; ++j)
        cout << '\t';
    cout << x->weight()  << endl;
    //cout << "para: "<< x->parent  << endl;
    //for (int j = 0; j < height; ++j)
    //    cout << '\t';
    //cout << "left: "<< x->left  << endl;
    //for (int j = 0; j < height; ++j)
    //    cout << '\t';
    //cout << "righ: " << x->right << endl;
    print_tree(x->left, height + 1);
    
}


// Helper functions end.

void SmartStorage::select_container_for_buyer()
{
    // An example implementation of select_container_for_buyer is given below for your reference:

    SmartContainer *downcasted_reference = dynamic_cast<SmartContainer *>(reference);
    // // Select the container containing the cheapest gem for the buyer.
    // // If the reference container contains a gem from the customer, find a heavier gem.

    selected = find_just_heavier(find_root(containers), downcasted_reference);
}

void SmartStorage::deselect_container()
{
    // An example implementation of deselect_container is given below for your reference:
    if (selected)
    {
        SmartContainer *downcasted_selected = dynamic_cast<SmartContainer *>(selected);

    //     // As the customer may have changed the content of the selected container, the structure of the BST has to be changed here.
    //     // If a buyer bought the gem away, then the empty selected container should be removed from the BST.
    //     // On the other hand, if a seller sold a gem, the new non-empty container should be put on the BST.
    //     // Hint: You don't have to put the first non-empty container onto the BST.

         if (!downcasted_selected->empty() && !on_tree(downcasted_selected))
        {
    //         // The selected container is not empty but it's not on the BST.
    //         // The customer may have sold us a gem.
    //         // Attach the selected container on the BST.

    //         // Find the root, note that don't mistake the selected one as the root.
    //         // Then insert the selected node on the BST.
        
            //cout << "seller sold a gem" << endl;

            insert_node(find_root(containers, selected), downcasted_selected);
            balancing_on_breaking_bridges(find_root(containers, selected));
            
         }
            else if (downcasted_selected->empty() && on_tree(downcasted_selected))
         {
    //         // The selected container is empty.
    //         // The customer may have bought the gem away.
    //         // Detach the selected container from the BST.
            //cout <<"buyer bought gem" << endl;
            detach_node(downcasted_selected);
         }

    //     // Don't forget to deselect!
         selected = nullptr;
         
     }
     //cout << "root: " << find_root(containers) << endl;
     
     //print_tree(find_root(containers), 1);
     
}
