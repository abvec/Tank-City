
#ifndef _VECTOR_HPP_

    #define _VECTOR_HPP_
    
    #include <ostream>

    namespace src {

        /* A two dimentional vector. */
        class Vector2D {

            public :

            /* Constructors */
            constexpr Vector2D ( );
            constexpr Vector2D ( float const & a );
            constexpr Vector2D ( float const & a, float const & b );
            constexpr Vector2D ( Vector2D const & ab );
            constexpr Vector2D ( Vector2D const & a, float const & b );
            constexpr Vector2D ( float const & a, Vector2D const & b );

            /* Compare with floating point number */
            constexpr bool operator >  ( float const & ab ) const;
            constexpr bool operator <  ( float const & ab ) const;
            constexpr bool operator >= ( float const & ab ) const;
            constexpr bool operator <= ( float const & ab ) const;
            constexpr bool operator != ( float const & ab ) const;
            constexpr bool operator == ( float const & ab ) const;

            /* Compare with other vector */
            constexpr bool operator >  ( Vector2D const & ab ) const;
            constexpr bool operator <  ( Vector2D const & ab ) const;
            constexpr bool operator >= ( Vector2D const & ab ) const;
            constexpr bool operator <= ( Vector2D const & ab ) const;
            constexpr bool operator != ( Vector2D const & ab ) const;
            constexpr bool operator == ( Vector2D const & ab ) const;

            /* Arithmetic operation with floating point number */
            constexpr Vector2D operator + ( float const & ab ) const;
            constexpr Vector2D operator - ( float const & ab ) const;
            constexpr Vector2D operator * ( float const & ab ) const;
            constexpr Vector2D operator / ( float const & ab ) const;

            /* Arithmetic operation with other vector */
            constexpr Vector2D operator + ( Vector2D const & ab ) const;
            constexpr Vector2D operator - ( Vector2D const & ab ) const;
            constexpr Vector2D operator * ( Vector2D const & ab ) const;
            constexpr Vector2D operator / ( Vector2D const & ab ) const;

            /* Arithmetic operation and assignment with floating point number */
            constexpr Vector2D & operator += ( float const & ab );
            constexpr Vector2D & operator -= ( float const & ab );
            constexpr Vector2D & operator *= ( float const & ab );
            constexpr Vector2D & operator /= ( float const & ab );

            /* Arithmetic operation and assignment with other vector */
            constexpr Vector2D & operator += ( Vector2D const & ab );
            constexpr Vector2D & operator -= ( Vector2D const & ab );
            constexpr Vector2D & operator *= ( Vector2D const & ab );
            constexpr Vector2D & operator /= ( Vector2D const & ab );

            /* Get length of this vector */
            constexpr float length ( ) const;

            /* Normalize this vector */
            constexpr Vector2D & normalize ( );

            /* Get normalized temp vector */
            constexpr Vector2D normalized ( ) const;

            /* Friendly print function */
            friend std::ostream & operator << ( std::ostream & os, const Vector2D & p );

            float x, y;
        };

    } /* namespace src */

#endif /* _VECTOR_HPP_ */
