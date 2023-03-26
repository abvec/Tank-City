
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

    constexpr float Vector2D::dot ( Vector2D const & a ) const {
        return (this)->x * a.x + (this)->y * a.y;
    }

    constexpr Vector2D Vector2D::rotate ( float const & rad ) const {
        float const cs = std::cos(rad);
        float const sn = std::sin(rad);
        return Vector2D((this)->x*cs-(this)->y*sn,(this)->x*sn+(this)->y*cs);
    }

    constexpr Vector2D Vector2D::rotate ( Vector2D const & other, float const & rad ) const {
        float const cs = std::cos(rad);
        float const sn = std::sin(rad);
        Vector2D const dec = (*this) - other;
        return Vector2D(dec.x*cs-dec.y*sn,dec.x*sn+dec.y*cs) + other;
    }

    constexpr Vector2D & Vector2D::rotated ( float const & rad ) {
        float const cs = std::cos(rad);
        float const sn = std::sin(rad);
        return (*this)=Vector2D((this)->x*cs-(this)->y*sn,(this)->x*sn+(this)->y*cs);
    }

    constexpr Vector2D & Vector2D::rotated ( Vector2D const & other, float const & rad ) {
        return ((*this) -= other).rotated(rad)+=other;
    }
    
    constexpr Vector2D Vector2D::abs ( ) const {
        return Vector2D(std::abs((this)->x),std::abs((this)->y));
    }

    constexpr float Vector2D::angle ( Vector2D const & other ) const {
        return acos((this)->dot(other));
    }

    constexpr float Vector2D::project ( Vector2D const & other ) const {
        return (this)->dot(other)/((this)->length() * 2);
    }
    
    std::ostream & operator << ( std::ostream &os, Vector2D const & p ) {
        return os << '[' << p.x << ',' << p.y << ']';
    }

} /* namespace src */
