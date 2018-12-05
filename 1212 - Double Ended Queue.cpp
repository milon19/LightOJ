#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>

using namespace std;

int main()
{
    int t, cs = 1;
    cin >> t;

    while(t--)
    {
        int sz, op;
        cin >> sz >> op;

        list <int> li;
        list <int> :: iterator it, aa;
        cout << "Case " << cs++ << ":" << endl;
        for(int i = 1; i <= op; i++)
        {
            int val;
            string opname;
            cin >> opname;

            if(opname == "pushRight")
            {
                cin >> val;

                if(li.size() == sz)
                    cout << "The queue is full" << endl;
                else
                {
                    li.push_back(val);
                    cout << "Pushed in right: " << val << endl;
                }
            }

            else if(opname == "pushLeft")
            {
                cin >> val;

                if(li.size() == sz)
                    cout << "The queue is full" << endl;
                else
                {
                    li.push_front(val);
                    cout << "Pushed in left: " << val << endl;
                }
            }

            else if(opname == "popRight")
            {
                if(li.empty())
                    cout << "The queue is empty" << endl;
                else
                {

                    cout << "Popped from right: " << li.back() << endl;
                    li.pop_back();
                }
            }

            else if(opname == "popLeft")
            {
                if(li.empty())
                    cout << "The queue is empty" << endl;
                else
                {
                    cout << "Popped from left: " << li.front() << endl;
                    li.pop_front();
                }
            }
        }
        li.clear();

    }

    return 0;
}
