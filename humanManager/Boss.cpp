//
// Created by knigh on 2020/11/19.
//
#include "Boss.h"

Boss::Boss(int id,string name,int did){
    this->m_Id = id;
    this->m_Name = name;
    this->m_Dept = did;
};
void Boss::showInfo(){
    cout << "职工编号: " << this->m_Id
         << "\t职工姓名: " <<this->m_Name
         << "\t岗位: " << this->getDeptName()
         << "\t岗位职责: 给经理下发任务" <<endl;
};
string Boss::getDeptName(){
    return string("老板");
};
