#ifndef E_MODULE_EVENT_TYPE
#define E_MODULE_EVENT_TYPE

#include "Definitions.h"
#include "ISerializable.h"

#include <string>
#include <cstdint>

using namespace std;

namespace E_Module
{
	/**
	  * A class used to distinguish different kinds of events.
	  */
	class E_MODULE EventType : implements ISerializable
	{
	public:
		/**
		  * The constructor.
		  * @param str The type name of an event which is used to generate an unique identifier.
		  */
		EventType(string str);

		/**
		  * Gets the original string that is used to generate the identifier.
		  * @returns The original string.
		  */
		string getOrigString() const;

		/**
		  * Gets the identifier for this type of events.
		  * @returns The identifier.
		  */
		uint32_t getIdentifier() const;

		/**
		  * Gets whether this event type equals to a given event type or not.
		  * @param other The other event type to compare.
		  * @returns Whether this event type equals to the given event type or not.
		  */
		bool operator == (const EventType& other) const;

		/**
		  * Gets whether this event type doesn't equal to a given event type or does.
		  * @param other The other event type to compare.
		  * @returns Whether this event type doesn't equal to a given event type or does.
		  */
		bool operator != (const EventType& other) const;

		/**
		  * Gets whether this event type is larger than a given event type or not.
		  * @param other The other event type to compare.
		  * @returns Whether this event type is larger than the given event type or not.
		  */
		bool operator > (const EventType& other) const;

		/**
		  * Gets whether this event type is smaller than a given event type or not.
		  * @param other The other event type to compare.
		  * @returns Whether this event type is smaller than the given event type or not.
		  */
		bool operator < (const EventType& other) const;

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

		static const string WILD_CARD_EVENT_TYPE_STRING;              //!< The type name of the wild card event.
		static const uint32_t WILD_CARD_EVENT_TYPE_ID;                //!< The identifier of the wild card event.

	private:
		/**
		  * Calculate the unique identifier for a given type name.
		  * @param str The given type name to calculate.
		  * @returns The calculated identifier.
		  */
		uint32_t _calculateHashValue(string str) const;

		string mOrigString;                                           //!< The original string.
		uint32_t mIdentifier;                                         //!< The unique identifier.
	};
}

#endif