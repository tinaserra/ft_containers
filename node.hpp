#ifndef NODE_HPP
#define NODE_HPP

#define RED false
#define BLACK true

template<typename T>
class Node
{
    public:
        typedef Node    node;
        typedef Node*   node_pointer;
        typedef T*      data_pointer;
        bool            color;
        node_pointer    nil_node;
        node_pointer    parent;
        node_pointer    left;
        node_pointer    right;
        data_pointer    data;

        node_pointer    min;
        node_pointer    max;
        Node() : color(RED) {}
        Node(const Node &copy) { return *this; }

        Node &operator=(const Node &rhs) {
            color = rhs.color;
            nil_node = rhs.nil_node;
            parent = rhs.parent;
            left = rhs.left;
            right = rhs.right;
            data = rhs.data;
            min = rhs.min;
            max = rhs.max;
            return *this;
        }

        ~Node() {}

};

#endif