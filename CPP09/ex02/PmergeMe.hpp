#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deque;

		void	sortVector();
		void	mergeInsertVector(std::vector<int>& v);
		void	sortDeque();
		void	mergeInsertDeque(std::deque<int>& d);

		static int	parseInt(const std::string& token);
		static void	printSequence(const std::string& label,
						const std::vector<int>& v);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe();

		void	parseArguments(int argc, char** argv);
		void	run();
};

#endif
