//
// Copyright (c) 2009, Markus Rickert
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice,
//   this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#ifndef RL_MDL_NLOPTINVERSEKINEMATICS_H
#define RL_MDL_NLOPTINVERSEKINEMATICS_H

#include <chrono>
#include <nlopt.h>
#include <random>
#include <utility>

#include "InverseKinematics.h"

namespace rl
{
	namespace mdl
	{
		class NloptInverseKinematics : public InverseKinematics
		{
		public:
			NloptInverseKinematics(Kinematic* kinematic);
			
			virtual ~NloptInverseKinematics();
			
			bool solve();
			
			::rl::math::Real delta;
			
			::std::chrono::nanoseconds duration;
			
			::rl::math::Real epsilonRotation;
			
			::rl::math::Real epsilonTranslation;
			
			double tolerance;
			
		protected:
			
		private:
			::rl::math::Real error(const ::rl::math::Vector& q);
			
			static ::rl::math::Real f(unsigned n, const double* x, double* grad, void* data);
			
			::std::uniform_real_distribution< ::rl::math::Real> randDistribution;
			
			::std::mt19937 randEngine;
		};
	}
}

#endif // RL_MDL_NLOPTINVERSEKINEMATICS_H
