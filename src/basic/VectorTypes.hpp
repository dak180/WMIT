/*
	Copyright 2010 Warzone 2100 Project

	This file is part of WMIT.

	WMIT is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	WMIT is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with WMIT.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef VERTEXTYPES_HPP
#define VERTEXTYPES_HPP
#include "Vector.hpp"

template <typename T, size_t COMPONENTS = 2>
struct UV : public Vector<T, COMPONENTS>
{
	UV() {u() = 0, v() =0;}

	UV(T u, T v) {
		u() = u; v() = v;
	}

	UV(const UV& rhs): Vector<T, COMPONENTS>(rhs) {}

	UV& operator = (const UV& rhs)
	{
		Vector<T, COMPONENTS>::operator=(rhs);
		return *this;
	}

	UV(const Vector<T, COMPONENTS>& rhs): Vector<T, COMPONENTS>(rhs) {}

	inline T& u() {
		return this->operator [](0);
	}
	inline T u() const {
		return this->operator [](0);
	}

	inline T& v() {
		return this->operator [](1);
	}
	inline T v() const {
		return this->operator [](1);
	}
};

template <typename T, size_t COMPONENTS = 3>
struct Vertex : public Vector<T, COMPONENTS>
{
	Vertex()
	{
		x() = 0;
		y() = 0;
		z() = 0;
	}

	Vertex(T x, T y, T z)
	{
		this->x() = x;
		this->y() = y;
		this->z() = z;
	}

	Vertex(const Vertex& rhs): Vector<T, COMPONENTS>(rhs) {}

	Vertex& operator = (const Vertex& rhs)
	{
		Vector<T, COMPONENTS>::operator=(rhs);
		return *this;
	}

	Vertex(const Vector<T, COMPONENTS>& rhs): Vector<T, COMPONENTS>(rhs) {}

	inline T& x() {
		return this->operator [](0);
	}
	inline T x() const {
		return this->operator [](0);
	}

	inline T& y() {
		return this->operator [](1);
	}
	inline T y() const {
		return this->operator [](1);
	}

	inline T& z() {
		return this->operator [](2);
	}
	inline T z() const {
		return this->operator [](2);
	}

	inline void scale(T xfac, T yfac, T zfac) {
		this->operator [](0) *= xfac;
		this->operator [](1) *= yfac;
		this->operator [](2) *= zfac;
	}

	Vertex crossProduct(const Vertex& rhs) const
	{
		return Vertex(y() * rhs.z() - z() * rhs.y(),
			      z() * rhs.x() - x() * rhs.z(),
			      x() * rhs.y() - y() * rhs.x());
	}

	T dotProduct(const Vertex& rhs) const
	{
		return x() * rhs.x() + y() * rhs.y() + z() * rhs.z();
	}
};

template <typename T, size_t COMPONENTS = 4>
struct Vertex4 : public Vector<T, COMPONENTS>
{
	Vertex4(const T val = 0)
	{
		x() = y() = z() = w() = val;
	}

	Vertex4(const T x, const T y, const T z, const T w)
	{
		x() = x;
		y() = y;
		z() = z;
		w() = w;
	}

	Vertex4(const Vertex4& rhs): Vector<T, COMPONENTS>(rhs) {}
	Vertex4(const Vertex<T>& rhs): Vector<T, COMPONENTS>()
	{
		x() = rhs.x();
		y() = rhs.y();
		z() = rhs.z();
		w() = 0;
	}

	Vertex4& operator = (const Vertex4& rhs)
	{
		Vector<T, COMPONENTS>::operator=(rhs);
		return *this;
	}

	inline T& x() {
		return this->operator [](0);
	}
	inline T x() const {
		return this->operator [](0);
	}

	inline T& y() {
		return this->operator [](1);
	}
	inline T y() const {
		return this->operator [](1);
	}

	inline T& z() {
		return this->operator [](2);
	}
	inline T z() const {
		return this->operator [](2);
	}

	T& w() {
		return this->operator [](3);
	}
	T w() const {
		return this->operator [](3);
	}

	Vertex<T> xyz() const
	{
		return Vertex<T>(x(), y(), z());
	}

	Vertex<T> swizzle(size_t x, size_t y, size_t z) const
	{
		return Vertex<T>(this->operator [](x), this->operator [](y), this->operator [](z));
	}

	Vertex4 swizzle(size_t x, size_t y, size_t z, size_t w) const
	{
		return Vertex4(this->operator [](x), this->operator [](y),
			       this->operator [](z), this->operator [](w));
	}
};

#endif // VERTEXTYPES_HPP
