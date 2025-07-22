#pragma once

#include <string>

#include "SCSRPG_Entity.h"

using namespace std;

namespace SCSRPG
{
	namespace Player
	{
		class SCSRPG_Player final : public Entity::SCSRPG_Entity
		{
		public:
			SCSRPG_Player(void);
			~SCSRPG_Player(void);

			void Reset(void);

		private:
		};
	}
}
