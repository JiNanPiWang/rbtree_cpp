#include "rbtree.h"
#include <bits/stdc++.h>

const int max_len = 1e6;
int data[max_len + 10];

int main(int argc, char* argv[])
{
	rb_tree<long long> tree;
//	std::cout << "test_rb_tree: insert" << std::endl;
	for (auto i = 0; i < max_len; ++i)
	{
        data[i] = i + 1;
		auto debug = data[i];
		tree.insert(debug);
	}

//	std::cout << "test_rb_tree: dump" << std::endl;
//	tree.dump();
//	std::cout << "test_rb_tree: height" << std::endl;
//	std::cout << "height: " << tree.height() << std::endl;

	for (auto i = 0; i < max_len; ++i)
	{
		auto debug = data[i];
		tree.erase(debug);
//		std::cout << "test_rb_tree: height: " << tree.height() << " erase: " << debug << std::endl;
//		std::cout << "test_rb_tree: dump" << std::endl;
//		tree.check_rb_feature_5();
//		tree.dump();
	}

	return 0;
}




