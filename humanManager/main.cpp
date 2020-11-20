#include "workerManager.h"
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

int main() {
//    Worker * worker = NULL;
//    worker = new Employee(1,"奈特",1);
//    worker->showInfo();
//    delete worker;
//
//    worker = new Manager(2,"龙龙",2);
//    worker->showInfo();
//    delete worker;
//
//    worker = new Boss(3,"美满",3);
//    worker->showInfo();
//    delete worker;

    WorkerManager wm;
    int select=0;
    while(true) {
        wm.showMenu();
        cout << "请输入选择:" <<endl;
        cin >> select;
        if(cin.good() == 0){
            cout << "输入类型错误" <<endl;
            cin.clear();
            cin.ignore();
            continue;
        };
        switch (select){
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.addWorker();
                break;
            case 2:
                wm.showEmp();
                break;
            case 3:
                wm.delEmp();
                break;
            case 4:
                wm.modEmp();
                break;
            case 5:
                wm.findEmp();
                break;
            case 6:
                wm.sortEmp();
                break;
            case 7:
                wm.cleanFile();
                break;
            default:
                cout << "无效输入!" <<endl;
                break;
        }
}}