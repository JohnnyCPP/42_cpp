#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const& that)
{
	*this = that;
}

PmergeMe::~PmergeMe()
{
}

PmergeMe& PmergeMe::operator=(PmergeMe const& that)
{
	if (this != &that)
	{
		this->vec = that.vec;
		this->deq = that.deq;
	}
	return (*this);
}

void	PmergeMe::parseInput(int argc, char **argv)
{
	int		i;
	long	num;
	
	i = 1;
	while (i < argc)
	{
		std::stringstream	ss(argv[i]);
		ss >> num;
		if (ss.fail() || !ss.eof())
		{
			std::cerr << "Error: invalid input" << std::endl;
			std::exit(1);
		}
		if (num <= 0 || num > INT_MAX)
		{
			std::cerr << "Error: invalid positive integer" << std::endl;
			std::exit(1);
		}
		this->vec.push_back(static_cast<int>(num));
		this->deq.push_back(static_cast<int>(num));
		i ++;
	}
}

void	PmergeMe::insertionSortVector(std::vector<int>& arr, int left, int right)
{
	int	i;
	int	j;
	int	key;
	
	i = left + 1;
	while (i <= right)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j --;
		}
		arr[j + 1] = key;
		i ++;
	}
}

void	PmergeMe::mergeVector(std::vector<int>& arr, int left, int mid, int right)
{
	std::vector<int>	leftArr(arr.begin() + left, arr.begin() + mid + 1);
	std::vector<int>	rightArr(arr.begin() + mid + 1, arr.begin() + right + 1);
	size_t	i;
	size_t	j;
	size_t	k;
	
	i = 0;
	j = 0;
	k = left;
	while (i < leftArr.size() && j < rightArr.size())
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i ++;
		}
		else
		{
			arr[k] = rightArr[j];
			j ++;
		}
		k ++;
	}
	while (i < leftArr.size())
	{
		arr[k] = leftArr[i];
		i ++;
		k ++;
	}
	while (j < rightArr.size())
	{
		arr[k] = rightArr[j];
		j ++;
		k ++;
	}
}

void	PmergeMe::fordJohnsonMergeInsertVector(std::vector<int>& arr, int left, int right)
{
	int	size;
	
	size = right - left + 1;
	
	if (size <= 10)
	{
		this->insertionSortVector(arr, left, right);
		return ;
	}
	int	mid = left + (right - left) / 2;
	this->fordJohnsonMergeInsertVector(arr, left, mid);
	this->fordJohnsonMergeInsertVector(arr, mid + 1, right);
	this->mergeVector(arr, left, mid, right);
}

void	PmergeMe::mergeInsertSortVector(std::vector<int>& arr)
{
	if (arr.size() <= 1)
		return;
	this->fordJohnsonMergeInsertVector(arr, 0, arr.size() - 1);
}

void	PmergeMe::insertionSortDeque(std::deque<int>& arr, int left, int right)
{
	int	i;
	int	j;
	int	key;
	
	i = left + 1;
	while (i <= right)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j --;
		}
		arr[j + 1] = key;
		i ++;
	}
}

void	PmergeMe::mergeDeque(std::deque<int>& arr, int left, int mid, int right)
{
	std::deque<int>	leftArr;
	std::deque<int>	rightArr;
	size_t			i;
	size_t			j;
	size_t			k;
	
	i = left;
	while (i <= static_cast<size_t>(mid))
	{
		leftArr.push_back(arr[i]);
		i ++;
	}
	i = mid + 1;
	while (i <= static_cast<size_t>(right))
	{
		rightArr.push_back(arr[i]);
		i ++;
	}
	i = 0;
	j = 0;
	k = left;
	while (i < leftArr.size() && j < rightArr.size())
	{
		if (leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i ++;
		}
		else
		{
			arr[k] = rightArr[j];
			j ++;
		}
		k ++;
	}
	while (i < leftArr.size())
	{
		arr[k] = leftArr[i];
		i ++;
		k ++;
	}
	while (j < rightArr.size())
	{
		arr[k] = rightArr[j];
		j ++;
		k ++;
	}
}

void	PmergeMe::fordJohnsonMergeInsertDeque(std::deque<int>& arr, int left, int right)
{
	int	size;
	
	size = right - left + 1;
	if (size <= 10)
	{
		this->insertionSortDeque(arr, left, right);
		return ;
	}
	int	mid = left + (right - left) / 2;
	this->fordJohnsonMergeInsertDeque(arr, left, mid);
	this->fordJohnsonMergeInsertDeque(arr, mid + 1, right);
	this->mergeDeque(arr, left, mid, right);
}

void	PmergeMe::mergeInsertSortDeque(std::deque<int>& arr)
{
	if (arr.size() <= 1)
		return ;
	this->fordJohnsonMergeInsertDeque(arr, 0, arr.size() - 1);
}

void	PmergeMe::displaySequence(std::string const& msg, std::vector<int> const& seq) const
{
	size_t	i;
	
	std::cout << msg;
	i = 0;
	while (i < seq.size())
	{
		std::cout << seq[i];
		if (i + 1 < seq.size())
			std::cout << " ";
		i ++;
	}
	std::cout << std::endl;
}

void	PmergeMe::displaySequence(std::string const& msg, std::deque<int> const& seq) const
{
	size_t	i;
	
	std::cout << msg;
	i = 0;
	while (i < seq.size())
	{
		std::cout << seq[i];
		if (i + 1 < seq.size())
			std::cout << " ";
		i ++;
	}
	std::cout << std::endl;
}

double	PmergeMe::getTimeInMicroseconds(clock_t start, clock_t end) const
{
	return (static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000.0);
}

void	PmergeMe::sortAndDisplay(int argc, char **argv)
{
	clock_t	startVec;
	clock_t	endVec;
	clock_t	startDeq;
	clock_t	endDeq;
	
	this->parseInput(argc, argv);
	this->displaySequence("Before: ", this->vec);
	startVec = clock();
	this->mergeInsertSortVector(this->vec);
	endVec = clock();
	startDeq = clock();
	this->mergeInsertSortDeque(this->deq);
	endDeq = clock();
	this->displaySequence("After: ", this->vec);
	double	timeVec = this->getTimeInMicroseconds(startVec, endVec);
	double	timeDeq = this->getTimeInMicroseconds(startDeq, endDeq);
	std::cout << "Time to process a range of " << this->vec.size() 
	          << " elements with std::vector : " << std::fixed 
	          << std::setprecision(5) << timeVec << " us" << std::endl;
	
	std::cout << "Time to process a range of " << this->deq.size() 
	          << " elements with std::deque : " << std::fixed 
	          << std::setprecision(5) << timeDeq << " us" << std::endl;
}
