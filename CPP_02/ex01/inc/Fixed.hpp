#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed(const int num);
		Fixed(const float num);
		Fixed &operator=(const Fixed &obj);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;
	private:
		int					_fixed_point;
		static const int	_fractional_bits = 8;
};

std::ostream &operator<<(std::ostream &stream, const Fixed &obj);

#endif
