/*
* @filee OrganNode.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

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