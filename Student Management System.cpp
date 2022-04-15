#include <iostream>
#include <string.h>
#include <sstream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define NO 1
#define TOTAL 2
#define AVG 3
#define MATH 4
#define ENGLISH 5
#define COMPUTE 6

class Student //学生类 
 {
private:
    long long no;
    string name;
    string classes;
    float math;
    float english;
    float compute;
    float total;
    float avg;
public:
    static vector<Student*> student_list;
    
    Student(long long no, string name, string classes, float math, float english, float compute) {
        this->no = no;
        this->name = name;
        this->classes = classes;
        this->math = math;
        this->english = english;
        this->compute = compute;
        this->total = this->math + this->english + this->compute;
        this->avg = this->total / 3;
    }
    
    void print_msg() {
        ostringstream msg;
        msg << "          学号: " << this->no << endl;
        msg << "          姓名: " << this->name << endl;
        msg << "          班级: " << this->classes << endl;
        msg << "          数学成绩: " << this->math << endl;
        msg << "          外语成绩: " << this->english << endl;
        msg << "          计算机成绩: " << this->compute << endl;
        msg << "          总成绩: " << this->total << endl;
        msg << "          平均成绩: " << setiosflags(ios::fixed)<<setprecision(2) << this->avg << endl;
        cout << msg.str() << endl;
    }
    
    long long get_no() {
        return this->no;
    }
    
    float get_total() {
        return this->total;
    }
    
    float get_avg() {
        return this->avg;
    }
    
    float get_math() {
        return this->math;
    }
    
    float get_english() {
        return this->english;
    }
    
    float get_compute() {
        return this->compute;
    }
    
    void set_total_avg() {
        this->total = this->math + this->english + this->compute;
        this->avg = this->total / 3;
    }
    
    void set_no(long long no) {
        this->no = no;
    }
    
    void set_name(string name) {
        this->name = name;
    }
    
    void set_classes(string classes) {
        this->classes = classes;
    }
    
    void set_math(float math) {
        this->math = math;
        this->set_total_avg();
    }
    
    void set_english(float english) {
        this->english = english;
        this->set_total_avg();
    }
    
    void set_compute(float compute) {
        this->compute = compute;
        this->set_total_avg();
    }
    
    //修改信息 
	void do_modify() {
        long long no;
        string name;
        string classes;
        float math;
        float english;
        float compute;
        cout << "          请输入学号: ";
        cin >> no;
        while (check_no_exist(no)) {
            cout << "          该学号已存在，请重新输入: " ;
            cin >> no;
        }
        cout << "          请输入姓名: " ;
        cin >> name;
        cout << "          请输入班级: ";
        cin >> classes;
        cout << "          请输入数学成绩: ";
        cin >> math;
        cout << "          请输入外语成绩: ";
        cin >> english;
        cout << "          请输入计算机成绩: ";
        cin >> compute;
        this->set_no(no);
        this->set_name(name);
        this->set_classes(classes);
        this->set_math(math);
        this->set_english(english);
        this->set_compute(compute);
        cout << "          修改学生信息成功！" << endl << endl;
    }
    
    static bool check_no_exist(long long no) {
        for (int i = 0; i < student_list.size(); i++) {
            if (no == student_list[i]->get_no()) {
                return true;
            }
        }
        return false;
    }
    
    //录入信息 
	static void init_student() {
        string command = "y";
        while (command != "n") {
            if (command == "y"){
                add_student();
                cout << "          是否继续录入？(y/n):";
            }
            else {
                cout << "          输入不合法，是否继续录入？(y/n):";
            }
            cin >> command;
        }
    }
    
    //添加信息 
	static void add_student() {
        long long no;
        string name;
        string classes;
        float math;
        float english;
        float compute;
        cout << "          请输入学号: ";
        cin >> no;
        while (check_no_exist(no)) {
            cout << "          该学号已存在，请重新输入: " ;
            cin >> no;
        }
        cout << "          请输入姓名: " ;
        cin >> name;
        cout << "          请输入班级: ";
        cin >> classes;
        cout << "          请输入数学成绩: ";
        cin >> math;
        cout << "          请输入外语成绩: ";
        cin >> english;
        cout << "          请输入计算机成绩: ";
        cin >> compute;
        Student* student = new Student(no, name, classes, math, english, compute);
        student_list.push_back(student);
        cout << "          添加学生信息成功！" << endl << endl;
    }
    
    static void print_all() {
        if (student_list.size() == 0) {
            cout << "          暂无任何学生信息" << endl;
        }
        else {
            for (int i = 0; i < student_list.size(); i++) {
                student_list[i]->print_msg();
            }
        }
        cout << "          按任意键继续..." << endl;
        cin.ignore();
        cin.get();
    }
   
    //查询信息 
    static void query() {
        cout << "          请输入要查询的学生学号: ";
        long long no;
        cin >> no;
        bool exist = false;
        for (int i = 0; i < student_list.size(); i++) {
            if (student_list[i]->get_no() == no) {
                student_list[i]->print_msg();
                exist = true;
                break;
            }
        }
        if (!exist) {
            cout << "           该学号不存在！" << endl;
        }
        cout << "          按任意键继续..." << endl;
        cin.ignore();
        cin.get();
    }
    
    //修改信息 
    static void modify() {
        cout << "          请输入要修改的学生学号: ";
        long long no;
        cin >> no;
        bool exist = false;
        for (int i = 0; i < student_list.size(); i++) {
            if (student_list[i]->get_no() == no) {
                student_list[i]->do_modify();
                exist = true;
                break;
            }
        }
        if (!exist) {
            cout << "           该学号不存在！" << endl;
        }
    }
    
    //用户界面 
    static void sort_menu() {
        cout << "          ******************欢迎使用******************" << endl;
        cout << "          ***************学生成绩管理系统***************" << endl;
        cout << "          ****************请选择排序方式***************" << endl;
        cout << "          *-----------------------------------------*" << endl;
        cout << "          *            1 --按学号顺序                 *" << endl;
        cout << "          *            2 --按学号倒序                 *" << endl;
        cout << "          *            3 --按总成绩顺序                *" << endl;
        cout << "          *            4 --按总成绩倒序                *" << endl;
        cout << "          *            5 --按平均成绩顺序              *" << endl;
        cout << "          *            6 --按平均成绩倒序              *" << endl;
        cout << "          *            7 --按数学成绩顺序              *" << endl;
        cout << "          *            8 --按数学成绩倒序              *" << endl;
        cout << "          *            9 --按外语成绩顺序              *" << endl;
        cout << "          *            10--按外语成绩倒序              *" << endl;
        cout << "          *            11--按计算机成绩顺序            *" << endl;
        cout << "          *            12--按计算机成绩倒序            *" << endl;
        cout << "          *            0 --退出                      *" << endl;
        cout << "          *-----------------------------------------*" << endl;
        
        cout << "          请输入您要使用的功能序号(0 ~ 12): ";
    }
    
    static void do_sort(int type) {
        if (student_list.size() >= 2) {
            for (int i = 0; i < student_list.size() - 1; i++) {
                int min = i;
                for (int j = i + 1; j < student_list.size(); j++) {
                    switch (type) {
                        case NO:
                            if (student_list[min]->get_no() > student_list[j]->get_no())
                                min = j;
                            break;
                        case TOTAL:
                            if (student_list[min]->get_total() > student_list[j]->get_total())
                                min = j;
                            break;
                        case AVG:
                            if (student_list[min]->get_avg() > student_list[j]->get_avg())
                                min = j;
                            break;
                        case MATH:
                            if (student_list[min]->get_math() > student_list[j]->get_math())
                                min = j;
                            break;
                        case ENGLISH:
                            if (student_list[min]->get_english() > student_list[j]->get_english())
                                min = j;
                            break;
                        case COMPUTE:
                            if (student_list[min]->get_compute() > student_list[j]->get_compute())
                                min = j;
                            break;
                        default:
                            break;
                    }
                }
                if (min != i) {
                    Student* temp = student_list[i];
                    student_list[i] = student_list[min];
                    student_list[min] = temp;
                }
            }
        }
    }
    
    static void do_reverse_sort(int type) {
        do_sort(type);
        reverse(student_list.begin(), student_list.end());
    }
    
    static void sort() {
        int select = -1;
        while (select != 0) {
            sort_menu();
            cin >> select;
            switch (select) {
                case 0:
                    break;
                case 1:
                    do_sort(NO);
                    print_all();
                    break;
                case 2:
                    do_reverse_sort(NO);
                    print_all();
                    break;
                case 3:
                    do_sort(TOTAL);
                    print_all();
                    break;
                case 4:
                    do_reverse_sort(TOTAL);
                    print_all();
                    break;
                case 5:
                    do_sort(AVG);
                    print_all();
                    break;
                case 6:
                    do_reverse_sort(AVG);
                    print_all();
                    break;
                case 7:
                    do_sort(MATH);
                    print_all();
                    break;
                case 8:
                    do_reverse_sort(MATH);
                    print_all();
                    break;
                case 9:
                    do_sort(ENGLISH);
                    print_all();
                    break;
                case 10:
                    do_reverse_sort(ENGLISH);
                    print_all();
                    break;
                case 11:
                    do_sort(COMPUTE);
                    print_all();
                    break;
                case 12:
                    do_reverse_sort(COMPUTE);
                    print_all();
                    break;
                default:
                    break;
            }
        }
    }
    
    //删除信息 
    static void delete_student() {
        cout << "          请输入要删除的学生学号: ";
        long long no;
        cin >> no;
        bool exist = false;
        vector<Student *>::iterator it = student_list.begin();
        while (it != student_list.end()) {
            if ((*it)->get_no() == no) {
                student_list.erase(it);
                exist = true;
                break;
            }
            it++;
        }
        if (!exist) {
            cout << "          该学号不存在！" << endl;
        }
        else {
            cout << "          删除成功！" << endl;
        }
        cout << "          按任意键继续..." << endl;
        cin.ignore();
        cin.get();
    }
    
    //用户界面 
    static void print_menu() {
        cout << "          ******************欢迎使用******************" << endl;
        cout << "          ***************学生成绩管理系统***************" << endl;
        cout << "          *-----------------------------------------*" << endl;
        cout << "          *           1--录入学生信息                 *" << endl;
        cout << "          *           2--显示学生信息                 *" << endl;
        cout << "          *           3--查询学生信息                 *" << endl;
        cout << "          *           4--修改学生信息                 *" << endl;
        cout << "          *           5--添加学生信息                 *" << endl;
        cout << "          *           6--排序学生信息                 *" << endl;
        cout << "          *           7--删除学生信息                 *" << endl;
        cout << "          *           0--退出                        *" << endl;
        cout << "          *-----------------------------------------*" << endl;
        
        cout << "          请输入您要使用的功能序号(0 ~ 7): ";
    }
    
    static void menu() {
        int select = -1;
        while (select != 0) {
            print_menu();
            cin >> select;
            switch (select) {
                case 0:
                    break;
                case 1:
                    init_student();
                    break;
                case 2:
                    print_all();
                    break;
                case 3:
                    query();
                    break;
                case 4:
                    modify();
                    break;
                case 5:
                    add_student();
                    break;
                case 6:
                    sort();
                    break;
                case 7:
                    delete_student();
                    break;
                default:
                    break;
            }
        }
        
    }
};

vector<Student*> Student::student_list;

int main() {
    Student::menu();
    return 0;
}
