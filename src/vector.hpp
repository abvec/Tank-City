
#ifndef _VECTOR_HPP_

    #define _VECTOR_HPP_

    #include <ostream>

    namespace src {

        /* A two dimentional vector. */
        class Vector2D {

            public :

            /* Constructors */
            Vector2D ( );
            Vector2D ( float const & a );
            Vector2D ( float const & a, float const & b );
            Vector2D ( Vector2D const & ab );
            Vector2D ( Vector2D const & a, float const & b );
            Vector2D ( float const & a, Vector2D const & b );

            /* Compare with floating point number */
            bool operator >  ( float const & ab ) const;
            bool operator <  ( float const & ab ) const;
            bool operator >= ( float const & ab ) const;
            bool operator <= ( float const & ab ) const;
            bool operator != ( float const & ab ) const;
            bool operator == ( float const & ab ) const;

            /* Compare with other vector */
            bool operator >  ( Vector2D const & ab ) const;
            bool operator <  ( Vector2D const & ab ) const;
            bool operator >= ( Vector2D const & ab ) const;
            bool operator <= ( Vector2D const & ab ) const;
            bool operator != ( Vector2D const & ab ) const;
            bool operator == ( Vector2D const & ab ) const;

            /* Arithmetic operation with floating point number */
            Vector2D operator + ( float const & ab ) const;
            Vector2D operator - ( float const & ab ) const;
            Vector2D operator * ( float const & ab ) const;
            Vector2D operator / ( float const & ab ) const;

            /* Arithmetic operation with other vector */
            Vector2D operator + ( Vector2D const & ab ) const;
            Vector2D operator - ( Vector2D const & ab ) const;
            Vector2D operator * ( Vector2D const & ab ) const;
            Vector2D operator / ( Vector2D const & ab ) const;

            /* Arithmetic operation and assignment with floating point number */
            Vector2D & operator += ( float const & ab );
            Vector2D & operator -= ( float const & ab );
            Vector2D & operator *= ( float const & ab );
            Vector2D & operator /= ( float const & ab );

            /* Arithmetic operation and assignment with other vector */
            Vector2D & operator += ( Vector2D const & ab );
            Vector2D & operator -= ( Vector2D const & ab );
            Vector2D & operator *= ( Vector2D const & ab );
            Vector2D & operator /= ( Vector2D const & ab );

            /* Get length of this vector */
            float length ( ) const;

            /* Get normalized this vector */
            Vector2D & normalize ( );

            /* Get normalized temp vector */
            Vector2D normalized ( ) const;

            /* Dot product */
            float dot ( Vector2D const & other ) const;

            /* Rotate this vector by rad radians */
            Vector2D rotate ( float const & rad ) const;

            /* Rotate this vector by rad radians around other vector */
            Vector2D rotate ( Vector2D const & other, float const & rad ) const;

            /* Rotate this vector by rad radians */
            Vector2D & rotated ( float const & rad );

            /* Rotate this vector by rad radians around other vector */
            Vector2D & rotated ( Vector2D const & other, float const & rad );

            /* Get absolute vector */
            Vector2D abs ( ) const;

            /* Calculate angle between vectors */
            float angle ( Vector2D const & other ) const;

            /* Project vector on to this vector */
            float project ( Vector2D const & other ) const;

            /* Friendly print function */
            friend std::ostream & operator << ( std::ostream & os, Vector2D const & p );

            float x, y;
        };

    } /* namespace src */

#endif /* _VECTOR_HPP_ */
