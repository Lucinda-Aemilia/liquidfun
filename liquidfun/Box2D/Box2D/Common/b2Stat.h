/*
* Copyright (c) 2013 Google, Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/
#ifndef B2_STAT
#define B2_STAT

#include <Box2D/Common/b2Settings.h>

///@file class of b2Stat

/// Calculates min/max/mean of a set of samples
///
/// The samples are of type float32.
class b2Stat
{
public:
	/// The constructor.
	/// \see Clear()
	b2Stat();

	/// Record a sample
	/// \param t The sample to be recorded
	void Record( float32 t );

	/// Returns the number of recorded samples
	/// \return the number of recorded samples
	int GetCount() const;

	/// Returns the mean of all recorded samples
	/// \return the mean of all recorded samples
	/// \retval 0 if there are no recorded samples
	float32 GetMean() const;

	/// Returns the min of all recorded samples
	/// \return the min of all recorded samples
	/// \retval FLT_MAX if there are no recorded samples
	float32 GetMin() const;

	/// Returns the max of all recorded samples
	/// \return the max of all recorded samples
	/// \retval -FLT_MAX if there are no recorded samples
	float32 GetMax() const;

	/// Erase all recorded samples
	///
	/// Set m_count and m_total to zero;\n
	/// Set m_min to FLT_MAX and m_max to FLT_MIN.
	void Clear();

private:

	/// The number of samples
	int m_count;

	/// The sum of samples
	float64 m_total;

	/// The minimum of samples
	float32 m_min;

	/// The maximum of samples
	float32 m_max;
};

#endif
