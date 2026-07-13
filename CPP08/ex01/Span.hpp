#include <iterator>
#include <stdexcept>
#include <vector>
class Span
{
	private:
		unsigned int _N;
		std::vector<int> _values;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();
		template <typename T>
		void addGroup(T begin, T end)
		{
			unsigned int distance = std::distance(begin, end);
			if (_values.size() + distance > _N)
			{
				throw std::runtime_error("Cannot add range: would exceed capacity");
			}
			_values.insert(_values.end(), begin, end);
		}
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		int spanSize();
};
