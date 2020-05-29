/*
 * Author: Chung-Yang (Ric) Huang, WildfootW
 * GitHub: github.com/WildfootW
 * Copyleft (c) 2009-present LaDs(III), GIEE, NTU, Taiwan
 * Copyleft (C) 2020 WildfootW all rights reversed
 * MinHeap Template implemented with array (complete binary tree)
 */

#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <algorithm>
#include <vector>
#include <cassert>

template <class Data>
class MinHeap
{
public:
    MinHeap(size_t s = 0)
    {
        if (s != 0) _data.reserve(s + 1);
        _data.push_back(Data()); // Dummy Node
    }
    ~MinHeap() {}

    void clear() { _data.erase(_data.begin() + 1, _data.end()); }

    size_t size() const { return _data.size() - 1; }
    bool empty() const { return size() == 0; }

    const Data& min() const
    {
        assert(size());
        return _data[1];
    }

    void insert(const Data& d)
    {
        _data.push_back(d);
        size_t current = size();
        while(parent(current) != 0)
        {
            if(_data[current] < _data[parent(current)]) // if current value is smaller than parent
            {
                iter_swap(_data.begin() + current, _data.begin() + parent(current));
                current = parent(current);
            }
            else
                break;
        }
    }
    void del_min() { del_data(0); }
    void del_data(size_t n) // delete index n
    {
        assert(size() > n);

        size_t current = n + 1;
        iter_swap(_data.begin() + current, _data.end() - 1); // swap selected node with last node
        _data.pop_back();


        // if have rchild and rchild is smaller, swap
        while(lchild(current) < _data.size()) // check if we still have child
        {
            // select min child
            size_t child = lchild(current);
            if(rchild(current) < _data.size()) // rchild exist
            {
                if(_data[rchild(current)] < _data[lchild(current)])
                    child = rchild(current);
            }

            if(_data[child] < _data[current])
            {
                iter_swap(_data.begin() + child, _data.begin() + current);
                current = child;
            }
            else
                break;
        }
    }

#ifndef NDEBUG
    void print_array() const
    {
        for(size_t i = 0;i < _data.size();++i)
        {
            cout << i << " : " << _data[i] << endl;
        }
    }
#endif // NDEBUG

private:
    vector<Data>   _data;   // _data[0] is dummy node;

    inline static size_t parent(const size_t& x) { return x / 2; }
    inline static size_t lchild(const size_t& x) { return x * 2; }
    inline static size_t rchild(const size_t& x) { return x * 2 + 1; }

    // For the following member functions,
    // We don't respond for the case vector "_data" is empty!
    const Data& operator [] (size_t i) const { return _data[i + 1]; }
          Data& operator [] (size_t i)       { return _data[i + 1]; }
};

#endif // MINHEAP_HPP
