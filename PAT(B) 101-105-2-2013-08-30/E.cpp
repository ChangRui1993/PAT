/**
E. �²��� (25)
�δ�ʷѧ��˾����ڡ�����ͨ��������һ�������ġ��²��ۡ���
���ǹʲŵ�ȫ��ν֮ʥ�ˣ��ŵ¼���ν֮���ˣ���ʤ��ν֮���ӣ���ʤ��ν֮С�ˡ���ȡ��֮����������ʥ�ˣ����Ӷ���֮�������С�ˣ����������ˡ���

�ָ���һ�������ĵ²ŷ����������˾�������۸���¼ȡ������

�����ʽ��
�����1�и���3�����������ֱ�Ϊ��
N��<=105����������������
L��>=60����Ϊ¼ȡ��ͷ����ߣ����·ֺͲŷ־�������L�Ŀ��������ʸ񱻿���¼ȡ��
H��<100����Ϊ����¼ȡ�ߡ����·ֺͲŷ־������ڴ��ߵı�����Ϊ���ŵ�ȫ���������࿼�����²��ִܷӸߵ�������
�ŷֲ������·ֵ��ߵ�һ�࿼�����ڡ���ʤ�š���Ҳ���ܷ����򣬵����ڵ�һ�࿼��֮��
�²ŷ־�����H�����ǵ·ֲ����ڲŷֵĿ������ڡ��ŵ¼����������С���ʤ�š��ߣ����ܷ����򣬵����ڵڶ��࿼��֮��
�����ﵽ�����L�Ŀ���Ҳ���ܷ����򣬵����ڵ����࿼��֮��

���N�У�ÿ�и���һλ��������Ϣ��������׼��֤�š��·֡��ŷ֣�
����׼��֤��Ϊ8λ�������²ŷ�Ϊ����[0, 100]�ڵ�������
���ּ��Կո�ָ���

�����ʽ��
�����1�����ȸ����ﵽ��ͷ����ߵĿ�������M��
���M�У�ÿ�а��������ʽ���һλ��������Ϣ��������������˵���Ĺ���Ӹߵ�������
��ĳ�࿼�����ж����ܷ���ͬʱ������·ֽ������У�
���·�Ҳ���У���׼��֤�ŵ����������

����������
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

���������
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
        // ��������id����
        if(de+cai>s.de+s.cai)
            return true;
        else if(de+cai<s.de+s.cai)
            return false;
        else
        {
            // �ܷ���ͬ
            if(de>s.de)
                return true;
            else if(de<s.de)
                return false;
            else
            {
                // �ܷ���ͬ���·���ͬ
                return id<s.id;
            }
        }
    }
};

bool cmp(Student a, Student b)
{
    /** ��������id���� */
    /** ����a>b */
    if(a.de+a.cai<b.de+b.cai)
        return false;
    else if(a.de+a.cai>b.de+b.cai)
        return true;
    else
    {
        // �ܷ���ͬ
        if(a.de<b.de)
            return false;
        else if(a.de>b.de)
            return true;
        else
        {
            // �ܷ���ͬ���·���ͬ
            return a.id<b.id;
        }
    }
}

int main()
{

    //freopen("D:\input.txt", "r", stdin);

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



