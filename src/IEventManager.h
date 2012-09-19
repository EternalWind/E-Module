#ifndef E_MODULE_INTERFACE_EVENT_MANAGER
#define E_MODULE_INTERFACE_EVENT_MANAGER

#include "Singleton.h"
#include "EventType.h"

namespace E_Module
{
	class IEventManager : public Singleton
	{
	public:
		bool validateEventType(const EventType type) const;
	};
}

#endif