/**
E. 德才论 (25)
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：
“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：
输入第1行给出3个正整数，分别为：
N（<=105），即考生总数；
L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；
H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；
才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；
德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；
其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，
其中准考证号为8位整数，德才分为区间[0, 100]内的整数。
数字间以空格分隔。

输出格式：
输出第1行首先给出达到最低分数线的考生人数M，
随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。
当某类考生中有多人总分相同时，按其德分降序排列；
若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60

输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90

*/

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <cstdio>
#include <algorithm>

using namespace std;

class Student
{

public:
    int id;
    int de;
    int cai;

    Student(int _id, int _de, int _cai)
    {
        id = _id;
        de = _de;
        cai = _cai;
    }

    bool operator < (const Student &s) const
    {
        // 分数降序，id升序
        if(de+cai>s.de+s.cai)
            return true;
        else if(de+cai<s.de+s.cai)
            return false;
        else
        {
            // 总分相同
            if(de>s.de)
                return true;
            else if(de<s.de)
                return false;
            else
            {
                // 总分相同，德分相同
                return id<s.id;
            }
        }
    }
};

bool cmp(Student a, Student b)
{
    /** 分数降序，id升序 */
    /** 定义a>b */
    if(a.de+a.cai<b.de+b.cai)
        return false;
    else if(a.de+a.cai>b.de+b.cai)
        return true;
    else
    {
        // 总分相同
        if(a.de<b.de)
            return false;
        else if(a.de>b.de)
            return true;
        else
        {
            // 总分相同，德分相同
            return a.id<b.id;
        }
    }
}

int main()
{

    freopen("D:\input.txt", "r", stdin);

    int n,l,h;

    while(cin>>n>>l>>h)
    {

        vector<Student> student_list;
        vector<Student> class_a;
        vector<Student> class_b;
        vector<Student> class_c;
        vector<Student> class_d;
        vector<Student>::iterator it;

        int id, de, cai;

        for(int i=0; i<n; i++)
        {
            cin>>id>>de>>cai;
            student_list.push_back(Student(id,de,cai));
        }

        for(it=student_list.begin(); it!=student_list.end(); ++it)
        {
            Student s = (*it);

            if(s.de>=h && s.cai>=h)
            {
                class_a.push_back(s);
            }
            else if(s.de>=h && s.cai>=l)
            {
                class_b.push_back(s);
            }
            else if(s.de>=l && s.cai>=l && s.de>=s.cai)
            {
                class_c.push_back(s);
            }
            else if(s.de>=l && s.cai>=l)
            {
                class_d.push_back(s);
            }
        }

//        sort(class_a.begin(),class_a.end(),cmp);
//        sort(class_b.begin(),class_b.end(),cmp);
//        sort(class_c.begin(),class_c.end(),cmp);
//        sort(class_d.begin(),class_d.end(),cmp);

        sort(class_a.begin(),class_a.end());
        sort(class_b.begin(),class_b.end());
        sort(class_c.begin(),class_c.end());
        sort(class_d.begin(),class_d.end());


        cout << class_a.size()+ class_b.size() + class_c.size() + class_d.size() << endl;

        for(it=class_a.begin(); it!=class_a.end(); ++it)
        {
            cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
        }
        for(it=class_b.begin(); it!=class_b.end(); ++it)
        {
            cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
        }
        for(it=class_c.begin(); it!=class_c.end(); ++it)
        {
            cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
        }

        for(it=class_d.begin(); it!=class_d.end(); ++it)
        {
            cout << (*it).id << " " << (*it).de << " " << (*it).cai << endl;
        }

    }

    return 0;
}



