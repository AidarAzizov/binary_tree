
#ifndef BINARY_TREE_HPP
# define BINARY_TREE_HPP

template <typename T>
class binary_tree
{
	struct	s_str
	{
		T 				val;
		struct s_str	*left;
		struct s_str	*right;
	};
	s_str	*installer(T val)
	{
		s_str *temp = new s_str;
		temp->val = val;
		temp->right = nullptr;
		temp->left = nullptr;
		return (temp);
	}
	void	push_1(T val, s_str *temp);
	void	print_1(const s_str *temp);
	int		size_tree;
	s_str	*str;

	void	clean_all(s_str *temp);
	bool	find_1(T val, s_str *left, s_str *right);

public:
	binary_tree() {
		str = nullptr;
		size_tree = 0;
	}
	~binary_tree() {
		clean_all(this->str);
		delete this->str;
	}

	void	push(T val);
	bool	find(T val) { return (find_1(val, str->left, str->right) || str->val == val); }
	int		size() { return size_tree; }
	void	print() { print_1(str); }
};

template <typename T>
bool binary_tree<T>::find_1(T val, s_str *left, s_str *right)
{
	if ((left && left->val == val) || (right && right->val == val))
		return (true);
	if (!left)
	{
		if (!right)
			return false;
		return (find_1(val, right->left, right->right));
	}
	if (!right)
		return (find_1(val, left->left, left->right));
	return (find_1(val, left->left, left->right) || find_1(val, right->left, right->right));
}

template <typename T>
void binary_tree<T>::push_1(T val, s_str *temp)
{
	if (val == temp->val)
		return ;
	if (val < temp->val)
	{
		if (temp->left)
			push_1(val, temp->left);
		else
			temp->left = installer(val);
	}
	else if (val > temp->val)
	{
		if (temp->right)
			push_1(val, temp->right);
		else
			temp->right = installer(val);
	}
}

template <typename T>
void binary_tree<T>::print_1(const s_str *temp)
{
	if (!temp)
		return ;
	if (temp->left)
		print_1(temp->left);
	if (temp->right)
	{
		std::cout << temp->val << std::endl;
		print_1(temp->right);
	}
	else
		std::cout << temp->val << std::endl;
}

template <typename T>
void binary_tree<T>::push(T val)
{
	size_tree++;
	if (!str)
	{
		str = new s_str;
		str->right = nullptr;
		str->left = nullptr;
		str->val = val;
	}
	else
		push_1(val, this->str);
}

template <typename T>
void binary_tree<T>::clean_all(s_str *temp)
{
	if (!temp)
		return ;
	if (temp->left)
	{
		clean_all(temp->left);
		delete temp->left;
	}
	if (temp->right)
	{
		clean_all(temp->right);
		delete temp->right;
	}
}

#endif