/*
* @filee SistemNode.cpp
* @description Bagli Liste , Agac, Queue, Radix Sort kullanarak organizma olusturuyor.
* @course Veri Yapilari 1-B
* @assignment 2
* @datee 08/12/2022
* @authorr Eren Kara , errennkaaraa@hotmail.com
*/

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