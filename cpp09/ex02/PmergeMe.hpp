#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <sstream>
# include <algorithm>
# include <cstdlib>
# include <climits>

class PmergeMe
{
private:

	std::vector<int>	vector;
	std::deque<int>		deque;

	PmergeMe();

	bool				isNumber(const std::string& str) const;
	bool				hasDuplicates(const std::vector<int>& nums) const;

	std::vector<int>	fordJohnson(std::vector<int>& nums);
	std::vector<int>	createPairs(std::vector<int>& nums);
	void				mergeInsert(std::vector<int>& main, std::vector<int>& pend);
	std::vector<int>	getVJacobsthalOf(int n);

	std::deque<int>		fordJohnson(std::deque<int>& nums);
	std::deque<int>		createPairs(std::deque<int>& nums);
	void				mergeInsert(std::deque<int>& main, std::deque<int>& pend);
	std::deque<int>		getDJacobsthalOf(int n);

public:

	PmergeMe(char **argv);
	PmergeMe(const PmergeMe& that);
	PmergeMe& operator=(const PmergeMe& that);
	~PmergeMe();

	void	sort();
};

#endif
