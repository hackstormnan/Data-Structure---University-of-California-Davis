#include <iostream>
#include <vector>
#include <algorithm>
#include "json.hpp"

#include "priorityqueue.h"

PriorityQueue::PriorityQueue(std::size_t max_size) :
	nodes_(max_size + 1, KeyValuePair()),
	max_size_(max_size),
	size_(0) {
}

void PriorityQueue::insert(Key k) {
	insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv) {
    size_++;
    nodes_[size_] = kv;
    heapifyUp(size_);
}

KeyValuePair PriorityQueue::min() {
    KeyValuePair minimum = nodes_[1];
    return minimum;
}


KeyValuePair PriorityQueue::removeMin() {
    KeyValuePair minimum = nodes_[1];
    std::swap(nodes_[1],nodes_[size_]);
    nodes_.erase(nodes_.begin()+size_ );
    size_--;
    
    heapifyDown(1);
   
    return minimum;
}

bool PriorityQueue::isEmpty() const {
    if (nodes_.empty())
        return true;
    else
        return false;
}

size_t PriorityQueue::size() const {
    return size_;
}

nlohmann::json PriorityQueue::JSON() const {
	nlohmann::json result;
  for (size_t i = 1; i <= size_; i++) {
      nlohmann::json node;
      KeyValuePair kv = nodes_[i];
      node["key"] = kv.first;
      node["value"] = kv.second;
      if (i != ROOT) {
          node["parent"] = std::to_string(i / 2);
      }
      if (2 * i <= size_) {
          node["leftChild"] = std::to_string(2 * i);
      }
      if (2 * i + 1 <= size_) {
          node["rightChild"] = std::to_string(2 * i + 1);
      }
      result[std::to_string(i)] = node;
  }
  result["metadata"]["max_size"] = max_size_-300;
	result["metadata"]["maxHeapSize"] = max_size_-300;

  result["metadata"]["numOperations"];
  result["metadata"]["size"] = size_;
	return result;
}

std::vector<KeyValuePair> PriorityQueue::return_vec() {return nodes_;}


void PriorityQueue::heapifyUp(size_t i) {
    while (i > 1) {
        size_t parent_index = i / 2;
        if (nodes_[parent_index].first > nodes_[i].first) {
            std::swap(nodes_[parent_index],nodes_[i]);
        }
        i = parent_index;
    }
}

void PriorityQueue::heapifyDown(size_t i) {
   
    size_t left=2*i;
    size_t right=2*i+1;
    size_t largest=i;
    if (left<=size_&&nodes_[left]<nodes_[i])
        {largest=left;}
    if (right<=size_&&nodes_[right]<nodes_[largest])
        {largest=right;}
    if(largest!=i){
        std::swap(nodes_[i],nodes_[largest]);
        heapifyDown(largest);
    }
}

void PriorityQueue::removeNode_s(size_t i){removeNode(i);};




void PriorityQueue::removeNode(size_t i) {
  
    std::swap(nodes_[i],nodes_[size_]);
    nodes_.erase(nodes_.begin()+size_);
    size_--;
    heapifyDown(i);

}

Key PriorityQueue::getKey(size_t i) {
    Key key_want;
    key_want = nodes_[i].first;
    return key_want;
}
