#pragma once

/* ⭐结点类 */
template <typename Item>
class AVLTreeNode
{
public:
    /* 构造，初始化 */
    AVLTree(int data) :m_data(data), m_height(height), m_left(nullptr), m_right(nullptr), m_parent(nullptr)
    {};

    /* 创建新结点 */
    static AVLTreeNode creatNode(Item data, AVLTreeNode *parent);
    ~AVLTree(){}; //todo...

private:
    Item m_data;//数据
    int m_height;//自我高度
    AVLTreeNode *m_left;//左子树
    AVLTreeNode *m_right;//右子树
    AVLTreeNode *m_parent;//父结点
};

/* 创建新结点 */
template <typename Item>
inline AVLTreeNode<Item> AVLTreeNode<Item>::creatNode(Item data, AVLTreeNode *parent)
{
    /* 给结点分配空间 */
    AVLTreeNode newNode = new AVLTreeNode();
    /* 清除脏数据 */
    memset(AVLTreeNode, 0, sizeof(AVLTreeNode));
    {
        newNode.m_data = 0;
        newNode.m_height = 0;
        newNode.m_left = nullptr;
        newNode.m_right = nullptr;
        newNode.m_parent = nullptr;
    }

    /* 赋值 */
    newNode.m_data = data;
    newNode.m_parent = parent;

    return newNode;
}




/* ⭐ AVLTree类 */
template <typename Item>
class AVLTree
{
public:
    /* 树设置单例 */
    static AVLTree *Instance()
    {
        static AVLTree tree;
        return &tree;
    }
    
    /* 方法 */
    void AVLTreeInit(int (*m_compare)(Item val1, Item val2), int (*m_printFunc)(Item data));//初始化
    int  AVLTreeBalanceFactor(AVLTreeNode<Item> * node);//平衡因子
    bool AVLTreeIsBalance(AVLTreeNode<Item> * node);//是否平衡
    bool currentNodeIsLeft(AVLTreeNode<Item> * node);//当前结点是左子树
    bool currentNodeIsRight(AVLTreeNode<Item> * node);//当前结点是右子树
    int  AVLTreeChangeHeight(AVLTreeNode<Item> * node);//调整高度
    int  levorotation(AVLTreeNode<Item> * node);//左旋
    int  dextrorotation(AVLTreeNode<Item> * node);//右旋
    int  AVLTreeChangeBalance(AVLTreeNode<Item> * node);//调整平衡

    bool AVLTreeInsert(Item data);//插入
    void AVLTreeInsertAfter(AVLTreeNode<Item> * node);
    bool AVLTreeIsContainAppointVal(Item data);

    ~AVLTree(){};

private:
    AVLTreeNode<Item> *m_root;//根结点
    int m_size;//结点数
    int (*m_compare)(Item val1, Item val2);
    int (*m_printFunc)(Item data);
    /* 构造 */  
    AVLTree() : m_root(nullptr), m_size(0)
    {
        //m_root = new AVLTreeNode<Item>(0);
    };
};


/* 初始化 */
template <typename Item>
inline void AVLTree<Item>::AVLTreeInit(int (*compare)(Item val1, Item val2), int (*printFunc)(Item data))
{
    m_compare = compare;
    m_printFunc = printFunc;
}

/* 计算平衡因子 */
template <typename Item>
inline int AVLTree<Item>::AVLTreeBalanceFactor(AVLTreeNode<Item> *node)
{
    int leftHeight = node->m_left == nullptr ? 0 : node->m_left->m_height;
    int rightHeight = node->m_right == nullptr ? 0 : node->m_right->m_height;

    return leftHeight - rightHeight;
}

/* 是否平衡 */
template <typename Item>
inline bool AVLTree<Item>::AVLTreeIsBalance(AVLTreeNode<Item> *node)
{
    int factor = this->AVLTreeBalanceFactor(node);
    if (abs(factor) <= 1)
    {
        return true;
    }
    
    return false;
}

//当前结点是左子树
template <typename Item>
inline bool AVLTree<Item>::currentNodeIsLeft(AVLTreeNode<Item> *node)
{
    if (node->m_parent != nullptr && node == node->m_parent->m_left )
    {
        return true;
    }
    
    return false;
}

//当前结点是右子树
template <typename Item>
inline bool AVLTree<Item>::currentNodeIsRight(AVLTreeNode<Item> *node)
{
    if (node->m_parent != nullptr && node == node->m_parent->m_right)
    {
        return true;
    }
    
    return false;
}

/* 调整当前结点高度 */
template <typename Item>
inline int AVLTree<Item>::AVLTreeChangeHeight(AVLTreeNode<Item> *node)
{
    int leftHeight = node->m_left == nullptr ? 0 : node->m_left->m_height;
    int rightHeight = node->m_right == nullptr ? 0 : node->m_right->m_height;
    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return 1 + rightHeight;
}

/* 左旋 */
template <typename Item>
inline int AVLTree<Item>::levorotation(AVLTreeNode<Item> *node)
{
    return 0;
}

/* 右旋 */
template <typename Item>
inline int AVLTree<Item>::dextrorotation(AVLTreeNode<Item> *node)
{
    return 0;
}

/* 调整平衡 */
template <typename Item>
inline int AVLTree<Item>::AVLTreeChangeBalance(AVLTreeNode<Item> *node)
{
    /* L */
    if (currentNodeIsLeft(node->m_parent))
    {
        /* LL */
        if (currentNodeIsLeft(node))
        {
            /* RR */

        }
        else/* LR */
        {
            /* RL */

        }
    }/* R */
    else
    {
        /* RR */
        if (currentNodeIsRight(node))
        {
            /* LL */

        }/* RL*/
        else
        {
            /* LR */
        }  
    }
    
    return 0;
}

/* 插入数据 */
template <typename Item>
inline bool AVLTree<Item>::AVLTreeInsert(Item data)
{
    /* 如果是根结点 -- 直接添加 */
    if (this->m_root == nullptr)
    {
        this->m_root = AVLNode :: createNode(data, nullptr);
        this->m_size++;
        /* ⭐todo...AVLT添加之后应该判断是否平衡并进行调整 */
        return true;
    }
    
    /* 先要判断插在哪里 -- 从根结点开始 */
    AVLTreeNode<Item> * travelNode = m_root;
    AVLTreeNode<Item> * parentNode = m_root;
    int cmp = 0;
    /* 找位置 */
    while (travelNode)
    {
        /* 记录父结点 */
        parentNode = travelNode;
        cmp = m_compare(data, travelNode->m_data);
        if ( cmp < 0 )
        {
            /* 左边 */
            travelNode = travelNode->m_left;
        }
        else if (cmp > 0)
        {
            /* 右边 */
            travelNode = travelNode->m_right;
        }
        else
        {
            /* 相等的时候直接跳出去 */
            break;
        }
    }
    /* 封装成结点 --插入 */
    AVLTreeNode<Item> * node = AVLNode :: createNode(data, parentNode); //程序运行到这，一定不是空树，且它有父结点，故在封装时带上父结点，避免最后忘记更新
    if (cmp < 0)
    {
        travelNode->m_left = node;
    }
    else
    {
        travelNode->m_right = node;
    }
    m_size++;
    /* ⭐todo...AVLT添加之后应该判断是否平衡并进行调整 */
    
    return true;
}

/* 插入之后的调整 */
template <typename Item>
inline void AVLTree<Item>::AVLTreeInsertAfter(AVLTreeNode<Item> *node)
{
    /* 一定是在叶子结点的地方插入了新结点 -- 先判断从父结点到根结点是否都保持平衡 */
    while (node->m_parent)
    {
        /* 平衡则调整当前结点高度 */
        if (this->AVLTreeIsBalance(node))
        {
            this->AVLTreeChangeHeight(node);
        }
        else
        {
            /* 调整平衡 */
        }
        node = node->m_parent;
    }
    
    
}
