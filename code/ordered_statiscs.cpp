
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

typedef tree<
double,
int,
less<double>,
rb_tree_tag,
tree_order_statistics_node_update> map_t;


typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update> ordered_set;



int main(){
    map_t a;
    a[0] = 1;
    a[2] = 1;
    a[5] = 1;
    cout << a.find_by_order(1)->first <<endl;
    cout << a.order_of_key(-5) << endl;
}

