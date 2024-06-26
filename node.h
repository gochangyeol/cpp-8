#ifndef NODE_H
#define NODE_H

#include "link.h"
#include "packet.h"
#include <vector>

class Node {
  friend class LinkInstaller;

private:
  int id_;
  static int nextId_;
  std::vector<Link*> links_;
public:
  Node() : id_(nextId_++) {}

  int id() const { return id_; }
  
  void addLink(Link *link) {
        links_.push_back(link);
    }
};

#endif