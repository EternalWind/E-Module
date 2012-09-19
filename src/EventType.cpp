#include "EventType.h"

namespace E_Module
{
	const string EventType::WILD_CARD_EVENT_TYPE_STRING = "wild_card_event";
	const uint32_t EventType::WILD_CARD_EVENT_TYPE_ID = 0;

	EventType::EventType(string str)
		: mOrigString(str),
		  mIdentifier(_calculateHashValue(str)) {}

	string EventType::getOrigString() const
	{
		return mOrigString;
	}

	uint32_t EventType::getIdentifier() const
	{
		return mIdentifier;
	}

	bool EventType::operator == (const EventType& other) const
	{
		return mIdentifier == other.mIdentifier;
	}

	bool EventType::operator < (const EventType& other) const
	{
		return mIdentifier < other.mIdentifier;
	}

	bool EventType::operator > (const EventType& other) const
	{
		return mIdentifier > other.mIdentifier;
	}

	uint32_t EventType::_calculateHashValue(string str) const
	{
		if (str == WILD_CARD_EVENT_TYPE_STRING)
		{
			return WILD_CARD_EVENT_TYPE_ID;
		}

		
	}
}