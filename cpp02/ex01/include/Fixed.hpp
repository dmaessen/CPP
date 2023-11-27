#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int                 m_value;
        static const int    m_frac;

    public:
        Fixed(void); // default constructor
        Fixed(const Fixed &copy); // copy constructor
        Fixed& operator=(const Fixed &copy); // assignment
        Fixed(const int i); // int constructor
		Fixed(const float f); // float constructor
		~Fixed(void);
        
        int                 getRawBits( void ) const;
        void                setRawBits( int const raw );

		float				toFloat( void ) const;
		int					toInt( void ) const;

};

#endif