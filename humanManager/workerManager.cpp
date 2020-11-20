//
// Created by knigh on 2020/11/19.
//
#include "workerManager.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

WorkerManager::WorkerManager() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    if (!ifs.is_open()) {
//        cout << "文件不存在" <<endl;
        this->m_empNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }
    char ch;
    ifs >> ch;
    if (ifs.eof()) {
        this->m_empNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    int num = this->getEmpNum();

    //计算长度
    this->m_empNum = num;
    //开辟空间
    this->m_EmpArray = new Worker *[this->m_empNum];
    //读取文件内容更新到数组中
    this->initEmp();
    this->m_FileIsEmpty = false;
}


WorkerManager::~WorkerManager() {
    if (this->m_EmpArray != NULL) {
        for (int i = 0; i < this->m_empNum; i++) {
            delete this->m_EmpArray[i];
            this->m_EmpArray[i] = NULL;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
    }
}

void WorkerManager::showMenu() {
    string title(38, '*');
    string head(9, '*');
    string menu(12, '*');
    cout << title << endl;
    string menuArray[] = {"退出管理系统", "增加职工信息", "显示职工信息", "删除离职职工", "修改职工信息", "查找职工信息", "按照编号排序", "清空所有职工"};
    cout << head << " 欢迎使用职工管理系统! " << head << endl;
    for (int i = 0; i < size(menuArray); i++) {
        cout << menu << " " << i << "." << menuArray[i] << " " << menu << endl;
    }
    cout << title << endl;
}

void WorkerManager::exitSystem() {
    cout << "欢迎下次使用!" << endl;
    exit(0);
}

void WorkerManager::addWorker() {
    cout << "输入添加职工数量" << endl;
    int addNum = 0;
    cin >> addNum;

    if (addNum > 0) {
        int newsize = this->m_empNum + addNum;

        Worker **newSpace = new Worker *[newsize];
        if (this->m_EmpArray != NULL) {
            for (int i = 0; i < this->m_empNum; i++) {
                newSpace[i] = this->m_EmpArray[i];
            }
        }
        for (int i = 0; i < addNum; i++) {
            int id;
            string name;
            int dSelect;

            cout << "请输入第" << i + 1 << "个员工编号:" << endl;
            cin >> id;
            while (this->isExist(id)!=-1){
                cout << "编号已经存在,重新输入" <<endl;
                cin.clear();
                cin.ignore();
                cin >>id;
            }
            cout << "请输入第" << i + 1 << "个员工姓名:" << endl;
            cin >> name;
            cout << "请选择第" << i + 1 << "个员工岗位:" << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(id, name, 1);
                    break;
                case 2:
                    worker = new Manager(id, name, 2);
                    break;
                case 3:
                    worker = new Boss(id, name, 3);
                    break;
                default:
                    break;
            }

            newSpace[this->m_empNum + i] = worker;
        }
        delete[] this->m_EmpArray;
        this->m_EmpArray = newSpace;
        this->m_empNum = newsize;
        this->m_FileIsEmpty = false;
        cout << "添加成功" << endl;
        this->save();
    } else {
        cout << "输入有误" << endl;
    }
};

void WorkerManager::save() {
    ofstream ofs;
    ofs.open(FILENAME, ios::out);
    for (int i = 0; i < this->m_empNum; i++) {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_Dept << endl;
    }
    ofs.close();
};

int WorkerManager::getEmpNum() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int id;
    string name;
    int did;
    int num = 0;

    while (ifs >> id && ifs >> name && ifs >> did) {
        num++;
    }
    ifs.close();
    return num;
};

void WorkerManager::initEmp() {
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int id;
    string name;
    int did;
    int idx = 0;
    while (ifs >> id && ifs >> name && ifs >> did) {
        Worker *worker = NULL;
        if (did == 1) {
            worker = new Employee(id, name, did);
        } else if (did == 2) {
            worker = new Manager(id, name, did);
        } else {
            worker = new Boss(id, name, did);
        }
        this->m_EmpArray[idx] = worker;
        idx++;
    }
    ifs.close();
};

void WorkerManager::showEmp() {
    //判断文件是否为空
    if (this->m_FileIsEmpty) {
        cout << "不存在或者为空" << endl;
    } else {
        for (int i = 0; i < this->m_empNum; i++) {
            this->m_EmpArray[i]->showInfo();
        }
    }
};

int WorkerManager::isExist(int id) {
    for (int i = 0; i < this->m_empNum; i++) {
        if (this->m_EmpArray[i]->m_Id == id) {
            return i;
        } else {
            return -1;
        }
    }
};

void WorkerManager::delEmp() {
    if (this->m_FileIsEmpty) {
        cout << "不存在或者为空" << endl;
    } else {
        int id = 0;
        cout << "输入要删除得id" << endl;
        cin >> id;
        int index = this->isExist(id);
        if (index != -1) {
            for (int i = index; i < this->m_empNum - 1; i++) {
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }
            this->m_empNum--;
            this->save();
            cout << "删除成功" << endl;
        } else {
            cout << "查无此人" << endl;
        }
    }
};

void WorkerManager::modEmp(){
    if (this->m_FileIsEmpty) {
        cout << "不存在或者为空" << endl;
    } else {
        cout << "输入修改职工编号" <<endl;
        int id;
        cin >>id;
        int index = this->isExist(id);
        if(index != -1){
            delete this->m_EmpArray[index];
            int newId=0;
            string newName="";
            int dSelect=0;

            cout << "请输入新员工编号:" << endl;
            cin >> newId;
            cout << "请输入新员工姓名:" << endl;
            cin >> newName;
            cout << "请选择新员工岗位:" << endl;
            cout << "1.普通员工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect) {
                case 1:
                    worker = new Employee(newId, newName, 1);
                    break;
                case 2:
                    worker = new Manager(newId, newName, 2);
                    break;
                case 3:
                    worker = new Boss(newId, newName, 3);
                    break;
                default:
                    break;
            }
            this->m_EmpArray[index] = worker;
            this->save();
            cout << "修改成功" <<endl;
        } else {
            cout << "查无此人" <<endl;
        }
    }
};

void WorkerManager::findEmp(){
    if (this->m_FileIsEmpty) {
        cout << "不存在或者为空" << endl;
    } else {
        cout << "请输入查找方式" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按职工姓名查找" << endl;
        int select =0;
        cin >>select;
        if (select == 1){
            int id =0;
            cout << "输入查找编号" <<endl;
            cin >> id;
            int ret = this->isExist(id);
            if(ret!=-1){
                cout << "查找成功" <<endl;
                this->m_EmpArray[ret]->showInfo();
            }else{
                cout << "查找失败" << endl;
            }
        } else if (select ==2){
            string name;
            bool flag = false;
            cout << "输入查找姓名" <<endl;
            cin >> name;
            for (int i=0;i<this->m_empNum;i++){
                if(this->m_EmpArray[i]->m_Name==name){
                    cout << "查找成功" <<endl;
                    flag = true;
                    this->m_EmpArray[i]->showInfo();
                }
            }
            if (!flag){
                cout << "查无此人" <<endl;
            }

        } else {
            cout << "无效查找方式" <<endl;
        }
    }
};

void WorkerManager::sortEmp(){
    if (this->m_FileIsEmpty) {
        cout << "不存在或者为空" << endl;
    } else {
        int select;
        cout << "选择排序方式：" << endl;
        cout << "1.升序" << endl;
        cout << "2.降序" << endl;
        cin >> select;
        if (select == 1){
        for(int i=1;i<this->m_empNum;i++){
            for(int j=0;j<this->m_empNum-i;j++){
                if(this->m_EmpArray[j]->m_Id>this->m_EmpArray[j+1]->m_Id){
                    Worker * tmp = this->m_EmpArray[j];
                    this->m_EmpArray[j] = this->m_EmpArray[j+1];
                    this->m_EmpArray[j+1] = tmp;
                }
            }
        }
    } else if (select == 2) {
            for(int i=1;i<this->m_empNum;i++){
                for(int j=0;j<this->m_empNum-i;j++){
                    if(this->m_EmpArray[j]->m_Id<this->m_EmpArray[j+1]->m_Id){
                        Worker * tmp = this->m_EmpArray[j];
                        this->m_EmpArray[j] = this->m_EmpArray[j+1];
                        this->m_EmpArray[j+1] = tmp;
                    }
                }
            }
        }
        this->showEmp();
    }
};

void WorkerManager::cleanFile(){
    cout << "确认清空?" <<endl;
    cout << "1.确认" <<endl;
    cout << "2.返回" <<endl;

    int select =0;
    cin >> select;
    if (select == 1){
        ofstream ofs;
        ofs.open(FILENAME,ios::trunc);
        ofs.close();
        if(this->m_EmpArray!=NULL){
            for(int i=0;i<this->m_empNum;i++){
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }
            delete[] this->m_EmpArray;
            this->m_EmpArray = NULL;
            this->m_empNum = 0;
            this->m_FileIsEmpty = true;
            cout << "清空成功" <<endl;
        } else {
            cout << "取消清空" <<endl;
        }
    }
};
