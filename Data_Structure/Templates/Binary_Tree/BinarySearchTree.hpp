/*
 * Author: Chung-Yang (Ric) Huang, WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (c) 2009-present LaDs(III), GIEE, NTU, Taiwan
 * Copyleft (C) 2020 WildfootW all rights reversed
 */

#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <cassert>

using namespace std;

template <class Data> class BSTree;

// BSTreeNode is supposed to be a private class. User don't need to see it.
// Only BSTree and BSTree::iterator can access it.
template <class Data>
class BSTreeNode
{
    friend class BSTree<Data>;
    friend class BSTree<Data>::iterator;

    BSTreeNode(const Data& d, BSTreeNode<Data>* parent = nullptr, BSTreeNode<Data>* rchild = nullptr, BSTreeNode<Data>* lchild = nullptr):
        _data(d), _parent(parent), _rchild(rchild), _lchild(lchild)
    {
        update_size();
    }

    void update_size()
    {
        _size = 1;
        if(_rchild != nullptr)
            _size += _rchild->_size;
        if(_lchild != nullptr)
            _size += _lchild->_size;
    }
    BSTreeNode<Data>* get_rchild_end() const       // find maximal
    {
        BSTreeNode<Data> const * ret(this);
        while(ret->_rchild != nullptr)
            ret = ret->_rchild;
        return const_cast<BSTreeNode<Data>*>(ret);
    }
    BSTreeNode<Data>* get_lchild_end() const       // find minimal
    {
        BSTreeNode<Data> const * ret(this);
        while(ret->_lchild != nullptr)
            ret = ret->_lchild;
        return const_cast<BSTreeNode<Data>*>(ret);
    }
    BSTreeNode<Data>* get_lparent_end() const
    {
        BSTreeNode<Data> const * ret(this);
        while(ret->_parent != nullptr && ret->_parent->_rchild == ret) // Guarantee it is left parent
            ret = ret->_parent;
        return const_cast<BSTreeNode<Data>*>(ret);
    }
    BSTreeNode<Data>* get_rparent_end() const
    {
        BSTreeNode<Data> const * ret(this);
        while(ret->_parent != nullptr && ret->_parent->_lchild == ret)
            ret = ret->_parent;
        return const_cast<BSTreeNode<Data>*>(ret);
    }

    Data              _data;
    BSTreeNode<Data>* _parent;
    BSTreeNode<Data>* _rchild;
    BSTreeNode<Data>* _lchild;
    size_t            _size;       // number of childs (include itself)
};

template <class Data>
class BSTree
{
public:
    BSTree()
    {
        _maximum = new BSTreeNode<Data>(Data());
    }
    ~BSTree() { clear(); delete _maximum; }

    class iterator
    {
        friend class BSTree;

    public:
        iterator(BSTreeNode<Data>* n = nullptr): _node(n) {}
        iterator(const iterator& i) : _node(i._node) {}
        ~iterator() {} // Should NOT delete _node

        const Data& operator * () const { return _node->_data; }
              Data& operator * ()       { return _node->_data; }

        iterator& operator = (const iterator& i) { this->_node = i._node; return (*this); }

        bool operator == (const iterator& i) const { return (this->_node == i._node); }
        bool operator != (const iterator& i) const { return !((*this) == i); }

        iterator& operator ++ ()     // Successor (return nullptr if _node is maximum)
        {
            if(_node->_rchild != nullptr)
                _node = _node->_rchild->get_lchild_end();
            else
                _node = _node->get_lparent_end()->_parent;
            return (*this);
        }
        iterator operator ++ (int) { iterator ret(*this); ++(*this); return ret; }  // postfix
        iterator& operator -- ()     // Predecessor (return nullptr if _node is minimum)
        {
            if(_node->_lchild != nullptr)
                _node = _node->_lchild->get_rchild_end();
            else
                _node = _node->get_rparent_end()->_parent;
            return (*this);
        }
        iterator operator -- (int) { iterator ret(*this); --(*this); return ret; }
        iterator operator + (int num)
        {
            iterator ret = (*this);
            while(num--)
                ++ret;
            return ret;
        }
        iterator operator - (int num)
        {
            iterator ret = (*this);
            while(num--)
                --ret;
            return ret;
        }

    private:
        BSTreeNode<Data>* _node;
    };

    iterator begin() const { return iterator(_maximum->get_lchild_end()); }
    iterator end()   const { return iterator(_maximum); }
    iterator back()  const { return end() - 1; }

    bool empty() const { return (size() == 0); }
    size_t size() const { return (_maximum->_size - 1); }

    void insert(const Data& x)
    {
        if(empty())
        {
            BSTreeNode<Data>* new_node = new BSTreeNode<Data>(x, _maximum);
            _maximum->_lchild = new_node;
            _maximum->_size = 2;
            return;
        }
        BSTreeNode<Data>* current = _maximum->_lchild;
        while(true)
        {
            if(current->_data >= x)
            {
                if(current->_lchild == nullptr)
                {
                    BSTreeNode<Data>* new_node = new BSTreeNode<Data>(x, current);
                    current->_lchild = new_node;
                    update_size_upward(new_node);
                    break;
                }
                current = current->_lchild;
            }
            else
            {
                if(current->_rchild == nullptr)
                {
                    BSTreeNode<Data>* new_node = new BSTreeNode<Data>(x, current);
                    current->_rchild = new_node;
                    update_size_upward(new_node);
                    break;
                }
                current = current->_rchild;
            }
        }
    }

    iterator find(const Data& x) const
    {
        if(empty())
            return end();
        BSTreeNode<Data>* current = _maximum->_lchild;
        while(true)
        {
            if(current->_data > x)
            {
                if(current->_lchild == NULL)
                    break;
                current = current->_lchild;
            }
            else if(current->_data < x)
            {
                if(current->_rchild == NULL)
                    break;
                current = current->_rchild;
            }
            else
                return iterator(current);
        }
        return end();
    }

    bool erase(iterator pos)
    {
        BSTreeNode<Data>* current = pos._node;
        BSTreeNode<Data>* parent  = current->_parent;
        if(current->_rchild == nullptr && current->_lchild == nullptr)
        {
            if(parent->_rchild == current)
                parent->_rchild = nullptr;
            else if(parent->_lchild == current)
                parent->_lchild = nullptr;
            delete current;
            update_size_upward(parent);
        }
        else if(current->_rchild == nullptr || current->_lchild == nullptr)
        {
            BSTreeNode<Data>* child = current->_rchild;
            if(child == nullptr)
                child = current->_lchild;

            if(parent->_rchild == current)
                parent->_rchild = child;
            else if(parent->_lchild == current)
                parent->_lchild = child;
            child->_parent = parent;
            delete current;
            update_size_upward(parent);
        }
        else
        {
            iterator successor = iterator(current) + 1;
            current->_data = successor._node->_data;    // really?
            erase(successor);
        }
        return true;
    }
    bool erase(const Data& x)
    {
        iterator it = find(x);
        if(it == end())
            return false;
        return erase(it);
    }
    void pop_front() { erase(begin()); }
    void pop_back() { erase(back()); }

    // PostOrder
    void clear() { clear_dfs(_maximum->_lchild); }

private:
    BSTreeNode<Data>*  _maximum;   // Dummy node
    void clear_dfs(BSTreeNode<Data>* node)
    {
        if(node == nullptr) return;
        clear_dfs(node->_lchild);
        clear_dfs(node->_rchild);
        erase(iterator(node));
    }
    void update_size_upward(BSTreeNode<Data>* node)
    {
        do
        {
            node->update_size();
            node = node->_parent;
        }
        while(node != nullptr);
    }

#ifndef NDEBUG
public:
    void print_preorder()  const { print_preorder_dfs(_maximum->_lchild); }
    void print_inorder()   const { print_inorder_dfs(_maximum->_lchild); }
    void print_postorder() const { print_postorder_dfs(_maximum->_lchild); }
private:
    void print_preorder_dfs(BSTreeNode<Data>* node) const
    {
        if(node == nullptr) return;
        cout << " " << node->_data;
        print_preorder_dfs(node->_lchild);
        print_preorder_dfs(node->_rchild);
    }
    void print_inorder_dfs(BSTreeNode<Data>* node) const
    {
        if(node == nullptr) return;
        print_inorder_dfs(node->_lchild);
        cout << " " << node->_data;
        print_inorder_dfs(node->_rchild);
    }
    void print_postorder_dfs(BSTreeNode<Data>* node) const
    {
        if(node == nullptr) return;
        print_postorder_dfs(node->_lchild);
        print_postorder_dfs(node->_rchild);
        cout << " " << node->_data;
    }
#endif // NDEBUG
};

#endif // BINARYSEARCHTREE_HPP
