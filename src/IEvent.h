#ifndef E_MODULE_INTERFACE_EVENT
#define E_MODULE_INTERFACE_EVENT

#include "EventType.h"
#include "ISerializable.h"

#include <time.h>

namespace E_Module
{
	class IEvent
	{
	public:
		virtual clock_t getTimeStamp() const = 0;

		virtual EventType getType() const = 0;
	};
}

#endif