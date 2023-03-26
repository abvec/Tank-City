
#ifndef _PLANE_HPP_

    #define _PLANE_HPP_

    #include "vector.hpp"

    namespace src {

        class Plane2D {
            
            public :

            /* Constructors */
            Plane2D ( );
            Plane2D ( Plane2D const & abcd);
            Plane2D ( Vector2D const & aa, Vector2D const & cc );
            Plane2D ( Vector2D const & aa, Vector2D const & bb, Vector2D const & cc, Vector2D const & dd );

            /* Translate on x axis */
            Plane2D translatex ( float const & x ) const;
            Plane2D translatex ( Vector2D const & x ) const;

            /* Translate on y axis */
            Plane2D translatey ( float const & y ) const;
            Plane2D translatey ( Vector2D const & y ) const;

            /* Translate on x and y axis */
            Plane2D translate ( float const & x, float const & y ) const;
            Plane2D translate ( Vector2D const & xy ) const;

            /* Rotate around a, b, c or d corner */
            Plane2D rotatea ( float const & rad ) const;
            Plane2D rotateb ( float const & rad ) const;
            Plane2D rotatec ( float const & rad ) const;
            Plane2D rotated ( float const & rad ) const;

            /* Rotate around centre */
            Plane2D rotate ( float const & rad ) const;

            /* Rotate around given point */
            Plane2D rotate ( Vector2D const & xy, float const & rad ) const;

            /* Rotate around origin point */
            Plane2D rotateorigin ( float const & rad ) const;

            /* Scale from centre on x axis */
            Plane2D scalex ( float const & x ) const;
            Plane2D scalex ( Vector2D const & x ) const;

            /* Scale from left on x axis */
            Plane2D scaleadx ( float const & x ) const;
            Plane2D scaleadx ( Vector2D const & x ) const;

            /* Scale from right on x axis */
            Plane2D scalebcx ( float const & x ) const;
            Plane2D scalebcx ( Vector2D const & x ) const;

            /* Scale from centre on y axis */
            Plane2D scaley ( float const & y ) const;
            Plane2D scaley ( Vector2D const & y ) const;

            /* Scale from top on y axis */
            Plane2D scaleaby ( float const & y ) const;
            Plane2D scaleaby ( Vector2D const & y ) const;

            /* Scale from bottom on y axis */
            Plane2D scalecdy ( float const & y ) const;
            Plane2D scalecdy ( Vector2D const & y ) const;

            /* Scale from centre on x and y axis */
            Plane2D scale ( float const & xy ) const;
            Plane2D scale ( Vector2D const & xy ) const;

            /* Scale from corner a on x and y axis */
            Plane2D scalea ( float const & xy ) const;
            Plane2D scalea ( Vector2D const & xy ) const;

            /* Scale from corner b on x and y axis */
            Plane2D scaleb ( float const & xy ) const;
            Plane2D scaleb ( Vector2D const & xy ) const;

            /* Scale from corner c on x and y axis */
            Plane2D scalec ( float const & xy ) const;
            Plane2D scalec ( Vector2D const & xy ) const;

            /* Scale from corner x on x and y axis */
            Plane2D scaled ( float const & xy ) const;
            Plane2D scaled ( Vector2D const & xy ) const;
            
            /* Friendly print function */
            friend std::ostream & operator << ( std::ostream & os, Plane2D const & p );

            public :

            /*
                a - b
                |   |
                d - c
            */
            Vector2D  a, b, c, d;
        };

    }; /* namespace src */

#endif /* _PLANE_HPP_ */

