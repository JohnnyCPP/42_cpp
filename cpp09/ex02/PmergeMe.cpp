#include "PmergeMe.hpp"

bool	PmergeMe::isNumber(const std::string& str) const
{
	size_t	i;
	bool	hasDigit;

	i = 0;
	hasDigit = false;
	if (str.empty())
		return (false);
	if (str[i] == '+')
		++ i;
	while (i < str.length())
	{
		if (!std::isdigit(str[i]))
			return (false);
		hasDigit = true;
		++ i;
	}
	return (hasDigit);
}

bool	PmergeMe::hasDuplicates(const std::vector<int>& nums) const
{
	std::vector<int>	copy;
	size_t				i;

	copy = nums;
	i = 1;
	std::sort(copy.begin(), copy.end());
	while (i < copy.size())
	{
		if (copy[i] == copy[i - 1])
			return (true);
		++ i;
	}
	return (false);
}

std::vector<int>	PmergeMe::fordJohnson(std::vector<int>& nums)
{
	std::vector<int>::iterator	pos;
	std::vector<int>			larger;
	std::vector<int>			sorted;
	std::vector<int>			pend;
	std::vector<int>			pairsCopy;
	size_t						i;
	int							odd;
	bool						hasOdd;

	i = 0;
	odd = -1;
	hasOdd = false;
	if (nums.size() <= 1)
		return (nums);
	if (nums.size() % 2 != 0)
	{
		odd = nums.back();
		nums.pop_back();
		hasOdd = true;
	}
	larger = createPairs(nums);
	sorted = fordJohnson(larger);
	pairsCopy = nums;
	while (i < pairsCopy.size())
	{
		pend.push_back(pairsCopy[i + 1]);
		i += 2;
	}
	if (!pend.empty())
		mergeInsert(sorted, pend);
	if (hasOdd)
	{
		pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
		sorted.insert(pos, odd);
	}
	return (sorted);
}

std::vector<int>	PmergeMe::createPairs(std::vector<int>& nums)
{
	std::vector<int>	larger;
	size_t				i;
	int					a;
	int					b;

	i = 0;
	while (i + 1 < nums.size())
	{
		a = nums[i];
		b = nums[i + 1];
		if (a < b)
			std::swap(a, b);
		larger.push_back(a);
		nums[i] = a;
		nums[i + 1] = b;
		i += 2;
	}
	return (larger);
}

void	PmergeMe::mergeInsert(std::vector<int>& main, std::vector<int>& pend)
{
	std::vector<int>::iterator	pos;
	std::vector<int>			jacob;
	std::vector<int>			order;
	std::vector<bool>			inserted;
	size_t						i;
	size_t						j;
	int							idx;
	int							value;

	i = 2;
	j = 0;
	idx = 0;
	value = 0;
	if (pend.empty())
		return ;
	jacob = getVJacobsthalOf(pend.size());
	inserted.resize(pend.size(), false);
	while (i < jacob.size())
	{
		idx = jacob[i] - 1;
		if (idx >= static_cast<int>(pend.size()))
			idx = pend.size() - 1;
		if (idx >= 0 && !inserted[idx])
		{
			order.push_back(idx);
			inserted[idx] = true;
		}
		++ i;
	}
	i = 0;
	while (i < pend.size())
	{
		if (!inserted[i])
			order.push_back(i);
		++ i;
	}
	while (j < order.size())
	{
		value = pend[order[j]];
		pos = std::lower_bound(main.begin(), main.end(), value);
		main.insert(pos, value);
		++ j;
	}
}

std::vector<int>	PmergeMe::getVJacobsthalOf(int n)
{
	std::vector<int>	jacob;
	int					next;
	int					i;

	jacob.push_back(0);
	if (n < 2)
		return (jacob);
	jacob.push_back(1);
	i = 2;
	while (jacob.back() < n)
	{
		next = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next);
		++ i;
	}
	return (jacob);
}

std::deque<int>	PmergeMe::fordJohnson(std::deque<int>& nums)
{
	std::deque<int>::iterator	pos;
	std::deque<int>				larger;
	std::deque<int>				sorted;
	std::deque<int>				pend;
	std::deque<int>				pairsCopy;
	size_t						i;
	int							odd;
	bool						hasOdd;

	i = 0;
	odd = -1;
	hasOdd = false;
	if (nums.size() <= 1)
		return (nums);
	if (nums.size() % 2 != 0)
	{
		odd = nums.back();
		nums.pop_back();
		hasOdd = true;
	}
	larger = createPairs(nums);
	sorted = fordJohnson(larger);
	pairsCopy = nums;
	while (i < pairsCopy.size())
	{
		pend.push_back(pairsCopy[i + 1]);
		i += 2;
	}
	if (!pend.empty())
		mergeInsert(sorted, pend);
	if (hasOdd)
	{
		pos = std::lower_bound(sorted.begin(), sorted.end(), odd);
		sorted.insert(pos, odd);
	}
	return (sorted);
}

std::deque<int>	PmergeMe::createPairs(std::deque<int>& nums)
{
	std::deque<int>		larger;
	size_t				i;
	int					a;
	int					b;

	i = 0;
	while (i + 1 < nums.size())
	{
		a = nums[i];
		b = nums[i + 1];
		if (a < b)
			std::swap(a, b);
		larger.push_back(a);
		nums[i] = a;
		nums[i + 1] = b;
		i += 2;
	}
	return (larger);
}

void	PmergeMe::mergeInsert(std::deque<int>& main, std::deque<int>& pend)
{
	std::deque<int>::iterator	pos;
	std::deque<int>				jacob;
	std::deque<int>				order;
	std::deque<bool>			inserted;
	size_t						i;
	size_t						j;
	int							idx;
	int							value;

	i = 2;
	j = 0;
	idx = 0;
	value = 0;
	if (pend.empty())
		return ;
	jacob = getDJacobsthalOf(pend.size());
	inserted.resize(pend.size(), false);
	while (i < jacob.size())
	{
		idx = jacob[i] - 1;
		if (idx >= static_cast<int>(pend.size()))
			idx = pend.size() - 1;
		if (idx >= 0 && !inserted[idx])
		{
			order.push_back(idx);
			inserted[idx] = true;
		}
		++ i;
	}
	i = 0;
	while (i < pend.size())
	{
		if (!inserted[i])
			order.push_back(i);
		++ i;
	}
	while (j < order.size())
	{
		value = pend[order[j]];
		pos = std::lower_bound(main.begin(), main.end(), value);
		main.insert(pos, value);
		++ j;
	}
}

std::deque<int>	PmergeMe::getDJacobsthalOf(int n)
{
	std::deque<int>	jacob;
	int				next;
	int				i;

	jacob.push_back(0);
	if (n < 2)
		return (jacob);
	jacob.push_back(1);
	i = 2;
	while (jacob.back() < n)
	{
		next = jacob[i - 1] + 2 * jacob[i - 2];
		jacob.push_back(next);
		++ i;
	}
	return (jacob);
}

PmergeMe::PmergeMe(char **argv)
{
	std::string	arg;
	long		value;
	int			i;

	i = 1;
	while (argv[i] != NULL)
	{
		arg = argv[i];
		if (!isNumber(arg))
		{
			std::cerr << "Error: Invalid number format - " << arg << std::endl;
			std::exit(EXIT_FAILURE);
		}
		value = std::atol(arg.c_str());
		if (value > INT_MAX || value < 0)
		{
			std::cerr << "Error: Number out of range (0 to INT_MAX) - " << arg << std::endl;
			std::exit(EXIT_FAILURE);
		}
		vector.push_back(static_cast<int>(value));
		deque.push_back(static_cast<int>(value));
		++ i;
	}
	if (hasDuplicates(vector))
	{
		std::cerr << "Error: Duplicate values found" << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

PmergeMe::PmergeMe(const PmergeMe& that)
{
	*this = that;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& that)
{
	if (this != &that)
	{
		vector = that.vector;
		deque = that.deque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::sort()
{
	std::vector<int>	vecCopy;
	std::deque<int>		deqCopy;
	clock_t				vecStart;
	clock_t				vecEnd;
	clock_t				deqStart;
	clock_t				deqEnd;
	double				vecTime;
	double				deqTime;
	std::vector<int>	sortedVec;
	std::deque<int>		sortedDeq;
	size_t				i;

	i = 0;
	vecTime = 0.0;
	deqTime = 0.0;
	std::cout << "Before: ";
	while (i < vector.size())
	{
		std::cout << vector[i];
		if (i + 1 < vector.size())
			std::cout << " ";
		++ i;
	}
	std::cout << std::endl;
	vecCopy = vector;
	deqCopy = deque;
	vecStart = clock();
	sortedVec = fordJohnson(vecCopy);
	vecEnd = clock();
	vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000;
	deqStart = clock();
	sortedDeq = fordJohnson(deqCopy);
	deqEnd = clock();
	deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000;
	std::cout << "After: ";
	i = 0;
	while (i < sortedVec.size())
	{
		std::cout << sortedVec[i];
		if (i + 1 < sortedVec.size())
			std::cout << " ";
		++ i;
	}
	std::cout << std::endl;
	std::cout << "Time to process a range of " << vector.size()
		<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deque.size()
		<< " elements with std::deque  : " << deqTime << " us" << std::endl;
}
