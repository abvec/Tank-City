
#include "plane.hpp"

namespace src {

    /* Constructors */
    Plane2D::Plane2D ( ) { }

    Plane2D::Plane2D ( Plane2D const & abcd) : a(abcd.a), b(abcd.b), c(abcd.c), d(abcd.d) { }

    Plane2D::Plane2D ( Vector2D const & aa, Vector2D const & cc ) :
                                a(aa), b(cc.x,aa.y), c(cc), d(aa.x,cc.y) { }

    Plane2D::Plane2D ( Vector2D const & aa, Vector2D const & bb, Vector2D const & cc, Vector2D const & dd ) :
                                a(aa), b(bb), c(cc), d(dd) { }

    Plane2D Plane2D::translatex ( float const & x ) const {
        Vector2D tr = Vector2D(x,0);
        return Plane2D(a+tr,b+tr,c+tr,d+tr);
    }

    Plane2D Plane2D::translatex ( Vector2D const & x ) const {
        return (this)->translatex(x.x);
    }

    Plane2D Plane2D::translatey ( float const & y ) const {
        Vector2D tr = Vector2D(0,y);
        return Plane2D(a+tr,b+tr,c+tr,d+tr);
    }

    Plane2D Plane2D::translatey ( Vector2D const & y ) const{
        return (this)->translatey(y.y);
    }

    Plane2D Plane2D::translate ( float const & x, float const & y ) const {
        Vector2D tr = Vector2D(x,y);
        return Plane2D(a+tr,b+tr,c+tr,d+tr);
    }

    Plane2D Plane2D::translate ( Vector2D const & xy ) const {
        return Plane2D(a+xy,b+xy,c+xy,d+xy);
    }

    Plane2D Plane2D::rotatea ( float const & rad ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = (this)->b.rotate((this)->a,rad);
        temp.c = (this)->c.rotate((this)->a,rad);
        temp.d = (this)->d.rotate((this)->a,rad);
        return temp;
    }

    Plane2D Plane2D::rotateb ( float const & rad ) const {
        Plane2D temp;
        temp.a = (this)->a.rotate((this)->b,rad);
        temp.b = (this)->b;
        temp.c = (this)->c.rotate((this)->b,rad);
        temp.d = (this)->d.rotate((this)->b,rad);
        return temp;
    }

    Plane2D Plane2D::rotatec ( float const & rad ) const {
        Plane2D temp;
        temp.a = (this)->a.rotate((this)->c,rad);
        temp.b = (this)->b.rotate((this)->c,rad);
        temp.c = (this)->c;
        temp.d = (this)->d.rotate((this)->c,rad);
        return temp;
    }

    Plane2D Plane2D::rotated ( float const & rad ) const {
        Plane2D temp;
        temp.a = (this)->a.rotate((this)->d,rad);
        temp.b = (this)->b.rotate((this)->d,rad);
        temp.c = (this)->c.rotate((this)->d,rad);
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::rotate ( float const & rad ) const {
        Vector2D centre = (this)->a + ((this)->c - (this)->a) / 2;
        Plane2D temp;
        temp.a = (this)->a.rotate(centre,rad);
        temp.b = (this)->b.rotate(centre,rad);
        temp.c = (this)->c.rotate(centre,rad);
        temp.d = (this)->d.rotate(centre,rad);
        return temp;
    }

    Plane2D Plane2D::rotate ( Vector2D const & xy, float const & rad ) const {
        Plane2D temp;
        temp.a = (this)->a.rotate(xy,rad);
        temp.b = (this)->b.rotate(xy,rad);
        temp.c = (this)->c.rotate(xy,rad);
        temp.d = (this)->d.rotate(xy,rad);
        return temp;
    }

    Plane2D Plane2D::rotateorigin ( float const & rad ) const {
        Plane2D temp;
        temp.a = (this)->a.rotate(rad);
        temp.b = (this)->b.rotate(rad);
        temp.c = (this)->c.rotate(rad);
        temp.d = (this)->d.rotate(rad);
        return temp;
    }

    Plane2D Plane2D::scalex ( float const & x ) const {
        float sc = x / 2;
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-sc,(this)->a.y);
        temp.b = Vector2D((this)->b.x+sc,(this)->b.y);
        temp.c = Vector2D((this)->c.x+sc,(this)->c.y);
        temp.d = Vector2D((this)->d.x-sc,(this)->d.y);
        return temp;
    }

    Plane2D Plane2D::scalex ( Vector2D const & x ) const {
        float sc = x.x / 2;
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-sc,(this)->a.y);
        temp.b = Vector2D((this)->b.x+sc,(this)->b.y);
        temp.c = Vector2D((this)->c.x+sc,(this)->c.y);
        temp.d = Vector2D((this)->d.x-sc,(this)->d.y);
        return temp;
    }

    Plane2D Plane2D::scaleadx ( float const & x ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x+x,(this)->a.y);
        temp.b = (this)->b;
        temp.c = (this)->c;
        temp.d = Vector2D((this)->d.x+x,(this)->d.y);
        return temp;
    }

    Plane2D Plane2D::scaleadx ( Vector2D const & x ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x+x.x,(this)->a.y);
        temp.b = (this)->b;
        temp.c = (this)->c;
        temp.d = Vector2D((this)->d.x+x.x,(this)->d.y);
        return temp;
    }

    Plane2D Plane2D::scalebcx ( float const & x ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = Vector2D((this)->b.x+x,(this)->b.y);
        temp.c = Vector2D((this)->c.x+x,(this)->c.y);
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::scalebcx ( Vector2D const & x ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = Vector2D((this)->b.x+x.x,(this)->b.y);
        temp.c = Vector2D((this)->c.x+x.x,(this)->c.y);
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::scaley ( float const & y ) const {
        float sc = y / 2;
        Plane2D temp;
        temp.a = Vector2D((this)->a.x,(this)->a.y-sc);
        temp.b = Vector2D((this)->b.x,(this)->b.y-sc);
        temp.c = Vector2D((this)->c.x,(this)->c.y+sc);
        temp.d = Vector2D((this)->d.x,(this)->d.y+sc);
        return temp;
    }

    Plane2D Plane2D::scaley ( Vector2D const & y ) const {
        float sc = y.y / 2;
        Plane2D temp;
        temp.a = Vector2D((this)->a.x,(this)->a.y-sc);
        temp.b = Vector2D((this)->b.x,(this)->b.y-sc);
        temp.c = Vector2D((this)->c.x,(this)->c.y+sc);
        temp.d = Vector2D((this)->d.x,(this)->d.y+sc);
        return temp;
    }

    Plane2D Plane2D::scaleaby ( float const & y ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x,(this)->a.y-y);
        temp.b = Vector2D((this)->b.x,(this)->b.y-y);
        temp.c = (this)->c;
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::scaleaby ( Vector2D const & y ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x,(this)->a.y-y.y);
        temp.b = Vector2D((this)->b.x,(this)->b.y-y.y);
        temp.c = (this)->c;
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::scalecdy ( float const & y ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = (this)->b;
        temp.c = Vector2D((this)->c.x,(this)->c.y+y);
        temp.d = Vector2D((this)->d.x,(this)->d.y+y);
        return temp;
    }

    Plane2D Plane2D::scalecdy ( Vector2D const & y ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = (this)->b;
        temp.c = Vector2D((this)->c.x,(this)->c.y+y.y);
        temp.d = Vector2D((this)->d.x,(this)->d.y+y.y);
        return temp;
    }

    Plane2D Plane2D::scale ( float const & xy ) const {
        float sc = xy / 2;
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-sc,(this)->a.y-sc);
        temp.b = Vector2D((this)->b.x+sc,(this)->b.y-sc);
        temp.c = Vector2D((this)->c.x+sc,(this)->c.y+sc);
        temp.d = Vector2D((this)->d.x-sc,(this)->d.y+sc);
        return temp;
    }

    Plane2D Plane2D::scale ( Vector2D const & xy ) const {
        Vector2D sc = xy / 2;
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-sc.x,(this)->a.y-sc.y);
        temp.b = Vector2D((this)->b.x+sc.x,(this)->b.y-sc.y);
        temp.c = Vector2D((this)->c.x+sc.x,(this)->c.y+sc.y);
        temp.d = Vector2D((this)->d.x-sc.x,(this)->d.y+sc.y);
        return temp;
    }

    Plane2D Plane2D::scalea ( float const & xy ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-xy,(this)->a.y-xy);
        temp.b = Vector2D((this)->b.x,(this)->b.y+xy);
        temp.c = (this)->c;
        temp.d = Vector2D((this)->d.x-xy,(this)->d.y);
        return temp;
    }

    Plane2D Plane2D::scalea ( Vector2D const & xy ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-xy.x,(this)->a.y+xy.y);
        temp.b = Vector2D((this)->b.x,(this)->b.y+xy.y);
        temp.c = (this)->c;
        temp.d = Vector2D((this)->d.x-xy.x,(this)->d.y);
        return temp;
    }

    Plane2D Plane2D::scaleb ( float const & xy ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x,(this)->a.y+xy);
        temp.b = Vector2D((this)->b.x+xy,(this)->b.y+xy);
        temp.c = Vector2D((this)->c.x+xy,(this)->c.y);
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::scaleb ( Vector2D const & xy ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x,(this)->a.y-xy.y);
        temp.b = Vector2D((this)->b.x+xy.x,(this)->b.y+xy.y);
        temp.c = Vector2D((this)->c.x+xy.x,(this)->c.y);
        temp.d = (this)->d;
        return temp;
    }

    Plane2D Plane2D::scalec ( float const & xy ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = Vector2D((this)->b.x+xy,(this)->b.y);
        temp.c = Vector2D((this)->c.x+xy,(this)->c.y-xy);
        temp.d = Vector2D((this)->d.x,(this)->d.y-xy);
        return temp;
    }

    Plane2D Plane2D::scalec ( Vector2D const & xy ) const {
        Plane2D temp;
        temp.a = (this)->a;
        temp.b = Vector2D((this)->b.x+xy.x,(this)->b.y);
        temp.c = Vector2D((this)->c.x+xy.x,(this)->c.y-xy.y);
        temp.d = Vector2D((this)->d.x,(this)->d.y-xy.y);
        return temp;
    }

    Plane2D Plane2D::scaled ( float const & xy ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-xy,(this)->a.y);
        temp.b = (this)->b;
        temp.c = Vector2D((this)->c.x,(this)->c.y-xy);
        temp.d = Vector2D((this)->d.x-xy,(this)->d.y-xy);
        return temp;
    }

    Plane2D Plane2D::scaled ( Vector2D const & xy ) const {
        Plane2D temp;
        temp.a = Vector2D((this)->a.x-xy.x,(this)->a.y);
        temp.b = (this)->b;
        temp.c = Vector2D((this)->c.x,(this)->c.y-xy.y);
        temp.d = Vector2D((this)->d.x-xy.x,(this)->d.y-xy.y);
        return temp;
    }

    std::ostream & operator << ( std::ostream & os, Plane2D const & p ) {
        return os << p.a << p.b << std::endl << p.d << p.c;
    }

}; /* namespace src */
