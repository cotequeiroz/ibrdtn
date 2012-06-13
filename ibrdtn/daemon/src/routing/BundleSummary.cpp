/*
 * BundleList.cpp
 *
 * Copyright (C) 2011 IBR, TU Braunschweig
 *
 * Written-by: Johannes Morgenroth <morgenroth@ibr.cs.tu-bs.de>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "routing/BundleSummary.h"

namespace dtn
{
	namespace routing
	{
		BundleSummary::BundleSummary()
		{
		}

		BundleSummary::~BundleSummary()
		{
		}

		void BundleSummary::add(const dtn::data::MetaBundle bundle)
		{
			_vector.add(bundle);
			dtn::data::BundleList::add(bundle);
		}

		void BundleSummary::remove(const dtn::data::MetaBundle bundle)
		{
			_vector.remove(bundle);
			dtn::data::BundleList::remove(bundle);
		}

		void BundleSummary::clear()
		{
			_vector.clear();
			dtn::data::BundleList::clear();
		}

		void BundleSummary::eventBundleExpired(const ExpiringBundle &bundle)
		{
			_vector.remove(bundle.bundle);
		}

		void BundleSummary::eventCommitExpired()
		{
			_vector.commit();
		}

		bool BundleSummary::contains(const dtn::data::BundleID &bundle) const
		{
			// quick check
			if (_vector.contains(bundle))
			{
				// do a deeper inspection
				return dtn::data::BundleList::contains(bundle);
			}

			return false;
		}

		const SummaryVector& BundleSummary::getSummaryVector() const
		{
			return _vector;
		}
	}
}
