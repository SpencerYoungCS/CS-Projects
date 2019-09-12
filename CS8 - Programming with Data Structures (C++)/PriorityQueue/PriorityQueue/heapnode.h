#ifndef HEAPNODE
#define HEAPNODE


class HeapNode
{
private:
    int Item;

public:
    HeapNode();
    HeapNode(int item);
    ~HeapNode();
    int getItem();
    void setItem(int item);
};

HeapNode::HeapNode()
{
    Item = 0;
}

HeapNode::HeapNode(int item)
{
    Item = item;
}

int HeapNode::getItem()
{
    return Item;
}
void HeapNode::setItem(int item)
{
    Item = item;
}

HeapNode::~HeapNode()
{
}

#endif // HEAPNODE

