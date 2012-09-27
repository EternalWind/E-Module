#ifndef E_MODULE_BASE_EVENT
#define E_MODULE_BASE_EVENT

#include "Definitions.h"
#include "IEvent.h"

namespace E_Module
{
	/**
	  * A base calss for all the events.
	  */
	class E_MODULE BaseEvent : implements IEvent
	{
	public:
		/**
		  * The constructor.
		  * @param time_stamp The time stamp wwhen the event occurs.
		  */
		BaseEvent(const clock_t time_stamp = 0);

		/**
		  * @see ISerializable
		  */
		void serialize(OUT IStream& stream) const;

		/**
		  * @see ISerializable
		  */
		void deserialize(IN IStream& stream);

		/**
		  * @see ISerializable
		  */
		string toString() const;

		clock_t getTimeStamp() const;

		virtual void onSerialize(OUT IStream& stream) const = 0;

		virtual void onDeserialize(IN IStream& stream) = 0;

		virtual string onToString() const = 0;

		virtual ~BaseEvent() = 0;

	protected:
		clock_t mTimeStamp;
	};
}

#endif