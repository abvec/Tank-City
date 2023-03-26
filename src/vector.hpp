
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

            /* Get normalized this vector */
            constexpr Vector2D & normalize ( );

            /* Get normalized temp vector */
            constexpr Vector2D normalized ( ) const;

            /* Dot product */
            constexpr float dot ( Vector2D const & other ) const;

            /* Rotate this vector by rad radians */
            constexpr Vector2D rotate ( float const & rad ) const;

            /* Rotate this vector by rad radians around other vector */
            constexpr Vector2D rotate ( Vector2D const & other, float const & rad ) const;

            /* Rotate this vector by rad radians */
            constexpr Vector2D & rotated ( float const & rad );

            /* Rotate this vector by rad radians around other vector */
            constexpr Vector2D & rotated ( Vector2D const & other, float const & rad );

            /* Get absolute vector */
            constexpr Vector2D abs ( ) const;

            /* Calculate angle between vectors */
            constexpr float angle ( Vector2D const & other ) const;

            /* Project vector on to this vector */
            constexpr float project ( Vector2D const & other ) const;

            /* Friendly print function */
            friend std::ostream & operator << ( std::ostream & os, Vector2D const & p );

            float x, y;
        };

    } /* namespace src */

#endif /* _VECTOR_HPP_ */
