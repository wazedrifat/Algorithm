#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef
tree<
  int,
  null_type,
  less<int>,
  rb_tree_tag,
  tree_order_statistics_node_update>
ordered_set;

int main()
{
    ordered_set X;
    X.insert(1);
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    X.erase(8); /// delete 8 from where 8 is located
    
	cout<<"0 : "<<*X.find_by_order(0)<<endl; /// 2 same as X[1]
    cout<<"1 : "<<*X.find_by_order(1)<<endl; /// 2 same as X[1]
    cout<<"2 : "<<*X.find_by_order(2)<<endl; // 4
    cout<<"3 : "<<*X.find_by_order(3)<<endl; // 16
    cout<<"4 : "<<*X.find_by_order(4)<<endl; // 0 as is empty
    cout<<"end@4 : "<<(X.end()==X.find_by_order(4))<<endl<<endl; // true

    cout<<"-5 : "<<X.order_of_key(-5)<<endl;   // 0 = lower bound
    cout<<"1 : "<<X.order_of_key(1)<<endl;    // 0
    
    cout<<"2 : "<<X.order_of_key(2)<<endl;    // 1
    
    cout<<"3 : "<<X.order_of_key(3)<<endl;    // 2
    cout<<"4 : "<<X.order_of_key(4)<<endl;   // 2
    
    cout<<"5 : "<<X.order_of_key(5)<<endl;   // 3
    cout<<"6 : "<<X.order_of_key(6)<<endl;   // 3
    cout<<"7 : "<<X.order_of_key(7)<<endl;   // 3
    cout<<"8 : "<<X.order_of_key(8)<<endl;   // 3
    
    cout<<"9 : "<<X.order_of_key(9)<<endl;   // 3
    cout<<"400 : "<<X.order_of_key(400)<<endl; // 4
}
