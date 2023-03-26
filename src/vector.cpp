
#include <cmath>
#include "vector.hpp"

namespace src {

    constexpr Vector2D::Vector2D ( ) : x( ), y( ) {

    }

    constexpr Vector2D::Vector2D ( float const & a ) : x(a), y(a) {

    }

    constexpr Vector2D::Vector2D ( float const & a, float const & b ) : x(a), y(b) {

    }

    constexpr Vector2D::Vector2D ( Vector2D const & ab ) : x(ab.x), y(ab.y) {

    }

    constexpr Vector2D::Vector2D ( Vector2D const & a, float const & b ) : x(a.x), y(b) {

    }

    constexpr Vector2D::Vector2D ( float const & a, Vector2D const & b ) : x(a), y(b.y) {

    }

    constexpr bool Vector2D::operator >  ( float const & ab ) const {
        return ((this)->x > ab) && ((this)->y > ab);
    }

    constexpr bool Vector2D::operator <  ( float const & ab ) const {
        return ((this)->x < ab) && ((this)->y < ab);
    }

    constexpr bool Vector2D::operator >= ( float const & ab ) const {
        return ((this)->x >= ab) && ((this)->y >= ab);
    }

    constexpr bool Vector2D::operator <= ( float const & ab ) const {
        return ((this)->x <= ab) && ((this)->y <= ab);
    }

    constexpr bool Vector2D::operator != ( float const & ab ) const {
        return ((this)->x != ab) && ((this)->y != ab);
    }

    constexpr bool Vector2D::operator == ( float const & ab ) const {
        return ((this)->x == ab) && ((this)->y == ab);
    }

    constexpr bool Vector2D::operator >  ( Vector2D const & ab ) const {
        return ((this)->x > ab.x) && ((this)->y > ab.y);
    }

    constexpr bool Vector2D::operator <  ( Vector2D const & ab ) const {
        return ((this)->x < ab.x) && ((this)->y < ab.y);
    }

    constexpr bool Vector2D::operator >= ( Vector2D const & ab ) const {
        return ((this)->x >= ab.x) && ((this)->y >= ab.y);
    }

    constexpr bool Vector2D::operator <= ( Vector2D const & ab ) const {
        return ((this)->x <= ab.x) && ((this)->y <= ab.y);
    }

    constexpr bool Vector2D::operator != ( Vector2D const & ab ) const {
        return ((this)->x != ab.x) && ((this)->y != ab.y);
    }

    constexpr bool Vector2D::operator == ( Vector2D const & ab ) const {
        return ((this)->x == ab.x) && ((this)->y == ab.y);
    }

    constexpr Vector2D Vector2D::operator + ( float const & ab ) const {
        return Vector2D((this)->x+ab,(this)->y+ab);
    }

    constexpr Vector2D Vector2D::operator - ( float const & ab ) const {
        return Vector2D((this)->x-ab,(this)->y-ab);
    }

    constexpr Vector2D Vector2D::operator * ( float const & ab ) const {
        return Vector2D((this)->x*ab,(this)->y*ab);
    }

    constexpr Vector2D Vector2D::operator / ( float const & ab ) const {
        return Vector2D((this)->x/ab,(this)->y/ab);
    }

    constexpr Vector2D Vector2D::operator + ( Vector2D const & ab ) const {
        return Vector2D((this)->x+ab.x,(this)->y+ab.y);
    }

    constexpr Vector2D Vector2D::operator - ( Vector2D const & ab ) const {
        return Vector2D((this)->x-ab.x,(this)->y-ab.y);
    }

    constexpr Vector2D Vector2D::operator * ( Vector2D const & ab ) const {
        return Vector2D((this)->x*ab.x,(this)->y*ab.y);
    }

    constexpr Vector2D Vector2D::operator / ( Vector2D const & ab ) const {
        return Vector2D((this)->x/ab.x,(this)->y/ab.y);
    }

    constexpr Vector2D & Vector2D::operator += ( float const & ab ) {
        (this)->x+=ab;
        (this)->y+=ab;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator -= ( float const & ab ) {
        (this)->x-=ab;
        (this)->y-=ab;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator *= ( float const & ab ) {
        (this)->x*=ab;
        (this)->y*=ab;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator /= ( float const & ab ) {
        (this)->x/=ab;
        (this)->y/=ab;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator += ( Vector2D const & ab ) {
        (this)->x+=ab.x;
        (this)->y+=ab.y;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator -= ( Vector2D const & ab ) {
        (this)->x-=ab.x;
        (this)->y-=ab.y;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator *= ( Vector2D const & ab ) {
        (this)->x*=ab.x;
        (this)->y*=ab.y;
        return (*this);
    }

    constexpr Vector2D & Vector2D::operator /= ( Vector2D const & ab ) {
        (this)->x/=ab.x;
        (this)->y/=ab.y;
        return (*this);
    }

    constexpr float Vector2D::length ( ) const {
        return sqrt((this)->x * (this)->x + (this)->y * (this)->y);
    }

    constexpr Vector2D & Vector2D::normalize ( ) {
        return (this)->operator/=((this)->length());
    }

    constexpr Vector2D Vector2D::normalized ( ) const {
        return (this)->operator/((this)->length());
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    std::ostream & operator << ( std::ostream &os, const Vector2D & p ) {
        return os << '[' << p.x << ',' << p.y << ']';
    }

} /* namespace src */
