#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <iostream>
# include <sstream>
# include <climits>
# include <ctime>
# include <iomanip>
# include <cstdlib>

class PmergeMe
{
	private:

		std::vector<int>	vec;
		std::deque<int>		deq;

		void	parseInput(int argc, char **argv);
		void	displaySequence(std::string const& msg, std::vector<int> const& seq) const;
		void	displaySequence(std::string const& msg, std::deque<int> const& seq) const;
		
		void	mergeInsertSortVector(std::vector<int>& arr);
		void	mergeInsertSortDeque(std::deque<int>& arr);
		
		void	insertionSortVector(std::vector<int>& arr, int left, int right);
		void	mergeVector(std::vector<int>& arr, int left, int mid, int right);
		void	fordJohnsonMergeInsertVector(std::vector<int>& arr, int left, int right);
		
		void	insertionSortDeque(std::deque<int>& arr, int left, int right);
		void	mergeDeque(std::deque<int>& arr, int left, int mid, int right);
		void	fordJohnsonMergeInsertDeque(std::deque<int>& arr, int left, int right);
		
		double	getTimeInMicroseconds(clock_t start, clock_t end) const;

	public:

		PmergeMe();
		PmergeMe(PmergeMe const& that);
		~PmergeMe();
		PmergeMe& operator=(PmergeMe const& that);

		void	sortAndDisplay(int argc, char **argv);

};

#endif
