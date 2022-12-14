#include "SistemNode.hpp"
SistemNode::SistemNode(Sistem* sistem,SistemNode* next)
{
    this->sistem=sistem;
    this->next=next;
}
SistemNode::~SistemNode()
{
    delete sistem;
}