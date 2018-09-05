//哈弗曼树结点结构
typedef struct{
        int weight;//结点权重
        int parent,left,right;//父节点、左孩子、右孩子在数组中的位置下标
}HTNode,*HuffmanTree;
