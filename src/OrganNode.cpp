#include "OrganNode.hpp"
OrganNode::OrganNode(Organ* organ,OrganNode* next)
{
    this->organ=organ;
    this->next=next;
}
OrganNode::~OrganNode()
{
    delete organ;
}