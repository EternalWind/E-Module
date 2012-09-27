#ifndef E_MODULE_INTERFACE_EVENT
#define E_MODULE_INTERFACE_EVENT

#include "EventType.h"
#include "ISerializable.h"

#include <time.h>
#include <memory>

using namespace std;

namespace E_Module
{
	interface IEventManager;

	/**
	  * An interface for all the events. Events should not implement this interface directly. Instead, should inherit from BaseEvent.
	  * @see BaseEvent
	  */
	interface E_MODULE IEvent : implements ISerializable
	{
	public:
		/**
		  * Gets the time stamp when the event occurs.
		  * @returns The time stamp when the event occurs.
		  */
		virtual clock_t getTimeStamp() const = 0;

		/**
		  * Gets the type of the event.
		  * @returns The type of the event.
		  */
		virtual EventType getType() const = 0;

		virtual ~IEvent() = 0 {}
	};

	typedef shared_ptr<IEvent> EventSP;
}

#endif