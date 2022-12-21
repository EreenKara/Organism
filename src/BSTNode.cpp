/*
* @filee BSTNode.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

#include "BSTNode.hpp"

BSTNode::BSTNode(Doku* doku,BSTNode* left,BSTNode* right)
{
    this->doku=doku;
    this->left=left;
    this->right=right;
}
BSTNode::~BSTNode()
{
    delete doku;
}