#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_mapped_type, less<int>, rb_tree_tag,
		 tree_order_statistics_node_update> set_t;
int main() {
	set_t s;
	s.insert(12);
	s.insert(505);
	s.insert(30);
	s.insert(1000);
	s.insert(10000);
	s.insert(100);
	assert(*s.find_by_order(0) == 12);
	assert(*s.find_by_order(1) == 30);
	assert(*s.find_by_order(2) == 100);
	assert(*s.find_by_order(3) == 505);
	assert(*s.find_by_order(4) == 1000);
	assert(*s.find_by_order(5) == 10000);
	assert(s.find_by_order(6) == s.end());
	assert(s.order_of_key(10) == 0);
	assert(s.order_of_key(12) == 0);
	assert(s.order_of_key(15) == 1);
	assert(s.order_of_key(30) == 1);
	assert(s.order_of_key(99) == 2);
	assert(s.order_of_key(100) == 2);
	assert(s.order_of_key(505) == 3);
	assert(s.order_of_key(1000) == 4);
	assert(s.order_of_key(10000) == 5);
	assert(s.order_of_key(9999999) == 6);
	s.erase(30);
	assert(*s.find_by_order(0) == 12);
	assert(*s.find_by_order(1) == 100);
	assert(*s.find_by_order(2) == 505);
	assert(*s.find_by_order(3) == 1000);
	assert(*s.find_by_order(4) == 10000);
	assert(s.find_by_order(5) == s.end());
	assert(s.order_of_key(10) == 0);
	assert(s.order_of_key(12) == 0);
	assert(s.order_of_key(100) == 1);
	assert(s.order_of_key(505) == 2);
	assert(s.order_of_key(707) == 3);
	assert(s.order_of_key(1000) == 3);
	assert(s.order_of_key(1001) == 4);
	assert(s.order_of_key(10000) == 4);
	assert(s.order_of_key(100000) == 5);
	assert(s.order_of_key(9999999) == 5);	
	exit(EXIT_SUCCESS);
}
 
